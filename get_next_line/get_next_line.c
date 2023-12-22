/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:31:05 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/16 02:31:08 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_free_memo(char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			free((char *)va_arg(args, char *));
			format += 2;
		}
		else
			format++;
	}
	va_end(args);
	return (NULL);
}

void	ft_init_static_vars(char **memo_buff, int *memo_index)
{
	if (!*memo_buff)
	{
		*memo_buff = ft_strdup("");
		memo_index = 0;
	}
}

char	*get_next_line(int fd)
{
	static char	*memo_buff;
	static int	memo_index;
	char		*buff;
	size_t		read_bytes;
	int			index;

	ft_init_static_vars(&memo_buff, &memo_index);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free_memo("%s%s", memo_buff, buff));
	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (!read_bytes && memo_buff[memo_index] == '\0')
		return (ft_free_memo("%s%s", memo_buff, buff));
	buff[read_bytes] = '\0';
	memo_buff = ft_strjoin(memo_buff, buff);
	free(buff);
	buff = NULL;
	index = 0;
	while (memo_buff[memo_index + index]
		&& memo_buff[memo_index + index] != '\n')
		index++;
	buff = ft_substr(memo_buff, memo_index, index + 1);
	memo_index += index + 1;
	return (buff);
}
