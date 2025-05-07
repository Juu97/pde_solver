#include <string>
#include <iostream>

class Logger {
private:
    Logger() = default;

public:
    static Logger& getInstance() {
        static Logger logger;
        return logger;
    }

    void logOperations(std::string line) const{
        std::cout << line << std::endl;
    }

    static void log(std::string line){
        Logger::getInstance().logOperations(line);
    }

    Logger(const Logger& other) = delete;
    Logger& operator=(const Logger& other) = delete;
};