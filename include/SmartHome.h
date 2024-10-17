#ifndef SMARTHOME_H
#define SMARTHOME_H

#include "Schedule.h"
#include <vector>
#include <memory>
#include "SmartDevice.h"
#include <map>
#include "Notification.h"
#include "UserPreferences.h"
#include <queue>

class SmartHome {
private:
    std::vector<std::unique_ptr<SmartDevice>> devices;
    std::vector<Schedule> schedules;
    std::map<std::string, double> dailyEnergyUsage;
    double energyRate; // Cost per kWh
    std::queue<Notification> notifications;
    UserPreferences userPreferences;
    

public:
    void addDevice(std::unique_ptr<SmartDevice> device);
    void controlDevice(int index, bool turnOn);
    void displayStatus() const;
    double getTotalPowerConsumption() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void setLightBrightness(int index, int brightness);
    void setThermostatTemperature(int index, double temperature);
    void addSchedule(const Schedule& schedule);
    void executeSchedules();
    void displaySchedules() const;
    void setEnergyRate(double rate);
    void updateEnergyUsage();
    void displayEnergyReport() const;
    void addNotification(const std::string& message);
    void displayNotifications();
    void setUserPreference(const std::string& key, const std::string& value);
    void displayUserPreferences() const;
    int findDeviceIndex(const std::string& deviceId) const;
    bool getDeviceStatus(int index) const;
};

#endif // SMARTHOME_H