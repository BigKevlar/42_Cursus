/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Escribe una función que tome dos unsigned int como parámetros y devuelva el 
LCM calculado de esos parámetros.

LCM (Mínimo Común Múltiplo) de dos números enteros distintos de cero es el menor número entero positivo divisible por ambos números enteros.
entero divisible por ambos enteros.

Un LCM se puede calcular de dos maneras:

- Se pueden calcular cada uno de los múltiplos de cada uno de los enteros hasta obtener un
común distinto de 0

- Se puede utilizar el HCF (Highest Common Factor) de estos dos enteros y 
calcular como sigue:

	LCM(x, y) = | x * y | / HCF(x, y)
  
  | x * y | significa "Valor absoluto del producto de x por y".

Si al menos un entero es nulo, LCM es igual a 0.

Su función debe tener el siguiente prototipo:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int n = 0;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else if (b > a)
		n = b;
	while ((n % a == 0) && (n % b == 0))
		n++;
	return (n);
}