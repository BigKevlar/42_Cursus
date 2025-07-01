/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:51:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 14:39:28 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	const Dog	*j = new Dog();
	const Cat	*i = new Cat();

	Brain		*brain_dog = &j->getBrain();
	Brain		*brain_cat = &i->getBrain();
	
	brain_dog->ideas_[0] = "I want a bone...";
	std::cout << brain_dog->ideas_[0] << std::endl;
	brain_cat->ideas_[0] = "I want a fish...";
	std::cout << brain_cat->ideas_[0] << std::endl;

	std::cout << j->getBrain().ideas_[0] << std::endl;
	std::cout << i->getBrain().ideas_[0] << std::endl;
	
	delete (j);
	delete (i);
	
	return (0);
}
