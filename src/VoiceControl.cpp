// VoiceControl.cpp
#include "VoiceControl.h"
#include <iostream>
#include <sstream>
#include <algorithm>

VoiceControl::VoiceControl(SmartHome& home) : smartHome(home) {
    registerCommands();
}

void VoiceControl::registerCommands() {
    commands["turn on"] = [this](const std::string& device) {
        int index = smartHome.findDeviceIndex(device);
        if (index != -1) {
            smartHome.controlDevice(index, true);
            std::cout << "Turned on " << device << "\n";
        }
    };

    commands["turn off"] = [this](const std::string& device) {
        int index = smartHome.findDeviceIndex(device);
        if (index != -1) {
            smartHome.controlDevice(index, false);
            std::cout << "Turned off " << device << "\n";
        }
    };

    commands["status"] = [this](const std::string& device) {
        if (device == "all") {
            smartHome.displayStatus();
        } else {
            int index = smartHome.findDeviceIndex(device);
            if (index != -1) {
                std::cout << smartHome.getDeviceStatus(index) << "\n";
            }
        }
    };

    // Add more commands as needed
}

void VoiceControl::processCommand(const std::string& input) {
    std::istringstream iss(input);
    std::string command, device;
    iss >> command >> device;

    std::string fullCommand = command + " " + device;
    std::transform(fullCommand.begin(), fullCommand.end(), fullCommand.begin(), ::tolower);

    auto it = commands.find(command);
    if (it != commands.end()) {
        it->second(device);
    } else {
        std::cout << "Unknown command. Please try again.\n";
    }
}