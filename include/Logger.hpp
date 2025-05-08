#pragma once

#include <string>

class Logger {
private:
    Logger();

public:
    static Logger& getInstance();

    void logOperations(std::string line) const;

    static void info(std::string line);
    static void warning(std::string line);
    static void error(std::string line);

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};