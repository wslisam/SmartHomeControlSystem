// SmartThermostat.h
#ifndef SMARTTHERMOSTAT_H
#define SMARTTHERMOSTAT_H

#include "SmartDevice.h"

class SmartThermostat : public SmartDevice {
private:
    double temperature;

public:
    SmartThermostat(const std::string& name, double power);
    void setTemperature(double temp);
    double getTemperature() const;
    std::string getStatus() const override;
};

#endif // SMARTTHERMOSTAT_H