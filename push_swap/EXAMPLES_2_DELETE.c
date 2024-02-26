typedef struct s_stack_test
{
	char				**str;
	t_list *a;
	t_list *b;
} t_stack_test;

typedef struct s_int
{
	long value;
	
} t_int;

int	main(int ac, char **av)
{
	(void)ac;
	t_int *num1;
	t_int *num2;
	t_stack_test *all;
	
	num1 = malloc(1 * sizeof(t_int));
	all = malloc(1 * sizeof(t_list));
	num1->value = atoi(av[1]);
	ft_lstadd_back(&all->a, ft_lstnew(num1));
	num2 = all->a->content;
	printf("%ld\n", num2->value);
}
