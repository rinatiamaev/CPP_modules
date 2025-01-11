#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_nbr;
    std::string darkest_secret;

public:
    void setFirstName(const std::string& name);
    void setLastName(const std::string& family);
    void setNickname(const std::string& nick);
    void setPhoneNbr(const std::string& phone);
    void setDarkestSecret(const std::string& ds);
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNbr();
    std::string getDarkestSecret();
    bool isEmpty() const;
};

#endif 


