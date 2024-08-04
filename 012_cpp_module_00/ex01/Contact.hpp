#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
    // ATRIBUTOS
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nick_name;
        std::string _phone_number;
        std::string _darkest_secret;
    // METODOS
    public:
        // CONTRUCTOR ESTANDAR
        Contact();
        // CONSTRUCTOR CON PARAMETROS
        Contact(std::string fname, std::string lname, std::string nick, std::string phone, std::string secret);
        // DESTRUCTOR ESTANDAR
        ~Contact();
        // GETTERS (tomadores/constructores): con ellos tomamos los atributos privados de la clase.
        std::string get_first_name() const;
        std::string get_last_name() const;
        std::string get_nick_name() const;
        std::string get_phone_number() const;
        std::string get_dark_secret() const;
        // SETTERS (fijadores/modificadores): con ellos establecemos los atributos privados a otros.
        void    set_first_name(std::string fname);
        void    set_last_name(std::string lname);
        void    set_nick_name(std::string nick);
        void    set_phone_number(std::string phone);
        void    set_dark_secret(std::string secret);
};

#endif