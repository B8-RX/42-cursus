#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
	int	nbr;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;


t_stack	*ft_handle_args(int args_len, char **args, t_stack **stack);
char	**ft_handle_second_arg(char **argv);
int		ft_count_words(char *arg);
int		ft_is_digit(char c);
void	ft_print_error(void);






