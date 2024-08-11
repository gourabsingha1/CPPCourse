#include <iostream>
#include "logger.hpp"
#include <thread>
using namespace std;

void user1Logs() {
    Logger* logger1 = Logger::getLogger();
    logger1->Log("This msg is from user 1");
}

void user2Logs() {
    Logger* logger2 = Logger::getLogger();
    logger2->Log("This msg is from user 2");
}

int main() {
    // Lets say thread t1 comes first and starts making loggerInstance. Not t2 comes after some time, instance isn't created yet, and T2 also starts creating it
    thread t1(user1Logs);
    thread t2(user2Logs);
    t1.join();
    t2.join();

    return 0;
}