#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

class SmartDevice {
protected:
    std::string name;
    bool isOn;
    double powerConsumption;

public:
    SmartDevice(const std::string& deviceName, double power);
    virtual ~SmartDevice() = default;

    virtual void turnOn();
    virtual void turnOff();
    virtual std::string getStatus() const;
    virtual double getPowerConsumption() const;
};

#endif // SMARTDEVICE_H