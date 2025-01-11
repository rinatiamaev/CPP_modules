#include "Contact.hpp"

void Contact::setFirstName(const std::string& name){
    first_name = name;
}
std::string Contact::getFirstName(){
    return first_name;
}
void Contact::setLastName(const std::string& family){
    last_name = family;
}
std::string Contact::getLastName(){
    return last_name;
}
void Contact::setNickname(const std::string& nick){
    nickname = nick;
}
std::string Contact::getNickname(){
    return nickname;
}
void Contact::setPhoneNbr(const std::string& phone){
    phone_nbr = phone;
}
std::string Contact::getPhoneNbr(){
    return phone_nbr;
}
void Contact::setDarkestSecret(const std::string& ds){
    darkest_secret = ds;
}
std::string Contact::getDarkestSecret(){
    return darkest_secret;
}

bool Contact::isEmpty() const {
    return first_name.empty() && last_name.empty() && nickname.empty() && phone_nbr.empty() && darkest_secret.empty();
}

