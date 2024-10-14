// SmartLock.h
#ifndef SMARTLOCK_H
#define SMARTLOCK_H

#include "SmartDevice.h"

class SmartLock : public SmartDevice {
private:
    bool isLocked;

public:
    SmartLock(const std::string& name, double power);
    void lock();
    void unlock();
    bool getLockedStatus() const;
    std::string getStatus() const override;
};

#endif // SMARTLOCK_H