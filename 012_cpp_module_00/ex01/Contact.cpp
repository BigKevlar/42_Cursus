#include "Contact.hpp"

/* Constructor estandar. */
Contact::Contact(){}

/* Destructor estandar.*/
Contact::~Contact(){}

/* Getters. Recordemos que lo usaremos para tomar el valor que hay en nuestra clase en sus atributos privados. */
std::string Contact::get_first_name(){
    return (this->_first_name);
}

std::string Contact::get_last_name(){
    return (this->_last_name);
}

std::string Contact::get_nick_name(){
    return (this->_nick_name);
}

std::string Contact::get_phone_number(){
    return (this->_phone_number);
}

std::string Contact::get_darkest_secret(){
    return (this->_darkest_secret);
}

/* Setters. Recodar que los usaremos para sobreescribir el valor de nuestros atributos privados */

void    Contact::set_first_name(std::string str){
    this->_first_name = str;
}

void    Contact::set_last_name(std::string str){
    this->_last_name = str;
}

void    Contact::set_nick_name(std::string str){
    this->_nick_name = str;
}

void    Contact::set_phone_number(std::string str){
    this->_phone_number = str;
}

void    Contact::set_darkest_secret(std::string str){
    this->_darkest_secret = str;
}

void    Contact::print(int index)
{
    std::cout << std::setw(10) << std::right << "index" << "|";    
    if (_first_name.length() < 10)
        std::cout << std::setw(10) << std::right << _first_name << "|";
    else
        std::cout << std::setw(10) << std::right << _first_name.substr(0, 9) << "." << "|";
    if (_last_name.length() < 10)
        std::cout << std::setw(10) << std::right << _last_name << "|";
    else
        std::cout << std::setw(10) << std::right << _last_name.substr(0, 9) << "." << "|";
    if (_nick_name.length() < 10)
        std::cout << std::setw(10) << std::right << _nick_name << "|";
    else
        std::cout << std::setw(10) << std::right << _nick_name.substr(0, 9) << "." << "|";
    if (_phone_number.length() < 10)
        std::cout << std::setw(10) << std::right << _phone_number << "|";
    else
        std::cout << std::setw(10) << std::right << _phone_number.substr(0, 9) << "." << "|";
    if (_darkest_secret.length() < 10)
        std::cout << std::setw(10) << std::right << _darkest_secret << "|";
    else
        std::cout << std::setw(10) << std::right << _darkest_secret.substr(0, 9) << "." << "|";
    std::cout << std::endl;
    std::cout << std::endl;
}
