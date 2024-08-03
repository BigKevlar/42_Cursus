#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>

class Phonebook
{
    private:
        Contact _contacts[8];
    public:
        Phonebook();
        ~Phonebook();
};

#endif