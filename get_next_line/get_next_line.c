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

char	*get_next_line(int fd)
{
	static char	*memo_buff;
	static int	memo_index;
	char		*buff;
	size_t		read_bytes;
	int			index;

	if (!memo_index)
		memo_index = 0;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
	{
		free(memo_buff);
		free(buff);
		return (NULL);
	}
	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (read_bytes == 0 && memo_buff[memo_index] == '\0')
	{
		free(memo_buff);
		free(buff);
		return (NULL);
	}
	buff[read_bytes] = '\0';
	if (!memo_buff)
	{
		memo_buff = ft_strdup("");
		if (memo_buff == NULL)
		{
			free(memo_buff);
			free(buff);
			return (NULL);
		}
	}
	if ((BUFFER_SIZE - read_bytes) > 0 && buff[read_bytes])
	{
		free(memo_buff);
		free(buff);
		return (NULL);
	}
	memo_buff = ft_strjoin(memo_buff, buff);
	if (memo_buff == NULL)
	{
		free(memo_buff);
		free(buff);
		return (NULL);
	}
	free(buff);
	buff = NULL;
	index = 0;
	while (memo_buff[memo_index + index]
		&& memo_buff[memo_index + index] != '\n')
		index++;
	buff = ft_substr(memo_buff, memo_index, index + 1);
	if (buff == NULL)
	{
		free(memo_buff);
		free(buff);
		return (NULL);
	}
	memo_index += index + 1;
	return (buff);
}
