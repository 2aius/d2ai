#include <iostream>
#include <iomanip>
#include <chrono>
#include "d2ai_util.h"

namespace d2ai {

std::mutex Util::PRINT_MUTEX{};

std::vector<std::string> Util::split(const std::string& str, char delim) {
    std::vector<std::string> sv;
    auto pos = str.find(delim);
    if (pos == std::string::npos) {
        sv.push_back(str);
    } else {
        auto i = 0;
        while (pos != std::string::npos) {
            sv.push_back(str.substr(i, pos-i));
            i = ++pos;
            pos = str.find(delim, pos);
            if (pos == std::string::npos) {
                sv.push_back(str.substr(i, str.length()));
            }
        }
    }
    return sv;
}

void Util::print(const std::string& str) {
    auto now = std::chrono::system_clock::now();
    auto t = std::chrono::system_clock::to_time_t(now);
    std::lock_guard<std::mutex> lock(Util::PRINT_MUTEX);
    std::cout << std::put_time(std::localtime(&t), "%D - %T")
        << " [d2ai] " << str << std::endl;
}

} /* namespace d2ai */
