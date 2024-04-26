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
#include <stdlib.h>
#include "../../ft_printf_bonus/src/lib/ft_printf.h"

typedef struct s_stack {
	char			stack_name;
	int				value;
	size_t			index;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_init_stack(t_stack **stack);
int		ft_populate_stack(t_stack **stack_a, int argc, char **args);
t_stack	*ft_init_lst(int value, const char stack_name);
t_stack	*ft_handle_args(t_stack **stack_a, int args_len, char **args);
t_stack	*ft_push_lst(t_stack **stack, t_stack *lst);
t_stack	*ft_unshift_lst(t_stack **stack, t_stack *lst);
void	ft_shift_lst(t_stack **stack);
void	ft_pop_lst(t_stack **stack);
t_stack	*ft_get_lst_by_index(t_stack *stack, size_t index);
t_stack	*ft_prepare_sort_stack(t_stack **stack);
size_t	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b, size_t total_ope);
int		ft_is_sorted(t_stack *stack);
void	ft_update_stack_index(t_stack *stack);

char	**ft_split(char *str, const char splitter);
int		ft_count_words(const char *str, const char splitter);
int		ft_count_spaces(const char *str);
int		ft_get_len_value(const char *value);
void	*ft_free_array_str(char **array);
int		ft_append_child(char *child, const char *value, const char splitter);

void	ft_free_stack(t_stack *stack);
int		ft_handle_error(t_stack *stack_a);
void	ft_print_stack(t_stack *stack);
void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
size_t	ft_get_stack_len(t_stack *stack);
int		ft_get_sm_value(t_stack *stack);
int		ft_get_bg_value(t_stack *stack);

void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_a);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_b);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);

int		ft_match_condition_rb(t_stack *stack_b);
int		ft_match_condition_ra(t_stack *stack_a);
int		ft_match_condition_rrb(t_stack *stack_b);
int		ft_match_condition_sa(t_stack *stack_a);
int		ft_match_condition_sb(t_stack *stack_b);

int		ft_atoi_2(const char *str);
int		ft_is_digit(const char *str);
// size_t	ft_strlen(const char *str);





