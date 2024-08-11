#ifndef logger_h
#define logger_h

#include <string>
#include <mutex>
using namespace std;

class Logger {
    static int ctr; // Counter to track the number of created instances
    static Logger* loggerInstance;
    static mutex mtx;
    Logger();

public:
    static Logger* getLogger();
    void Log(string msg);
};

#endif