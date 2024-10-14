// SmartCamera.cpp
#include "SmartCamera.h"

SmartCamera::SmartCamera(const std::string& name, double power)
    : SmartDevice(name, power), isRecording(false) {}

void SmartCamera::startRecording() {
    isRecording = true;
    turnOn();
}

void SmartCamera::stopRecording() {
    isRecording = false;
    turnOff();
}

bool SmartCamera::getRecordingStatus() const {
    return isRecording;
}

std::string SmartCamera::getStatus() const {
    return SmartDevice::getStatus() + " (" + (isRecording ? "Recording" : "Standby") + ")";
}