/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

void print_bits(unsigned char octet)
{
	int	bits = 7; //para mostrar solo 8 bits en orden de derecha a izquierda (del 7 al 0).
	
	while (bits >= 0)
	{
		if (octet & (1 << bits)) //esta operacion lo que hace es comprobar si el primer valor de octet esta "encendido" (si es un 1), y lo va transladando a la izquierda.
			write (1, "1", 1);
		else
			write (1, "0", 1);
		bits--;
	}
}