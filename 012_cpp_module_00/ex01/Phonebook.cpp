#include "Phonebook.hpp"

/* Constructor estandar. */
Phonebook::Phonebook()
{
    this->_index = 0; // Aqui estamos inicializando por 1a vez index.
    std::cout << "Constructor say: Welcome!" << std::endl;
}

/* Destructor estandar.*/
Phonebook::~Phonebook()
{
    std::cout << "Destructor say: Bye bye!" << std::endl;
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
        if (str != "" && std::getline(std::cin, str))
            this->_contact[this->_index % 8].set_first_name(str);
        else
            std::cout << "Error, please try again..." << std::endl;
    }

    /* Insertamos el apellido del mismo modo que antes. */    
    str = "";
    while (str == "" && (!std::cin.eof()))
    {
        std::cout << "Enter the last name: ";
        if (str != "" && std::getline(std::cin, str))
            this->_contact[this->_index % 8].set_last_name(str);
        else
            std::cout << "Error, please try again..." << std::endl;
    }

    /* Ahora insertamos el nick. */
    str = "";
    while (str == "" && (!std::cin.eof()))
    {
        std::cout << "Enter the nick name: ";
        if (str != "" && std::getline(std::cin, str))
            this->_contact[this->_index % 8].set_nick_name(str);
        else
            std::cout << "Error, please try again..." << std::endl;
    }

    /* Ahora el numero de telefono. */
    str = "";
    while(str == "" && (!std::cin.eof()))
    {
        if (str != "" && std::getline(std::cin, str) && ft_isdigit(str))
            this->_contact[this->_index % 8].set_phone_number(str);
        else
            std::cout << "Error, please try again..." << std::endl;
    }

    /* Ahora insertamos el sercreto oscuuuuuuuuuurooooo. */
    str = "";
    while (str == "" && (!std::cin.eof()))
    {
        if (str != "" && std::getline(std::cin, str))
            this->_contact[this->_index % 8].set_phone_number(str);
        else
            std::cout << "Error, please try again..." << std::endl;
    }

    /* Por ultimo aumentamos el contador de index. */
    if (this->_index == 8)
    {
        std::cout << "You write the last contact. Next one will overwrite the olders in order" << std::endl;
        this->_index = 0;
    }
    else
        this->_index++;
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
        if (str != "" && std::getline(std::cin, str))
        {
            if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && this->_contact[str[0] - 1 - '0'].get_first_name().size())
            {
                this->print(_contact[this->_index]);
                break ;
            }
        }
        else
            std::cout << "Error, please try again..." << std::endl;
    }
}

void    Phonebook::print(Contact contact)
{
    if (!contact.get_first_name().size())
	{
		std::cout << "Failed to get info for this contact" << std::endl;
		return ;
	}
	std::cout << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nick_name() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_darkest_secret() << std::endl;
}

Contact    Phonebook::get_contact(int index)
{
    return (this->_contact[this->_index % 8]);
}
