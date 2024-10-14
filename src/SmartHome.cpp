#include "SmartHome.h"
#include <fstream>
#include <iostream>

void SmartHome::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& device : devices) {
            file << device->getName() << "," 
                 << (device->isDeviceOn() ? "1" : "0") << ","
                 << device->getPowerConsumption() << "\n";
        }
        file.close();
        std::cout << "Device states saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for saving: " << filename << std::endl;
    }
}

void SmartHome::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        devices.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name;
            std::string status;
            double power;
            if (std::getline(iss, name, ',') && 
                std::getline(iss, status, ',') && 
                (iss >> power)) {
                auto device = std::make_unique<SmartDevice>(name, power);
                if (status == "1") {
                    device->turnOn();
                }
                devices.push_back(std::move(device));
            }
        }
        file.close();
        std::cout << "Device states loaded from " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for loading: " << filename << std::endl;
    }
}

void SmartHome::addDevice(std::unique_ptr<SmartDevice> device) {
    devices.push_back(std::move(device));
}

void SmartHome::controlDevice(int index, bool turnOn) {
    if (index >= 0 && index < devices.size()) {
        if (turnOn) {
            devices[index]->turnOn();
        } else {
            devices[index]->turnOff();
        }
    }
}

void SmartHome::displayStatus() const {
    std::cout << "Smart Home Status:\n";
    for (size_t i = 0; i < devices.size(); ++i) {
        std::cout << i << ". " << devices[i]->getStatus() << "\n";
    }
}

double SmartHome::getTotalPowerConsumption() const {
    double total = 0.0;
    for (const auto& device : devices) {
        total += device->getPowerConsumption();
    }
    return total;
}

void SmartHome::setLightBrightness(int index, int brightness) {
    if (index >= 0 && index < devices.size()) {
        auto light = dynamic_cast<SmartLight*>(devices[index].get());
        if (light) {
            light->setBrightness(brightness);
        }
    }
}

void SmartHome::setThermostatTemperature(int index, double temperature) {
    if (index >= 0 && index < devices.size()) {
        auto thermostat = dynamic_cast<SmartThermostat*>(devices[index].get());
        if (thermostat) {
            thermostat->setTemperature(temperature);
        }
    }
}