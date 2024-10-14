// SmartThermostat.cpp
#include "SmartThermostat.h"

SmartThermostat::SmartThermostat(const std::string& name, double power)
    : SmartDevice(name, power), temperature(20.0) {}

void SmartThermostat::setTemperature(double temp) {
    temperature = temp;
    turnOn();
}

double SmartThermostat::getTemperature() const {
    return temperature;
}

std::string SmartThermostat::getStatus() const {
    return SmartDevice::getStatus() + " (Temperature: " + 
           std::to_string(temperature) + "°C)";
}