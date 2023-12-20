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

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif // !BUFFER_SIZE

char	*get_next_line(int fd);		
void	*ft_calloc(size_t nb, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif // !GET_NEXT_LINE_H
