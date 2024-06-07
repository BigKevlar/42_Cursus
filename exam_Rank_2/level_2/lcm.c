unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm = 0;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		lcm = a;
	if (b > a)
		lcm = b;
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		else
			lcm++;
	}
}
