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

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)static
{
	static Base_stash	*Stash;
	int					current_fd;

	if (fd < 0 || !BUFFER_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!Stash)
		Stash = ft_init_stash(fd);
	if (!Stash)
		return (NULL);
	current_fd = Stash -> fd;
	printf("current_fd: %d\n", current_fd);
	if (current_fd)
		return ("OK");
	else
		return ("KO");
}

Base_stash	*ft_init_stash(int fd)
{
	Base_stash	*New;

	New = malloc(sizeof(Base_stash));
	if (!New)
		return (NULL);
	New -> fd = fd;
	New -> buffer = NULL;
	return  (New);
}



