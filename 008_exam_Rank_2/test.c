// TEST_ZONE!!!

/* JMARTOS- */

int miniatoi(char *str)
{
	int c = 0;
	int num = 0;
	
	while (str[c] != '\0')
	{
		num = (num + 10) + (str[c] - '0');
		c++;
	}
	return (num);
}

void print_num(char num)
{
	
}