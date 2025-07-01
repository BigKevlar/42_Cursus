/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:13:53 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/23 17:30:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> // Para los open y demas por el estilo.

void replace(std::ifstream &read, std::ofstream &write, std::string src, std::string dst)
{
	std::string line;
	int i;

	while (std::getline(read, line))
	{
		i = 0;
		while ((i = line.find(src, i)) != std::string::npos)
		{
			line.erase(i, src.length());
			line.insert(i, dst);
			i += dst.length();
		}
		write << line << "\n";
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error! Arguments incorrect." << std::endl;
		exit(1);
	}
	std::ifstream	infile;  // Archivo del que vamos a leer.
	std::ofstream	outfile; // Archivo al que escribiremos.

	infile.open(av[1]);
	if (!infile || !infile.is_open() || std::string(av[2]).empty())
	{
		if (infile.is_open())
			infile.close();
		std::cout << "Error! Fail searching file or directory." << std::endl;
		exit(1);
	}
	outfile.open(std::string(av[1]) + ".replace");
	if (!outfile.is_open())
	{
		infile.close();
		std::cout << "Error! Fail searching file or directory." << std::endl;
		exit(1);
	}
	replace(infile, outfile, av[2], av[3]);
	infile.close();
	outfile.close();
	return (0);
}
