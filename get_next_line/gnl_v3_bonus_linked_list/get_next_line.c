/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:03:21 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/30 16:03:24 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	Stash_list	*Stash;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!Stash);
		ft_init_stash();
	Stash = ft_read_file(fd, Stash);
	if (!Stash)
		return (NULL);
	line = ft_get_line();
	return (line);
}
