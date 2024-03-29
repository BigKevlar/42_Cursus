/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);
*/

int	ft_strlen(char *str)
{
	int c = 0;

	while (str[c] != '\0')
		c++;
	return (c);
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Nuestra funcion calcula la longuitud de un string..
Iniciamos un contador "c" que iterará cada letra del string.
Mientras que string no llegue a nulo aumenta el contador, que tambien sirve para ir iterando en las letras.
Finaliza la funcion devolviendo "c", que ha contado todas las posiciones del string.
*/