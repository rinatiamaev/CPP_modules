#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

#define WEIGHT 10
#define MAX_CONTACT 8

class PhoneBook {
private:
    Contact contacts[MAX_CONTACT];
    int curIndex = 0;
    int totalContact = 0;
    static std::string truncate(const std::string& str, size_t width);

public:
    void addContact(Contact& contact);
    int getCurIndex() const;
    void displayContact();
    void displayContactDetails(int index);
    bool isNumber(const std::string& str);
};

#endif