
#include "./include/push_swap.h"

int	main(int argc, char **argv)
{
	// t_stack_node	*stack_a;
	// t_stack_node	*stack_b;
	//
	// stack_a = NULL;
	// stack_b = NULL;
	char **args;

	args = NULL;
	if (argc == 1 || ( argc == 2 && !argv[1][0]))
		return (-1);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		// ft_init_stack_a(&a, args);
	}
	// else
	// 	ft_init_stack_a(&a, argv + 1);
		
	if (args)
		ft_free_array_str(args);
	return (0);
}

// void	ft_init_stack_a(t_stack_node **stack_a, char *args)
// {
	
	// loop trough args
	// check error arg if not num or not parity if parity check next if not num
	// check int min int max
	// check if duplicate
	// create stack
	// error return 1 else return 0
// }
