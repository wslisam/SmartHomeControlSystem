#ifndef SMARTHOME_H
#define SMARTHOME_H

#include <vector>
#include <memory>
#include "SmartDevice.h"

class SmartHome {
private:
    std::vector<std::unique_ptr<SmartDevice>> devices;

public:
    void addDevice(std::unique_ptr<SmartDevice> device);
    void controlDevice(int index, bool turnOn);
    void displayStatus() const;
    double getTotalPowerConsumption() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void setLightBrightness(int index, int brightness);
    void setThermostatTemperature(int index, double temperature);
};

#endif // SMARTHOME_H