/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:32:05 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/10 19:32:07 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(char *str);
int		ft_print_char(char c);
int		ft_print_str(char *str, int size);
int		ft_print_nbr(int nb, int size);
int		ft_print_hexa(unsigned long nb, int size, char format, char *base);
int		ft_handle_format(char f, va_list args);
#endif

