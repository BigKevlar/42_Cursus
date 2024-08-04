#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
    private:  // Atributos
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
    public: // Metodos (para acceder a los atributos)
        Contact(); // Constructor
        ~Contact(); // Destructor
        void    set_data();
        void    get_data();
};

#endif