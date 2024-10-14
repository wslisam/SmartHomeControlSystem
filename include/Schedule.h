// Schedule.h
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <chrono>
#include <functional>

class Schedule {
private:
    std::chrono::system_clock::time_point scheduledTime;
    std::function<void()> action;
    bool isRecurring;
    std::chrono::hours recurInterval;

public:
    Schedule(const std::chrono::system_clock::time_point& time, 
             std::function<void()> action, 
             bool recurring = false, 
             std::chrono::hours recur_interval = std::chrono::hours(24));

    bool isTimeToExecute() const;
    void execute();
    void updateNextExecution();
    std::string getNextExecutionTime() const;
};

#endif // SCHEDULE_H