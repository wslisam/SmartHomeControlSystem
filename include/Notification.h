// Notification.h
#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>
#include <chrono>

class Notification {
private:
    std::string message;
    std::chrono::system_clock::time_point timestamp;
    bool isRead;

public:
    Notification(const std::string& msg);
    std::string getMessage() const;
    std::string getTimestamp() const;
    bool getIsRead() const;
    void markAsRead();
};

#endif // NOTIFICATION_H