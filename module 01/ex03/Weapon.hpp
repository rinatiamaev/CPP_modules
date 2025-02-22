#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;

public:
    // Orthodox Canonical Form
    Weapon();                                // Default constructor
    Weapon(const std::string& type);         // Constructor with parameter
    Weapon(const Weapon& other);             // Copy constructor
    Weapon& operator=(const Weapon& other);  // Copy assignment operator
    ~Weapon();                               // destructor

    const std::string& getType() const;
    void setType(const std::string& newType);
};

#endif
