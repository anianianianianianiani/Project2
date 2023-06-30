#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_list	*start;
	t_list	*next;

	while (stack && stack->a)
	{
		start = stack->a;
		next = stack->a;
		while (next->next)
		{
			start = next;
			next = next->next;
		}
		if (start == next)
		{
			free(stack->a);
			stack->a = NULL;
		}
		else
		{
			start->next = NULL;
			free(next);
		}
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**test;

	if (argc > 1)
	{
		test = join_args(argc, argv);
		if (*test == NULL)
			return (0);
		if (arg_check(test) != 0)
			free_dp(&test, 1);
		stack = make_stack(&test);
		push_swap(stack);
		free_stack(stack);
	}
	return (0);
}
