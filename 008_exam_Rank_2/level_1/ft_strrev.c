char *ft_strrev(char *str)
{
	int start = 0;
	int end = 0;
	char tmp;

	while (str[end] != '\0')
		end++;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
	return (str);
}
