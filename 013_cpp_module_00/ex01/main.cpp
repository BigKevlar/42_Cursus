#include "Phonebook.hpp"

int main(int ac, char **av)
{
    Phonebook       Phonebook;
    std::string     str;

    std::system("clear");
    while (1)
    {
        std::cout << "Enter an option (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, str, '\n'))
            break ;
        if (str == "ADD")
            Phonebook.add();
        else if (str == "SEARCH")
            Phonebook.search();
        else if (str == "EXIT")
        {
            std::cout << "Godbye!" << std::endl;
            return (0);
        }
        else
            std::cout << "Wrong option! Remenber..." << std::endl;
    }
    return (0);
}
