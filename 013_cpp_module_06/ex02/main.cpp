#include "Base.hpp"

Base	*generate(void) // Genera aleatoriamente un objeto clase entre 3.
{
	switch (rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			std::cout << "ERROR!" << std::endl;
			return (NULL);
	}
}

void	identify(Base *p) // Comprueba la conversion entre p y A-B-C e imprime.
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "[*]The type is A." << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p))
	{
		std::cout << "[*]The type is B." << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p))
	{
		std::cout << "[*]The type is C." << std::endl;
		return ;
	}
}

void	identify(Base &p) // Comprueba la conversion entre p y A-B-C e imprime.
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "[&]The type is A" << std::endl;
		return ;
	}
	catch(std::bad_cast &){}
	try
	{
		(void)dynamic_cast<B &>(p); 
		std::cout << "[&]The type is B" << std::endl;
		return ;
	}
	catch(std::bad_cast &){}
	try
	{
		(void)dynamic_cast<C &>(p); 
		std::cout << "[&]The type is C" << std::endl;
		return ;
	}
	catch(std::bad_cast &){}
}

int main(void)
{
	srand(time(NULL));	// Asi reiniciamos la semilla de rand a tiempo de ejecucion.
	for(int i = 0; i < 6; i++)
	{
		Base *p = generate();
		identify(p);
		identify(*p);
		delete (p);
	}
	return (0);
}
