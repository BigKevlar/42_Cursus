/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

int	is_power_of_2(unsigned int n)
{
	if (n == 0) //si el numero es 0 devuelve 0,
		return (0);
	while (n > 1) //el bucle divide entre dos el numero si su resto da cero, hasta que n == 1, que demostraria que el ultimo numero fue 2, por lo que es potencia de 2.
	{
		if (n % 2 == 0)
			n /= 2;
		else
			return (0);
	}
	return (1);
}