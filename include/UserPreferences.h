// UserPreferences.h
#ifndef USERPREFERENCES_H
#define USERPREFERENCES_H

#include <string>
#include <map>

class UserPreferences {
private:
    std::map<std::string, std::string> preferences;

public:
    void setPreference(const std::string& key, const std::string& value);
    std::string getPreference(const std::string& key) const;
    void displayPreferences() const;
};

#endif // USERPREFERENCES_H