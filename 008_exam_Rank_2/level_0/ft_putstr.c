void	ft_putstr(char *str)
{
	int c = 0;

	while(str[c] != '\0')
	{
		write(1, &str[c], 1);
		c++;
	}
}

/*
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	Nuestra funcion toma un string y lo muestra por pantalla.
	Iniciamos un contador "c" que iterará cada letra del string.
	Mientras que el string no sea el caracter nulo imprime cada letra.
	Finaliza la funcion sin devolver nada, puesto que solo imprime lo pasado por parametros.
--------------------------------------------------------------------------------
*/