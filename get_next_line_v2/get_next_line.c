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

char	*ft_update_static_buff(char *static_buff, char *buff, size_t last_index)
{
	char	*new;

	new = ft_strjoin((static_buff + last_index), buff);
	free(static_buff);
	return (new);
}

char	*ft_update_buff(char *static_buff, char *buff, int found_lf)
{
	char	*new;
	size_t	size_line;

	if (found_lf)
		size_line = ft_strlen(static_buff)
			- ft_strlen(ft_strchr(static_buff, '\n')) + 1;
	else
		size_line = ft_strlen(static_buff) + ft_strlen(buff);
	free(buff);
	new = ft_substr(static_buff, 0, size_line);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*static_buff;
	char		*buff;

	if (!static_buff)
		static_buff = ft_strjoin("", "");
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	if (fd < 0)
		return (free(buff), NULL);
	if ((!read(fd, buff, BUFFER_SIZE) || !*buff) && *static_buff == '\0')
		return (free(buff), NULL);
	static_buff = ft_update_static_buff(static_buff, buff, 0);
	if (ft_strchr(buff, '\n'))
	{
		buff = ft_update_buff(static_buff, buff, 1);
		static_buff = ft_update_static_buff(static_buff, "", ft_strlen(buff));
	}
	else
	{
		buff = ft_update_buff(static_buff, buff, 0);
		static_buff = ft_update_static_buff(static_buff, "", ft_strlen(buff));
	}
	return (buff);
}
