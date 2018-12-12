#pragma once

#include <microhttpd.h>
#include <sstream>

namespace d2ai {

class Controller;

/*
 * This class provides an embedded HTTP Server based on libmicrohttpd
 */
class HttpServer {
private:

    Controller *controller;

    int threads;
    struct MHD_Daemon *daemon;

    static int callback(void *cls, MHD_Connection *connection, const char *url,
            const char *method, const char *version, const char *upload_data,
            size_t *upload_data_size, void **con_cls);

    static void send(const std::string &response, MHD_Connection *connection);

public:

    explicit HttpServer(Controller *controller, int threads = 50);

    void start(); // returns if failed, blocks otherwise
};

struct mhd_coninfo {
    MHD_Connection *connection;
    std::stringstream request;
    HttpServer *server;
};

} /* namespace d2ai */
