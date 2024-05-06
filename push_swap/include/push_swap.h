

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>


typedef struct s_stack_node {
	char	*stack_name;
	int		value;
	int		index;
	int		operations_cost;
	int		is_best_move;

	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

char	**ft_split(char *str, const char splitter);
int		ft_append_child(char *child, const char *value, const char splitter);
int		ft_count_words(const char *str, const char splitter);
int		ft_is_digit(int c);
int		ft_count_spaces(const char *str);
int		ft_atol(const char *str);
int		ft_get_len_value(const char *value);
void	*ft_free_array_str(char **array);



#endif // ! PUSH_SWAP_H
