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
	char *new;

	new = ft_strjoin(stock + size, buff);
	free(stock);
	return (new);
}

char	*ft_get_line(char *stock, char *buff)
{
	char	*new;
	size_t	len;

	if (ft_strchr(stock, '\n'))
		len = ft_strlen(stock) - ft_strlen(ft_strchr(stock, '\n')) + 1;
	else
		len = ft_strlen(stock);
	free(buff);
	new = ft_substr(stock, 0, len);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buff;
	ssize_t		read_bytes;


	if (!stock)
		stock = ft_strjoin("", "");
	if (fd < 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	buff[0] = '\0';
	while (read_bytes > 0 && !ft_strchr(buff, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if ((read_bytes == 0 || *buff == '\0') && *stock == '\0')
			return (free(buff), NULL);
		buff[read_bytes] = '\0';
		stock = ft_update_stock(stock, buff, 0);
	}
	buff = ft_get_line(stock, buff);
	stock = ft_update_stock(stock, "", ft_strlen(buff));
	return (buff);
}
