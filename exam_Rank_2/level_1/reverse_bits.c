/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Escribe una función que tome un byte, lo invierta, bit a bit (como el
ejemplo) y devuelva el resultado.

Tu función debe ser declarada como sigue:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/

unsigned char	reverse_bits(unsigned char octet)
{
    int             bits = 7;
	unsigned char	res = 0;

	while (bits >= 0)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
	}
	return (res);
}