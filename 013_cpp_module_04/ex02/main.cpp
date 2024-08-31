/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:51:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 17:38:13 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	const AAnimal	*j = new Dog();
	const AAnimal	*i = new Cat();
	Brain	*brain_dog = &j->getBrain();
	Brain	*brain_cat = &i->getBrain();
	brain_dog->ideas_[0] = "I want a bone...";
	std::cout << brain_dog->ideas_[0] << std::endl;
	brain_cat->ideas_[0] = "I want a fish...";
	std::cout << brain_cat->ideas_[0] << std::endl;
	
	std::cout << std::endl;
	
	Cat	Cat1;
	Cat1.getBrain().ideas_[0] = "I want a fish_1...";
	Cat	Cat2(Cat1);
	std::cout  << Cat2.getBrain().ideas_[0] << std::endl;

	std::cout << std::endl;

	AAnimal	*Cat3 = new Cat();
	Cat3->getBrain().ideas_[0] = "I want a fish..._3";
	std::cout << "idea de Cat3: " << Cat3->getBrain().ideas_[0] << std::endl;
	AAnimal	*Cat4 = new Cat();
	*Cat4 = *Cat3;
	std::cout << "idea de Cat4: " << Cat4->getBrain().ideas_[0] << std::endl;

	std::cout << std::endl;
	
	Cat	*Cat5 = new Cat();
	Cat5->getBrain().ideas_[0] = "I want a fish..._5";
	std::cout << "idea de Cat5: " << Cat5->getBrain().ideas_[0] << std::endl;
	AAnimal	*Cat6 = new Cat(*Cat5);
	std::cout << "idea de Cat6: " << Cat6->getBrain().ideas_[0] << std::endl;

	std::cout << std::endl;
	
	delete (j);
	delete (i);
	delete (Cat3);
	delete (Cat4);
	
	return (0);
}
