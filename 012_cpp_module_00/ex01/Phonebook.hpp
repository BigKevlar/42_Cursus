#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
    /* ATRIBUTOS */
    private:
        Contact _contacts[8];
    /* METODOS */
    public:
        /* CONSTRUCTOR ESTANDAR */ 
        Phonebook();
        /* DESTRUCTOR ESTANDAR */
        ~Phonebook();
        void    add();
        void    search();
        void    exit();
};

#endif