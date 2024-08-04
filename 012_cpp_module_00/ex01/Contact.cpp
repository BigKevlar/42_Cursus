#include "Contact.hpp"

/* Constructor estandar. */
Contact::Contact(){}

/* El constructor con parametros inicializa por primera vez los atributos. Despues lo haran los setters. */
Contact::Contact(std::string fname, std::string lname, std::string nick, std::string phone, std::string secret)
{
    _first_name = fname;
    _last_name = lname;
    _nick_name = nick;
    _phone_number = phone;
    _darkest_secret = secret;
}

/* Destructor estandar.*/
Contact::~Contact(){}

/* Getters. Recordemos que lo usaremos para tomar el valor que hay en nuestra clase en sus atributos privados. */
std::string Contact::get_first_name(){
    return (_first_name);
}

std::string Contact::get_last_name(){
    return (_last_name);
}

std::string Contact::get_nick_name(){
    return (_nick_name);
}

std::string Contact::get_phone_number(){
    return(_phone_number);
}

std::string Contact::get_darkest_secret(){
    return (_darkest_secret);
}

/* Setters. Recodar que los usaremos para sobreescribir el valor de nuestros atributos privados */

void    Contact::set_first_name(std::string fname){
    _first_name = fname;
}

void    Contact::set_last_name(std::string lname){
    _last_name = lname;
}

void    Contact::set_nick_name(std::string nname){
    _nick_name = nname;
}

void    Contact::set_phone_number(std::string phone){
    _phone_number = phone;
}

void    Contact::set_darkest_secret(std::string secret){
    _darkest_secret = secret;
}
