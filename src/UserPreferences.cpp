// UserPreferences.cpp
#include "UserPreferences.h"
#include <iostream>

void UserPreferences::setPreference(const std::string& key, const std::string& value) {
    preferences[key] = value;
}

std::string UserPreferences::getPreference(const std::string& key) const {
    auto it = preferences.find(key);
    return (it != preferences.end()) ? it->second : "";
}

void UserPreferences::displayPreferences() const {
    std::cout << "User Preferences:\n";
    for (const auto& [key, value] : preferences) {
        std::cout << key << ": " << value << "\n";
    }
}