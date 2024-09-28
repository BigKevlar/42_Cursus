/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:32:14 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/28 16:49:32 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data human2;
	human2.name = "Juan Carlos Martos";
	human2.age = 32;
	human2.next = NULL;
	Data human1;
	human1.name = "Marina Romero";
	human1.age = 31;
	human1.next = &human2;

    std::cout << std::endl;
	std::cout << "[ORIGINAL]\n" << std::endl;
    std::cout << "adress human1: " << &human1 << std::endl;
    std::cout << "name human1: " << human1.name << std::endl;
    std::cout << "age human1: " << human1.age << std::endl;
	std::cout << "next address human1: " << human1.next << std::endl;
    std::cout << std::endl;
    std::cout << "adress human2: " << &human2 << std::endl;
    std::cout << "name human2: " << human2.name << std::endl;
    std::cout << "age human2: " << human2.age << std::endl;
	std::cout << "next address human2: " << human2.next << std::endl;
    std::cout << std::endl;

	Serializer serializer;
    uintptr_t serializing = serializer.serialize(&human1);
	Data *reserializing = serializer.unserialize(serializing);

    //example1!!!!!

    std::cout << std::endl;
	std::cout << "[SERIALIZING AND RESERIALIZING STRUCT]\n" << std::endl;
    std::cout << "adress human1: " << reserializing << std::endl;
    std::cout << "name human1: " << reserializing->name << std::endl;
    std::cout << "age human1: " << reserializing->age << std::endl;
	std::cout << "next address human1: " << reserializing->next << std::endl;
	std::cout << std::endl;
    std::cout << "adress human2: " << &human2 << std::endl;
    std::cout << "name human2: " << human2.name << std::endl;
    std::cout << "age human2: " << human2.age << std::endl;
	std::cout << "next address human2: " << human2.next << std::endl;
	std::cout << std::endl;

	return (0);
}
