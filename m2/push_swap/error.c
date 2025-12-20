#include "push_swap.h"
#include <unistd.h>

void	free_resource(char **a, t_stack *stack)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);

	t_node	*tmp;
	t_node	*current_node;

	current_node = stack->head;
	while (current_node)
	{
		tmp = current_node->next;
		free(current_node);
		current_node = tmp;
	}
}

void	print_error()
{
	write(STDERR_FILENO, "Error\n", 6);
}