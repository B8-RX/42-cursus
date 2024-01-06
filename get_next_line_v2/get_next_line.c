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

char	*ft_update_stock(char *stock, char *buff, size_t size)
{
	char	*new;

	new = ft_strjoin(stock + size, buff);
	free(stock);
	stock = NULL;
	return (new);
}

char	*ft_get_line(char *stock)
{
	char	*new;
	size_t	len;

	if (ft_strchr(stock, '\n'))
		len = ft_strlen(stock) - ft_strlen(ft_strchr(stock, '\n')) + 1;
	else
		len = ft_strlen(stock);
	new = ft_substr(stock, 0, len);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stock)
		stock = ft_strjoin("", "");
	stock = ft_read_file(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_update_stock(stock, "", ft_strlen(line));
	return (line);
}
