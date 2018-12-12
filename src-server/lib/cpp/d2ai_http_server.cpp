#include <chrono>
#include <thread>
#include <string>
#include "d2ai_http_server.h"
#include "d2ai_controller.h"
#include "d2ai_util.h"

namespace d2ai {

HttpServer::HttpServer(Controller *controller, int threads)
    : controller(controller), threads(threads), daemon(NULL) {
}

void HttpServer::start() {
    daemon = MHD_start_daemon(
            MHD_USE_INTERNAL_POLLING_THREAD,      // flags
            controller->getPort(),                // port
            NULL, NULL,                           // accept policy callback + arg
            &HttpServer::callback, this,          // handler callback + cls ptr
            MHD_OPTION_THREAD_POOL_SIZE, threads, // number of threads
            MHD_OPTION_END);
    if (daemon != NULL) {
        Util::print("HTTP server listening on port "
                + std::to_string(controller->getPort()));
        std::this_thread::sleep_for(std::chrono::hours(9766)); // 1 year
    }
    MHD_stop_daemon(daemon);
}

int HttpServer::callback(void *cls, MHD_Connection *connection, const char *url,
        const char *method, const char *version, const char *upload_data,
        size_t *upload_data_size, void **con_cls) {
    if (*con_cls == NULL) {
        struct mhd_coninfo *coninfo = new mhd_coninfo;
        coninfo->connection = connection;
        coninfo->server = static_cast<HttpServer *>(cls);
        *con_cls = coninfo;
        return MHD_YES;
    }
    struct mhd_coninfo *coninfo = static_cast<struct mhd_coninfo *>(*con_cls);
    if (*upload_data_size != 0) {
        coninfo->request.write(upload_data, *upload_data_size);
        *upload_data_size = 0;
        return MHD_YES;
    } else {
        std::string response;
        coninfo->server->controller->process(coninfo->request.str(), response);
        HttpServer::send(response, coninfo->connection);
    }
    delete coninfo;
    *con_cls = NULL;
    return MHD_YES;
}

void HttpServer::send(const std::string &response, MHD_Connection *connection) {
    struct MHD_Response *mhdr = MHD_create_response_from_buffer(
            response.size(), (void*)response.c_str(), MHD_RESPMEM_MUST_COPY);
    MHD_queue_response(connection, MHD_HTTP_OK, mhdr);
    MHD_destroy_response(mhdr);
}

} /* namespace d2ai */
