// SmartLock.cpp
#include "SmartLock.h"

SmartLock::SmartLock(const std::string& name, double power)
    : SmartDevice(name, power), isLocked(true) {}

void SmartLock::lock() {
    isLocked = true;
    turnOn();
}

void SmartLock::unlock() {
    isLocked = false;
    turnOn();
}

bool SmartLock::getLockedStatus() const {
    return isLocked;
}

std::string SmartLock::getStatus() const {
    return SmartDevice::getStatus() + " (" + (isLocked ? "Locked" : "Unlocked") + ")";
}