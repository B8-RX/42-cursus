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
	static t_fd_stash_list	*stash;
	t_fd_stash_list			*curr_fd_stash;
	char					*line;

	if (fd < 0 || !BUFFER_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash && !ft_init_stash(&stash, fd))
		return (NULL);
	curr_fd_stash = ft_handle_fd(&stash, fd);
	if (!curr_fd_stash)
		return (NULL);
	if (!ft_read_file(&stash, fd))
		return (NULL);
	line = ft_get_line(curr_fd_stash);
	curr_fd_stash = ft_update_fd_stash(curr_fd_stash, "", ft_strlen(line));
	return (line);
}

t_fd_stash_list	*ft_init_stash(t_fd_stash_list **stash, int fd)
{
	t_fd_stash_list	*new;

	new = malloc(sizeof(t_fd_stash_list));
	if (!new)
		return (NULL);
	new -> fd_stash = malloc(sizeof(t_fd_stash));
	if (!new -> fd_stash)
		return (free(new), NULL);
	new -> fd_stash -> fd = fd;
	new -> fd_stash -> buffer = malloc(1);
	if (!(new -> fd_stash -> buffer))
		return (free(new -> fd_stash), free(new), NULL);
	*(new -> fd_stash -> buffer) = '\0';
	new -> next = NULL;
	*stash = new;
	return (*stash);
}

t_fd_stash_list	*ft_handle_fd(t_fd_stash_list **stash, int fd)
{
	t_fd_stash_list	*current;

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

t_fd_stash_list	*ft_create_file_stash(t_fd_stash_list **stash, int fd)
{
	t_fd_stash_list	*current;
	t_fd_stash_list	*updated_stash;

	updated_stash = *stash;
	current = malloc(sizeof(t_fd_stash_list));
	if (!current)
		return (NULL);
	current -> fd_stash = malloc(sizeof(t_fd_stash));
	if (!current -> fd_stash)
		return (free(current), NULL);
	while (updated_stash -> next != NULL)
		updated_stash = updated_stash -> next;
	current -> fd_stash -> fd = fd;
	current -> fd_stash -> buffer = malloc(1);
	if (!(current -> fd_stash -> buffer))
		return (free(current -> fd_stash), NULL);
	*(current -> fd_stash -> buffer) = '\0';
	current -> next = NULL;
	updated_stash -> next = current;
	return (updated_stash -> next);
}

t_fd_stash_list	*ft_read_file(t_fd_stash_list **stash, int fd)
{
	ssize_t			read_bytes;
	char			*temp_buffer;
	char			*stash_buffer;
	t_fd_stash_list	*curr_fd_stash;

	curr_fd_stash = ft_handle_fd(stash, fd);
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	temp_buffer[0] = '\0';
	stash_buffer = curr_fd_stash -> fd_stash -> buffer;
	read_bytes = 1;
	while (read_bytes && !ft_strchr(temp_buffer, '\n'))
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if ((read_bytes == 0 && *stash_buffer == '\0') || read_bytes == -1)
			return (ft_release_stash_list(stash, fd), free(temp_buffer), NULL);
		temp_buffer[read_bytes] = '\0';
		curr_fd_stash = ft_update_fd_stash(curr_fd_stash, temp_buffer, 0);
		stash_buffer = curr_fd_stash -> fd_stash -> buffer;
	}
	return (free(temp_buffer), *stash);
}

t_fd_stash_list	*ft_update_fd_stash(t_fd_stash_list *stash, char *buff, int len)
{
	char			*old_buffer;
	char			*updated_buffer;
	t_fd_stash_list	*curr_fd_stash;

	curr_fd_stash = stash;
	old_buffer = curr_fd_stash -> fd_stash -> buffer;
	updated_buffer = ft_strjoin(old_buffer + len, buff);
	free(curr_fd_stash -> fd_stash -> buffer);
	curr_fd_stash -> fd_stash -> buffer = NULL;
	curr_fd_stash -> fd_stash -> buffer = ft_strjoin(updated_buffer, "");
	free(updated_buffer);
	updated_buffer = NULL;
	return (stash);
}

char	*ft_get_line(t_fd_stash_list *stash)
{
	char	*line;
	char	*buffer;
	int		len;

	buffer = stash -> fd_stash -> buffer;
	if (ft_strchr(buffer, '\n'))
		len = ft_strlen(buffer) - ft_strlen(ft_strchr(buffer, '\n')) + 1 ;
	else
		len = ft_strlen(buffer);
	line = ft_substr(buffer, 0, len);
	return (line);
}

void	ft_release_stash_list(t_fd_stash_list **stash, int fd)
{
	t_fd_stash_list	*last;
	t_fd_stash_list	*current;

	current = *stash;
	last = *stash;
	if (current -> fd_stash -> fd == fd)
	{
		*stash = current -> next;
		return (free(current -> fd_stash -> buffer),
			free(current -> fd_stash), free(current));
	}
	while (current != NULL)
	{
		if (current -> fd_stash -> fd == fd)
		{
			last -> next = current -> next;
			return (free(current -> fd_stash -> buffer),
				free(current -> fd_stash), free(current));
		}
		if (current -> next -> fd_stash -> fd != fd)
		{
			current = current -> next;
			last = current;
		}
		else
			current = current -> next;
	}
}
