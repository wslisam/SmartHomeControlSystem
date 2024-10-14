// SmartSpeaker.h
#ifndef SMARTSPEAKER_H
#define SMARTSPEAKER_H

#include "SmartDevice.h"

class SmartSpeaker : public SmartDevice {
private:
    int volume;
    std::string currentTrack;

public:
    SmartSpeaker(const std::string& name, double power);
    void setVolume(int level);
    void playTrack(const std::string& track);
    int getVolume() const;
    std::string getCurrentTrack() const;
    std::string getStatus() const override;
};

#endif // SMARTSPEAKER_H