#include "push_swap.h"
#include <unistd.h>

// void	free_resource(char **a, t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	while (a[i])
// 	{
// 		free(a[i]);
// 		i++;
// 	}
// 	free(a);

// 	t_node	*tmp;
// 	t_node	*current_node;

// 	current_node = stack->head;
// 	while (current_node)
// 	{
// 		tmp = current_node->next;
// 		free(current_node);
// 		current_node = tmp;
// 	}
// }

void	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}

void	handle_error_case(t_error_case error, t_malloc_resource *var)
{
	print_error();
	free_split(var->splitstr_arr);
	if (error == ERROR_INT_BOUNDARY || error == ERROR_DUPLICATE_NUM)
		free_num_arr(var->num_arr);
	exit(EXIT_FAILURE);
}
