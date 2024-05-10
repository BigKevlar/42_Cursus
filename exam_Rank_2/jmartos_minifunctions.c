// MINI_ATOI
int miniatoi(char *str)
{
    int c = 0;
    int num = 0;

    while (str[c] != '\0')
    {
        num = (num * 10) + (str[c] - '0');
        c++;
    }
    return (num);
}

// PRINT_NUM
void print_num(char num)
{
    char digit;

    if (num >= 10)
        print_num(num / 10);
    digit = (num % 10) + '0';
    write(1, &digit, 1);
}
