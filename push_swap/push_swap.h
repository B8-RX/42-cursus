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
	size_t			index;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;


t_stack	*ft_init_stack(t_stack **stack);
t_stack	*ft_init_lst(int value);
t_stack	*ft_handle_args(t_stack **stack_a, int args_len, char **args);
t_stack	*ft_push_lst(t_stack **stack, t_stack *lst);
t_stack	*ft_unshift_lst(t_stack **stack, t_stack *lst);
void	ft_shift_lst(t_stack **stack);
t_stack	*ft_get_lst_by_index(t_stack *stack, size_t index);
t_stack	*ft_sort_stack(t_stack **stack);
void	ft_update_stack_index(t_stack *stack);

char	**ft_split(char *str, char splitter);
int		ft_count_words(char *str, char splitter);
int		ft_count_spaces(char *str);
int		ft_get_len_value(char *value);
void	*ft_free_array_str(char **array);
int		ft_append_child(char *child, char *value, char splitter);

void	ft_free_stack(t_stack *stack);
char	*ft_print_error(void);
void	ft_print_values_lst(t_stack *stack);
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_a);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_b);
void	ft_rb(t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_is_digit(char *str);





