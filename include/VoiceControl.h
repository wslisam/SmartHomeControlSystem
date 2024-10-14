// VoiceControl.h
#ifndef VOICECONTROL_H
#define VOICECONTROL_H

#include <string>
#include <map>
#include <functional>
#include "SmartHome.h"

class VoiceControl {
private:
    SmartHome& smartHome;
    std::map<std::string, std::function<void(const std::string&)>> commands;

public:
    VoiceControl(SmartHome& home);
    void registerCommands();
    void processCommand(const std::string& input);
};

#endif // VOICECONTROL_H