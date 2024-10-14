// SmartCamera.h
#ifndef SMARTCAMERA_H
#define SMARTCAMERA_H

#include "SmartDevice.h"

class SmartCamera : public SmartDevice {
private:
    bool isRecording;

public:
    SmartCamera(const std::string& name, double power);
    void startRecording();
    void stopRecording();
    bool getRecordingStatus() const;
    std::string getStatus() const override;
};

#endif // SMARTCAMERA_H