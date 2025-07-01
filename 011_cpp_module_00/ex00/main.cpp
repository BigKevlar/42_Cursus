/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:21:22 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/13 19:21:23 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Entrada/salida estandar, contiene el namespace "std".

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i = 1;
        char *str;
        while (av[i])
        {
            str = av[i];
            int j = 0;
            while (str[j])
            {
                str[j] = std::toupper(str[j]);
                j++;
            }
            std::cout << str;
            i++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
