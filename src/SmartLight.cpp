// SmartLight.cpp
#include "SmartLight.h"

SmartLight::SmartLight(const std::string& name, double power)
    : SmartDevice(name, power), brightness(0) {}

void SmartLight::setBrightness(int level) {
    brightness = std::max(0, std::min(100, level));
    if (brightness > 0) {
        turnOn();
    } else {
        turnOff();
    }
}

int SmartLight::getBrightness() const {
    return brightness;
}

std::string SmartLight::getStatus() const {
    return SmartDevice::getStatus() + " (Brightness: " + std::to_string(brightness) + "%)";
}