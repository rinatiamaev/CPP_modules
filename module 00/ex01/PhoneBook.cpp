#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string PhoneBook::truncate(const std::string& str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return str;
}

void PhoneBook::addContact(Contact& contact){
    contacts[curIndex] = contact;
    curIndex = (curIndex + 1) % MAX_CONTACT;
    if (totalContact < MAX_CONTACT)
        totalContact++;
}
int PhoneBook::getCurIndex() const {
    return totalContact;
}
void PhoneBook::displayContact(){
    std::cout << std::setw(WEIGHT) << "Index" << "|" << std::setw(WEIGHT) << "First name" << "|"  
                << std::setw(WEIGHT) << "Last Name" << "|" << std::setw(WEIGHT) << "Nickname" << std::endl;
    for (int i = 0; i < MAX_CONTACT; i++)
    {
        if (!contacts[i].isEmpty()){
            std::cout << std::setw(WEIGHT) << i << "|" 
                        << std::setw(WEIGHT) << truncate(contacts[i].getFirstName(), WEIGHT) << "|"
                        << std::setw(WEIGHT) << truncate(contacts[i].getLastName(), WEIGHT) << "|"
                        << std::setw(WEIGHT) << truncate(contacts[i].getNickname(), WEIGHT) << std::endl;
        }
    }
}
void PhoneBook::displayContactDetails(int index){
        std::cout << "Index: "<< index << std::endl 
                    << "First Name: " << contacts[index].getFirstName() << std::endl
                    << "Last Name: " << contacts[index].getLastName() << std::endl
                    << "Nickname: " << contacts[index].getNickname() << std::endl
                    << "Phone number: " << contacts[index].getPhoneNbr() << std::endl
                    << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
bool PhoneBook::isNumber(const std::string& str) {
for (char c : str) {
    if (!std::isdigit(c)) {
        return false;
    }
}
return !str.empty();
}


