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

void	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}

void	handle_error_case(t_error_case error, t_malloc_resource *var)
{
	t_malloc_resource	*var
	print_error();
	if (error == ERROR_NUM || ERROR_INT_LEN)
		free_split(splitstr_arr);
	else if (error == ERROR_INT_BOUNDARY)
	
	else if (error == ERROR_DUPLICATE_NUM)
	
	exit(EXIT_FAILURE);
}
