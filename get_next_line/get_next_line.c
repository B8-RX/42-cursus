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

void	*ft_free_memo(char *buff)
{
	free(buff);
	return (NULL);
}

int	ft_init_static_vars(char **memo_buff, int *memo_index)
{
	free(*memo_buff);
	*memo_buff = ft_calloc(1, sizeof(char));
	if (!*memo_buff)
		*memo_index = -1;
	else
		*memo_index = 0;
	return (*memo_index);
}

char	*get_next_line(int fd)
{
	static char	*memo_buff;
	static int	memo_index;
	char		*buff;
	int			index;

	if (!memo_buff && !memo_index)
		if (ft_init_static_vars(&memo_buff, &memo_index) == -1)
			return (NULL);
	buff = ft_calloc((BUFFER_SIZE), sizeof(char));
	if (!buff)
		return (ft_free_memo(buff));
	if (!read(fd, buff, BUFFER_SIZE) && memo_buff[memo_index] == '\0')
		return (ft_free_memo(buff));
	memo_buff = ft_strjoin(memo_buff, buff);
	free(buff);
	index = 0;
	while (memo_buff[memo_index + index] != '\n'
		&& memo_buff[memo_index + index])
		index++;
	if (memo_buff[memo_index + index] == '\n')
		index++;
	buff = ft_substr(memo_buff, memo_index, index);
	memo_index += index;
	return (buff);
}
