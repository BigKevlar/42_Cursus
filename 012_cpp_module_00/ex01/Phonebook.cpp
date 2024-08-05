#include "Phonebook.hpp"

/* Constructor estandar. */
Phonebook::Phonebook()
{
    this->_index = 0; // Aqui estamos inicializando por 1a vez index.
    std::cout << "Constructor: program ON" << std::endl;
}

/* Destructor estandar.*/
Phonebook::~Phonebook()
{
    std::cout << "Destructor: program OFF" << std::endl;
}

static int ft_isdigit(std::string str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}

/* Agregamos un contacto nuevo a la Phonebook. */
void    Phonebook::add()
{
    std::string str;

    /* Insertamos el nombre en el atributo privado del contacto usando el setter de first_name. */
    str = "";
    while(str == "" && (!std::cin.eof()))
    {
        std::cout << "Enter the first name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contact[this->_index].set_first_name(str);
        else
        {
            std::cout << "Error, please try again..." << std::endl;
            str = "";
        }
    }

    /* Insertamos el apellido del mismo modo que antes. */    
    str = "";
    while (str == "" && (!std::cin.eof()))
    {
        std::cout << "Enter the last name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contact[this->_index].set_last_name(str);
        else
        {
            std::cout << "Error, please try again..." << std::endl;
            str = "";
        }
    }

    /* Ahora insertamos el nick. */
    str = "";
    while (str == "" && (!std::cin.eof()))
    {
        std::cout << "Enter the nick name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contact[this->_index].set_nick_name(str);
        else
        {
            std::cout << "Error, please try again..." << std::endl;
            str = "";
        }
    }

    /* Ahora el numero de telefono. */
    str = "";
    while(str == "" && (!std::cin.eof()))
    {
        std::cout << "Enter the phone number: ";
        if (std::getline(std::cin, str) && str != "" && ft_isdigit(str))
            this->_contact[this->_index].set_phone_number(str);
        else
        {
            std::cout << "Error, please try again..." << std::endl;
            str = "";
        }
    }

    /* Ahora insertamos el sercreto oscuuuuuuuuuurooooo. */
    str = "";
    while (str == "" && (!std::cin.eof()))
    {
        std::cout << "Enter the ejem ejem: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contact[this->_index].set_darkest_secret(str);
        else
        {
            std::cout << "Error, please try again..." << std::endl;
            str = "";
        }
    }

    /* Por ultimo aumentamos el contador de index. */
    this->_index++;
    if (this->_index == 8)
    {
        std::cout << "You write the last contact. Next one will overwrite the olders in order" << std::endl;
        this->_index = 0;
    }
    std::cout << this->_index << std::endl;
}

/* Buscamos un contacto usando su index (si existe). */
void    Phonebook::search()
{
    std::string str;

    if (this->_contact[0].get_first_name().empty())
    {
        std::cout << "Phonebook is empty" << std::endl;
        return ;
    }
    while (!std::cin.eof())
    {
        std::cout << "Select an index (1 to 8): ";
        if (std::getline(std::cin, str) && str != "")
        {
            if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && this->_contact[str[0] - 1 - '0'].get_first_name().size())
            {
                this->_contact[std::atoi(str.c_str()) - 1].print();
                break ;
            }
        }
        else
            std::cout << "Error, please try again..." << std::endl;
    }
}

void    Contact::print()
{
	std::cout << "First Name: " << this->get_first_name() << std::endl;
	std::cout << "Last Name: " << this->get_last_name() << std::endl;
	std::cout << "Nickname: " << this->get_nick_name() << std::endl;
	std::cout << "Phone Number: " << this->get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << this->get_darkest_secret() << std::endl;
}
