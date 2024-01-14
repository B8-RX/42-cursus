/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:03:21 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/30 16:03:24 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_stash_list	*stash;
	t_stash_list		*current_fd;
	char				*line;
	int					i;

	if (fd < 0 || !BUFFER_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash && !ft_init_stash(&stash, fd))
		return (NULL);
	current_fd = ft_get_file_stash(&stash, fd);
	if (!current_fd)
		return (NULL);
	if (!ft_read_file(&stash, fd))
		return (NULL);
	line = ft_get_line(current_fd);
	i = 0;
	while (line[i])
		i++;
	current_fd = ft_update_stash(&current_fd, "", i);
	return (line);
}

t_stash_list	*ft_read_file(t_stash_list **stash, int fd)
{
	ssize_t			read_bytes;
	char			*temp_buffer;
	char			*temp_stash;
	t_stash_list	*current_fd;

	current_fd = ft_get_file_stash(stash, fd);
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	temp_buffer[0] = '\0';
	temp_stash = current_fd -> fd_stash -> buffer;
	read_bytes = 1;
	while (read_bytes && !ft_strchr(temp_buffer, '\n'))
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if ((read_bytes == 0
				&& *temp_stash == '\0') || read_bytes == -1)
			return (free(temp_buffer), ft_release_file_stash(stash, fd));
		temp_buffer[read_bytes] = '\0';
		current_fd = ft_update_stash(&current_fd, temp_buffer, 0);
		temp_stash = current_fd -> fd_stash -> buffer;
	}
	free(temp_buffer);
	return (*stash);
}

t_stash_list	*ft_update_stash(t_stash_list **stash, char *buff, int len)
{
	char			*old_buffer;
	char			*updated_buffer;
	t_stash_list	*current_fd;

	current_fd = *stash;
	old_buffer = current_fd -> fd_stash -> buffer;
	updated_buffer = ft_strjoin(old_buffer + len, buff);
	free(current_fd -> fd_stash -> buffer);
	current_fd -> fd_stash -> buffer = NULL;
	current_fd -> fd_stash -> buffer = ft_strjoin(updated_buffer, "");
	free(updated_buffer);
	updated_buffer = NULL;
	return (current_fd);
}

t_stash_list	*ft_get_file_stash(t_stash_list **stash, int fd)
{
	t_stash_list	*current;

	if (!*stash)
		return (NULL);
	current = *stash;
	while (current != NULL)
	{
		if (current -> fd_stash -> fd == fd)
			return (current);
		current = current -> next;
	}
	return (ft_create_file_stash(stash, fd));
}

void	*ft_release_file_stash(t_stash_list **stash, int fd)
{
	t_stash_list	*last;
	t_stash_list	*current;

	current = *stash;
	last = *stash;
	if (current -> fd_stash -> fd == fd)
		*stash = current -> next;
	else
	{
		while (current != NULL)
		{
			if (current -> fd_stash -> fd == fd)
				break ;
			else if (current -> next -> fd_stash -> fd != fd)
			{
				current = current -> next;
				last = current;
			}
			else
				current = current -> next;
		}
		last -> next = current -> next;
	}
	return (free(current -> fd_stash -> buffer),
		free(current -> fd_stash), free(current), NULL);
}
