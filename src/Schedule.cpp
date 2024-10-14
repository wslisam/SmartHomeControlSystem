// Schedule.cpp
#include "Schedule.h"
#include <iomanip>
#include <sstream>

Schedule::Schedule(const std::chrono::system_clock::time_point& time, 
                   std::function<void()> action, 
                   bool recurring, 
                   std::chrono::hours recur_interval)
    : scheduledTime(time), action(action), isRecurring(recurring), recurInterval(recur_interval) {}

bool Schedule::isTimeToExecute() const {
    return std::chrono::system_clock::now() >= scheduledTime;
}

void Schedule::execute() {
    action();
    if (isRecurring) {
        updateNextExecution();
    }
}

void Schedule::updateNextExecution() {
    scheduledTime += recurInterval;
}

std::string Schedule::getNextExecutionTime() const {
    auto timeT = std::chrono::system_clock::to_time_t(scheduledTime);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}