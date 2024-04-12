/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:52:00 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/04 01:52:01 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
	int				value;
	int				index;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;


t_stack	*ft_init_stack(t_stack **stack);
t_stack	*ft_handle_args(int args_len, char **args);
t_stack	*ft_get_last_lst(t_stack *stack);
t_stack	**ft_add_lst_back(t_stack **stack, int value, int index);
t_stack	**ft_add_lst_front(t_stack **stack, int value, int index);
int		ft_count_words(char *str, char splitter);
int		ft_is_digit(char *str);
char	*ft_print_error(void);
void	ft_print_values_lst(t_stack *stack);
int		ft_count_spaces(char *str);
int		ft_get_len_value(char *value);
char	**ft_split(char *str, char splitter);
void	*ft_free_array_str(char **array);
void	ft_free_stack(t_stack *stack);
int		ft_append_child(char *child, char *value, char splitter);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);






