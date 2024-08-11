#include <iostream>
#include "logger.hpp"
using namespace std;

int Logger::ctr = 0;
Logger* Logger::loggerInstance = NULL;
mutex Logger::mtx;

Logger::Logger() {
    ctr++;
    cout<<"New instance created. No of instance: "<<ctr<<endl;
}

void Logger::Log(string msg) {
    cout<<msg<<endl;
}

Logger* Logger::getLogger() {
    // Double-checked locking: Putting lock only once at the time of first instance creation
    if(loggerInstance == NULL) {
        // To make it thread safe OR keep No of instances = 1
        mtx.lock();
        if(loggerInstance == NULL) { // To make sure that there is only one loggerInstance
            loggerInstance = new Logger();
        }
        mtx.unlock();
    }
    return loggerInstance;
}