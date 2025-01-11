#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    Contact contact[MAX_CONTACT];
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
            if (!input.empty())
            {
                newContact.setPhoneNbr(input);
                break ;
            }
            std::cout << "Please fill phone number.\n";
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
            phonebook.addContact(newContact);
        }
        else if (command == "SEARCH" || command == "search")
        {
            int maxIndex = phonebook.getCurIndex();
            phonebook.displayContact();
            bool again = true;
            while (again)
            {
                std::cout << "Select index: ";
                std::getline(std::cin, input);

                if (phonebook.isNumber(input)){
                    int index = std::stoi(input);
                    if (index >= 0 && index < maxIndex)
                    {
                        phonebook.displayContactDetails(index);

                        std::cout << "Search more? Y/N: ";
                        std::getline(std::cin, input);
                        if (input == "N" || input == "n") {
                            break;
                        } else if (input == "Y" || input == "y") {
                            again = true;
                        } else {
                            std::cout << "Invalid input. Please enter 'Y' or 'N'.\n";
                        }
                    }
                    else
                        std::cout << "Index out of range. Please try again.\n";
                }
                else
                    std::cout << "Invalid index. Please enter a valid number.\n";
            }
        }
        else if (command == "EXIT" || command == "exit")
        {
            break;
        }
    }
    
}