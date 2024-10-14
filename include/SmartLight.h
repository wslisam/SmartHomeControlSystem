// SmartLight.h
#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H

#include "SmartDevice.h"

class SmartLight : public SmartDevice {
private:
    int brightness;

public:
    SmartLight(const std::string& name, double power);
    void setBrightness(int level);
    int getBrightness() const;
    std::string getStatus() const override;
};

#endif // SMARTLIGHT_H