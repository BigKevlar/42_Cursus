#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
    private:
        Contact _contacts[8];
    public:
        Phonebook();
        ~Phonebook();
        void    add();
        void    search();
        void    exit();
};

#endif