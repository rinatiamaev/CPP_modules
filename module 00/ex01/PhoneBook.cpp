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
    std::cout << std::setw(WIDTH) << "Index" << "|" << std::setw(WIDTH) << "First name" << "|"  
                << std::setw(WIDTH) << "Last Name" << "|" << std::setw(WIDTH) << "Nickname" << std::endl;
    for (int i = 0; i < MAX_CONTACT; i++)
    {
        if (!contacts[i].isEmpty()){
            std::cout << std::setw(WIDTH) << i << "|" 
                        << std::setw(WIDTH) << truncate(contacts[i].getFirstName(), WIDTH) << "|"
                        << std::setw(WIDTH) << truncate(contacts[i].getLastName(), WIDTH) << "|"
                        << std::setw(WIDTH) << truncate(contacts[i].getNickname(), WIDTH) << std::endl;
        }
    }
}
void PhoneBook::displayContactDetails(int index){
        if (index < 0 || index >= totalContact){
            std::cout << "Invlid contact! Index not found." << std::endl;
            return ;
        }
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

void PhoneBook::takeInput() {
    std::string command;
    std::string input;
    std::cout << "WELCOME TO AWESOME PHONE BOOK!\n";
    while (true)
    {
        std::cout << "Type a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD" || command == "add")
        {
            Contact newContact;
            while (true)
            {
                std::cout << "Type first name: ";
                std::getline(std::cin, input);
                if (!input.empty())
                {
                    newContact.setFirstName(input);
                    break ;
                }
                std::cout << "Please fill first name.\n";
            }
            while (true)
            {
            std::cout << "Type last name: ";
            std::getline(std::cin, input);
            if (!input.empty())
            {
                newContact.setLastName(input);
                break ;
            }
            std::cout << "Please fill last name.\n";
            }
            while (true)
            {
            std::cout << "Type nickname: ";
            std::getline(std::cin, input);
            if (!input.empty())
            {
                newContact.setNickname(input);
                break ;
            }
            std::cout << "Please fill nickname.\n";
            }
            while (true)
            {
                std::cout << "Type phone number: ";
                std::getline(std::cin, input);

                if (input.empty())  
                    std::cout << "Please fill phone number.\n";
                else if (!isNumber(input))
                    std::cout << "Phone number must contain only digits.\n";
                else
                {
                    newContact.setPhoneNbr(input);
                    break ;
                }
            }

            while (true)
            {
                std::cout << "Type darkest secret: ";
                std::getline(std::cin, input);
                if (!input.empty())
                {
                    newContact.setDarkestSecret(input);
                    break ;
                }
                std::cout << "Please fill darkest secret.\n";
                }
                this->addContact(newContact);
        }
        else if (command == "SEARCH" || command == "search")
        {
            int maxIndex = this->getCurIndex();
            if (maxIndex == 0)
            {
                std::cout << "No contacts\n";
                continue ; 
            }
            this->displayContact();
            while (true) 
            {
                std::cout << "Select index: ";
                std::getline(std::cin, input);

                if (input.empty()) {
                    std::cout << "Invalid index. Please enter a valid number.\n";
                    continue ;
                }
                if (!this->isNumber(input))
                {
                    std::cout << "Invalid index. Please enter only digits.\n";
                    continue;
                }
                try {
                    long long index = std::stoll(input);
                    if (index < 0 || index >= totalContact) {
                        std::cout << "Index out of range. Please try again.\n";
                    } else {
                        this->displayContactDetails(index);
                        break ;
                    }
                } 
                catch (const std::out_of_range&){
                    std::cout << "Number too large! Please enter a smaller number.\n";
                }
                catch (const std::invalid_argument&){
                    std::cout << "Invalid input. Please enter a valid number.\n";
                }
            }

        }
        else if (command == "EXIT" || command == "exit")
            break ;
        else
            std::cout << "Invalid command. Please type ADD, SEARCH, or EXIT.\n";
    }
}


