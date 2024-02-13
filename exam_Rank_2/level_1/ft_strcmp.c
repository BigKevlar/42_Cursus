/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	c = 0;

	while (s1[c] != '\0' && s2[c] != '\0' && s1[c] == s2[c])
		c++;
	return (s1[c] - s2[c]);
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Nuestra funcion compara ambos string en orden lexicografico (orden numerico en el abecedario).
La funcion es sencilla. Iniciamos una variable para iterar las posiciones de los dos strings.
Luego hacemos un bucle: mientras no lleguen ningunos de los dos al caracter nulo y sean
iguales sus caracteres sigue comparando.
Una vez salgamos del bucle restamos ambos y finalizamos funcion. El resultado se interpreta asi:
- Si el resultado es = 0, los dos strings son iguales.
- Si el resultado es > 0, el primer string es mayor.
- si el resultado es < 0, el segundo string es mayor.
*/