#include "Logger.hpp"
#include <iostream>

Logger::Logger() = default;

Logger& Logger::getInstance() {
    static Logger logger;
    return logger;
}

void Logger::logOperations(std::string line) const {
    std::cout << line << std::endl;
}

void Logger::info(std::string line) {
    Logger::getInstance().logOperations("[INFO] " + line);
}

void Logger::warning(std::string line) {
    Logger::getInstance().logOperations("[WARNING] " + line);
}

void Logger::error(std::string line) {
    Logger::getInstance().logOperations("[ERROR] " + line);
}
