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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_update_memo_buff(char *memo_buff, char *buff, size_t last_index)
{
	char	*new;

	new = ft_strjoin((memo_buff + last_index), buff);
	free(memo_buff);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*memo_buff;
	char		*buff;
	size_t		last_index;

	if (!memo_buff)
		memo_buff = ft_strjoin("", "");
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (free(memo_buff), NULL);
	if (!read(fd, buff, BUFFER_SIZE) && memo_buff[ft_strlen(memo_buff)] == '\0')
		return (free(buff), free(memo_buff), NULL);
	last_index = 0;
	memo_buff = ft_update_memo_buff(memo_buff, buff, last_index);
	if (ft_strchr(buff, '\n'))
	{
		last_index = ft_strlen(memo_buff) - ft_strlen(ft_strchr(memo_buff, '\n')) + 1;
		free(buff);
		buff = ft_substr(memo_buff, 0, last_index);
	}
	else
	{
		last_index = ft_strlen(buff);
		free(buff);
		buff = ft_strjoin(memo_buff, "");
	}
	memo_buff = ft_update_memo_buff(memo_buff, "", last_index);
	return (buff);	
}
