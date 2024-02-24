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
	static t_stash_list	*Stash;
	t_stash_list			*Current_fd;
	char				*line;

	if (fd < 0 || !BUFFER_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!Stash && !ft_init_stash(&Stash, fd))
		return (NULL);	
	Current_fd = ft_get_file_stash(&Stash, fd);
	if (!Current_fd)
		return (NULL);
	if (!ft_read_file(&Stash, fd))
		return (NULL);
	line = ft_get_line(Current_fd);
	Current_fd = ft_update_stash(&Current_fd, "", ft_strlen(line));
	return (line);
}

t_stash_list	*ft_update_stash(t_stash_list **Stash, char *buff, int line_lengh)
{
	char		*old_buffer;
	char		*updated_buffer;
	t_stash_list	*Current_fd;

	Current_fd = *Stash;
	old_buffer =  Current_fd -> fd_stash -> buffer;
	updated_buffer = ft_strjoin(old_buffer + line_lengh, buff); 
	
	free(Current_fd -> fd_stash -> buffer);
	Current_fd -> fd_stash -> buffer = NULL;
	Current_fd -> fd_stash -> buffer = ft_strjoin(updated_buffer, "");
	free(updated_buffer);
	updated_buffer = NULL;
	return (*Stash);
}

char	*ft_get_line(t_stash_list *Stash)
{
	char	*line;
	char	*buffer;
	int		len;

	buffer = Stash -> fd_stash -> buffer;
	if (ft_strchr(buffer, '\n'))
		len = ft_strlen(buffer) - ft_strlen(ft_strchr(buffer, '\n')) + 1 ;
	else
		len = ft_strlen(buffer);
	line = ft_substr(buffer, 0, len);
	return (line);
}

t_stash_list	*ft_read_file(t_stash_list **Stash, int fd)
{
	ssize_t		read_bytes;
	char		*temp_buffer;
	char		*temp_stash;
	t_stash_list	*Current_fd;

	Current_fd = ft_get_file_stash(Stash, fd); 
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	temp_buffer[0]= '\0';
	temp_stash = Current_fd -> fd_stash -> buffer; 
	read_bytes = 1;
	while (read_bytes && !ft_strchr(temp_buffer, '\n'))
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if ((read_bytes == 0 
			&&	*temp_stash == '\0')
			||	read_bytes == -1)
		{
			free(temp_buffer);
			temp_buffer = NULL;
			while (!ft_release_file_stash(Stash, fd))
				ft_release_file_stash(Stash, fd);
			return (NULL);
		}
		temp_buffer[read_bytes] = '\0';
		Current_fd = ft_update_stash(&Current_fd, temp_buffer, 0);
		temp_stash = Current_fd -> fd_stash -> buffer;
	}
	free(temp_buffer);
	temp_buffer = NULL;
	return (*Stash);
}

t_stash_list	*ft_get_file_stash(t_stash_list **Stash, int fd)
{
	t_stash_list	*Current;

	if (!*Stash)
		return (NULL);
	Current = *Stash;
	while (Current != NULL)
	{
		if (Current -> fd_stash -> fd == fd)
			return (Current);
		Current = Current -> next;
	}
	return (ft_create_file_stash(Stash, fd));
}

t_stash_list	*ft_create_file_stash(t_stash_list **Stash, int fd)
{
	t_stash_list	*Current;
	t_stash_list	*Updated_Stash;

	Updated_Stash = *Stash;
	Current = malloc(sizeof(t_stash_list));
	if (!Current)
		return (NULL);
	Current -> fd_stash = malloc(sizeof(t_fd_stash));
	if (!Current -> fd_stash)
	{
		free(Current);
		Current = NULL;
		return (NULL);
	}
	while (Updated_Stash -> next != NULL)
		Updated_Stash = Updated_Stash -> next;
	Current -> fd_stash -> fd = fd;
	Current -> fd_stash -> buffer = malloc(1);
	if (!(Current -> fd_stash -> buffer))
	{
		free(Current -> fd_stash);
		free(Current);
		Current = NULL;
		return (NULL);
	}
	*(Current -> fd_stash -> buffer) = '\0';
	Current -> next = NULL;
	Updated_Stash -> next = Current;
	return (Updated_Stash -> next);
}

int	ft_release_file_stash(t_stash_list **Stash, int fd)
{
	t_stash_list	*last;
	t_stash_list	*Current;
	Current = *Stash;
	last = *Stash;
	if (Current -> fd_stash -> fd == fd)
	{
		*Stash = Current -> next;
		free(Current -> fd_stash -> buffer);
		free(Current -> fd_stash);
		free(Current);
		Current = NULL;
		return (1);
	}
	while (Current != NULL)
	{
		if (Current -> fd_stash -> fd == fd)
		{
			last -> next = Current -> next;
			free(Current -> fd_stash -> buffer);
			free(Current -> fd_stash);
			free(Current);
			Current = NULL;
			return (1);
		}
		if (Current -> next -> fd_stash -> fd != fd)
		{
			Current = Current -> next;
			last = Current;
		}
		else
			Current = Current -> next;
	}
	return (-1);
}

t_stash_list	*ft_init_stash(t_stash_list **Stash, int fd)
{
	t_stash_list	*New;
	
	New = malloc(sizeof(t_stash_list));
	if (!New)
		return (NULL);
	New -> fd_stash = malloc(sizeof(t_fd_stash));
	if (!New -> fd_stash)
	{
		free(New);
		New = NULL;
		return (NULL);
	}
	New -> fd_stash -> fd = fd;
	New -> fd_stash -> buffer = malloc(1);
	if (!(New -> fd_stash -> buffer))
	{
		free(New -> fd_stash);
		free(New);
		New = NULL;
		return (NULL);
	}
	*(New -> fd_stash -> buffer) = '\0';
	New -> next = NULL;
	*Stash = New;
	return  (*Stash);
}
