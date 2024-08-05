#include "Contact.hpp"

/* Constructor estandar. */
Contact::Contact(){}

/* Destructor estandar.*/
Contact::~Contact(){}

/* Getters. Recordemos que lo usaremos para tomar el valor que hay en nuestra clase en sus atributos privados. */
std::string Contact::get_first_name() const {
    return (this->_first_name);
}

std::string Contact::get_last_name() const {
    return (this->_last_name);
}

std::string Contact::get_nick_name() const {
    return (this->_nick_name);
}

std::string Contact::get_phone_number() const {
    return (this->_phone_number);
}

std::string Contact::get_darkest_secret() const {
    return (this->_darkest_secret);
}

/* Setters. Recodar que los usaremos para sobreescribir el valor de nuestros atributos privados */

void    Contact::set_first_name(std::string str){
    _first_name = str;
}

void    Contact::set_last_name(std::string str){
    _last_name = str;
}

void    Contact::set_nick_name(std::string str){
    _nick_name = str;
}

void    Contact::set_phone_number(std::string str){
    _phone_number = str;
}

void    Contact::set_darkest_secret(std::string str){
    _darkest_secret = str;
}
