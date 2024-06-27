char	*ft_strcpy(char *s1, char *s2)
{
	int c = 0;

	while (s2[c] != '\0')
	{
		s1[c] = s2[c];
		c++;
	}
	s1[c] = '\0';
	return (s1);
}

/*
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	Nuestra funcion copia el origen "s2" sobre el destino "s1".
	Iniciamos un contador "c" que iterará cada letra del string.
	Mientras que el segundo string no llegue a nulo copia cada letra en la misma posicion del en el primero.
	Por ultimo pone al final el caracter nulo al final de destino, para indicar el final.
	Finaliza la funcion devolviendo destino con todo copiado del segundo.
--------------------------------------------------------------------------------
*/