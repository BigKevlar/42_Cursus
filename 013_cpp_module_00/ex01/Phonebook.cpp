/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:22:10 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/13 19:22:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/* Constructor estandar. */
Phonebook::Phonebook()
{
    this->_index = 0; // Aqui estamos inicializando por 1a vez index.
}

/* Destructor estandar.*/
Phonebook::~Phonebook()
{
    std::cout << "Phonebook deleted!" << std::endl;
}

static int ft_isdigit(std::string str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}

/* Agregamos un contacto nuevo a la Phonebook. */
void Phonebook::add()
{
    std::string str;

    /* Insertamos el nombre en el atributo privado del contacto usando el setter de first_name. */
    str = "";
    while (str == "" && (!std::cin.eof()))
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
    while (str == "" && (!std::cin.eof()))
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
}

void    Phonebook::show_phonebook()
{
    int i;
    
    std::cout << "|";
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
    i = 0;
    while (i < 8)
    {
        std::cout << "|";
        std::cout << std::setw(10) << std::right << i + 1 << "|";
        if (this->_contact[i].get_first_name().length() < 10)
            std::cout << std::setw(10) << std::right << this->_contact[i].get_first_name() << "|";
        else
            std::cout << std::setw(10) << std::right << this->_contact[i].get_first_name().substr(0, 9) + "." << "|";
        if (this->_contact[i].get_last_name().length() < 10)
            std::cout << std::setw(10) << std::right << this->_contact[i].get_last_name() << "|";
        else
            std::cout << std::setw(10) << std::right << this->_contact[i].get_last_name().substr(0, 9) + "." << "|";
        if (this->_contact[i].get_nick_name().length() <= 10)
            std::cout << std::setw(10) << std::right << this->_contact[i].get_nick_name() << "|" << std::endl;
        else
            std::cout << std::setw(10) << std::right << this->_contact[i].get_nick_name().substr(0, 9) + "." << "|" << std::endl;
        i++;
    }
}

/* Buscamos un contacto usando su index (si existe). */
void Phonebook::search()
{
    std::string str;

    if (this->_contact[0].get_first_name().empty())
    {
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }
    while (!std::cin.eof())
    {
        std::cout << std::endl;
        this->show_phonebook();
        std::cout << std::endl;
        std::cout << "Select an existing contact (1 to 8): ";
        if (std::getline(std::cin, str) && str != "")
        {
            if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && this->_contact[str[0] - 1 - '0'].get_first_name().size())
            {
                this->_contact[std::atoi(str.c_str()) - 1].print(Phonebook::_index);
                break;
            }
        }
        else
            std::cout << "Error, please try again..." << std::endl;
    }
}
