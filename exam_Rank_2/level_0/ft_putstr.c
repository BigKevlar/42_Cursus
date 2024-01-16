/*
Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

void	ft_putstr(char *str);
*/

void	ft_putstr(char *str)
{
	int c = 0;

	while(str[c] != '\0')
	{
		write(1, &str[c], 1);
		c++;
	}
	return ;
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Nuestra funcion toma un string y lo muestra por pantalla.
Iniciamos un contador "c" que iterará cada letra del string.
Mientras que el string no sea el caracter nulo imprime cada letra.
Finaliza la funcion sin devolver nada.
*/