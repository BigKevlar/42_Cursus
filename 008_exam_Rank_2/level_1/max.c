int	max(int *tab, unsigned int len)
{
	int max = tab[0];

	if (len == 0)
		return (0);
	while (len > 0)
	{
		if (max < tab[len - 1])
			max = tab[len - 1];
		len--;
	}
	return (max);
}
