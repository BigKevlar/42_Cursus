/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int start = 0;
	int end = 0;
	int len = 0;
	int flag = start;
	
	if (ac == 2)
	{
		while (av[1][len] != '\0') //recorremos todo el string y guardamos su longuitud en len.
			len++;
		while (len >= 0)
		{
			while (av[1][len] == '\0' || av[1][len] == ' ' || av[1][len] == '\t') //retrocede si hay espacios o tabs.
				len--;
			end = len; //ponemos la ultima posicion de la ultima palabra en end.
			while (av[1][len] && av[1][len] != ' ' && av[1][len] != '\t') //recorremos la ultma palabra desde el final.
				len--;
			start = len + 1; //guardamos esa posicion en start + 1.
			flag = start;
			while (start <= end)
			{
				write(1, &av[1][start], 1);
				start++;
			}
			if (flag != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}

