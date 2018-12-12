#pragma once

#include <string>
#include <vector>
#include <mutex>

namespace d2ai {

class Util final {
private:

    static std::mutex PRINT_MUTEX;

public:

    static std::vector<std::string> split(const std::string& str, char delim);

    static void print(const std::string& str);
};

} /* namespace d2ai */
