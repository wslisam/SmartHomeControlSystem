#include "SmartDevice.h"

SmartDevice::SmartDevice(const std::string& deviceName, double power)
    : name(deviceName), isOn(false), powerConsumption(power) {}

void SmartDevice::turnOn() {
    isOn = true;
}

void SmartDevice::turnOff() {
    isOn = false;
}

std::string SmartDevice::getStatus() const {
    return name + " is " + (isOn ? "ON" : "OFF");
}

double SmartDevice::getPowerConsumption() const {
    return isOn ? powerConsumption : 0.0;
}