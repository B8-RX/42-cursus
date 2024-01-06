/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:31:51 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/16 02:31:53 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif // !BUFFER_SIZE

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

char	*get_next_line(int fd);		
void	*ft_calloc(size_t nb, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlcat(char *dst, char *src, size_t size);
void	*ft_free_memo(char *buff);
int		ft_init_static_vars(char **memo_buff, int *memo_index);

#endif // !GET_NEXT_LINE_H
