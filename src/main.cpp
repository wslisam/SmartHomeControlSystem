#include <iostream>
#include <memory>
#include "SmartHome.h"
#include "SmartDevice.h"
#include "SmartLight.h"
#include "SmartThermostat.h"


void displayMenu() {
    std::cout << "\nSmart Home Control System\n";
    std::cout << "1. Display device status\n";
    std::cout << "2. Turn on a device\n";
    std::cout << "3. Turn off a device\n";
    std::cout << "4. Display total power consumption\n";
    std::cout << "5. Exit\n";
    std::cout << "6. Set light brightness\n";
    std::cout << "7. Set thermostat temperature\n";
    std::cout << "Enter your choice: ";
}

int main() {
    SmartHome myHome;

    // Add some sample devices
    myHome.addDevice(std::make_unique<SmartDevice>("Living Room Light", 60.0));
    myHome.addDevice(std::make_unique<SmartDevice>("Kitchen Appliance", 1500.0));
    myHome.addDevice(std::make_unique<SmartDevice>("Bedroom AC", 1000.0));
    myHome.addDevice(std::make_unique<SmartLight>("Living Room Light", 60.0));
    myHome.addDevice(std::make_unique<SmartThermostat>("Living Room AC", 1000.0));
    myHome.addDevice(std::make_unique<SmartLight>("Bedroom Light", 40.0));

    int choice;
    do
    {
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            myHome.displayStatus();
            break;
        case 2:
        case 3:
        {
            int deviceIndex;
            std::cout << "Enter device index: ";
            std::cin >> deviceIndex;
            myHome.controlDevice(deviceIndex, choice == 2);
            break;
        }
        case 4:
            std::cout << "Total power consumption: "
                      << myHome.getTotalPowerConsumption() << " watts\n";
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        case 6:
        {
            int deviceIndex, brightness;
            std::cout << "Enter light index: ";
            std::cin >> deviceIndex;
            std::cout << "Enter brightness (0-100): ";
            std::cin >> brightness;
            myHome.setLightBrightness(deviceIndex, brightness);
            break;
        }
        case 7:
        {
            int deviceIndex;
            double temperature;
            std::cout << "Enter thermostat index: ";
            std::cin >> deviceIndex;
            std::cout << "Enter temperature: ";
            std::cin >> temperature;
            myHome.setThermostatTemperature(deviceIndex, temperature);
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}