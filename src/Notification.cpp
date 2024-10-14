// Notification.cpp
#include "Notification.h"
#include <iomanip>
#include <sstream>

Notification::Notification(const std::string& msg)
    : message(msg), timestamp(std::chrono::system_clock::now()), isRead(false) {}

std::string Notification::getMessage() const {
    return message;
}

std::string Notification::getTimestamp() const {
    auto timeT = std::chrono::system_clock::to_time_t(timestamp);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

bool Notification::getIsRead() const {
    return isRead;
}

void Notification::markAsRead() {
    isRead = true;
}