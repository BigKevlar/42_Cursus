/*
Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	c = 0;

	if (ac == 2)
	{
		while (av[1][c] != '\0')
		{
			if (av[1][c] >= 'A' && av[1][c] <= 'Z')
				av[1][c] += 32;
			else if (av[1][c] >= 'a' && av[1][c] <= 'z')
				av[1][c] -= 32;
			write(1, &av[1][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Nuestro programa cambiara las minusculas por mayusculas y viceversa (segun tabla ASCII).
Incluimos la libreria "unistd.h" para usar la funcion "write".
Para ello primero creamos una variable "c" para iterar sobre todoas las letras del string.
Luego condicionamos que deben ser dos argumentos solo.
Ahora hacemos un bucle que recorra todo el string y vamos haciendo las condiciones:
- Si es minuscula aumenta 32 posiciones para convertirla en su homologo en mayuscula.
- Si es mayuscula restamos 32 posiciones para convertirla en su homologo en minuscula.
- Al final imprimimos lo que sea que haya en la posicion, cambiada o no.
Ponemos un salto de linea y finalizamos programa.
*/