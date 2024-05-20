int	ft_atoi(const char *str)
{
	int c = 0;
	int num = 0;
	int sig = 1;

	while (str[c] == ' ' || str[c] >= '\t')
		c++;
	if (str[c] == '-')
	{
		sig = -1;
		c++;
	}
	if (str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		num = (num * 10) + (str[c] - '0');
		c++;
	}
	return (num * sig);
}

/*
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	ASCII TO INTEGER (letra a numero).
	Nuestra funcion recibe un string tipo char * y lo cambia a tipo int.
	Iniciamos 3 variaables_
	- Un contador "c" que iterará cada letra del string.
	- Un numero "num" que sera el que almacenara la conversion.
	- un numero "sig" que usaremos para pasar a negativo el numero en caso de serlo.
	Vamos a comprobar si el string tiene espacios para saltarlos, si el primer
	caracter es un simbolo negatico para saltarlo y cambiar el valor de sig, si
	es un simbolo opsitivo para saltarlo, y por utimo  ir cambiando uno a uno
	los caracteres a numeros.
	Finalizamos la funcion. 
--------------------------------------------------------------------------------
*/