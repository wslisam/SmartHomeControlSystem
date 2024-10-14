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

void SmartHome::addSchedule(const Schedule& schedule) {
    schedules.push_back(schedule);
}

void SmartHome::executeSchedules() {
    for (auto& schedule : schedules) {
        if (schedule.isTimeToExecute()) {
            schedule.execute();
        }
    }
}

void SmartHome::displaySchedules() const {
    std::cout << "Scheduled Actions:\n";
    for (size_t i = 0; i < schedules.size(); ++i) {
        std::cout << i << ". Next execution: " << schedules[i].getNextExecutionTime() << "\n";
    }
}

void SmartHome::setEnergyRate(double rate) {
    energyRate = rate;
}

void SmartHome::updateEnergyUsage() {
    auto now = std::chrono::system_clock::now();
    auto timeT = std::chrono::system_clock::to_time_t(now);
    std::string date = std::string(std::ctime(&timeT)).substr(0, 10);
    
    double totalUsage = getTotalPowerConsumption() / 1000.0; // Convert to kWh
    dailyEnergyUsage[date] += totalUsage;
}

void SmartHome::displayEnergyReport() const {
    std::cout << "Energy Usage Report:\n";
    double totalUsage = 0.0;
    for (const auto& [date, usage] : dailyEnergyUsage) {
        std::cout << date << ": " << usage << " kWh\n";
        totalUsage += usage;
    }
    std::cout << "Total Usage: " << totalUsage << " kWh\n";
    std::cout << "Estimated Cost: $" << totalUsage * energyRate << "\n";
}

void SmartHome::addNotification(const std::string& message) {
    notifications.emplace(message);
}

void SmartHome::displayNotifications() {
    std::cout << "Notifications:\n";
    while (!notifications.empty()) {
        const auto& notification = notifications.front();
        std::cout << notification.getTimestamp() << ": " << notification.getMessage() << "\n";
        notifications.pop();
    }
}

void SmartHome::setUserPreference(const std::string& key, const std::string& value) {
    userPreferences.setPreference(key, value);
}

void SmartHome::displayUserPreferences() const {
    userPreferences.displayPreferences();
}