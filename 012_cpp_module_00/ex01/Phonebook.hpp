#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
    private: // Atributos
        Contact _contacts[8];
    public: // Metodos (para acceder a los atributos)
        Phonebook(); // Constructor
        ~Phonebook(); // Destructor
        void    add();
        void    search();
        void    exit();
};

#endif