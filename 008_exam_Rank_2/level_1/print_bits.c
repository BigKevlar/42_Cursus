void print_bits(unsigned char octet)
{
	int	bits = 7;
	
	while (bits >= 0)
	{
		if (octet & (1 << bits))
			write (1, "1", 1);
		else
			write (1, "0", 1);
		bits--;
	}
}
