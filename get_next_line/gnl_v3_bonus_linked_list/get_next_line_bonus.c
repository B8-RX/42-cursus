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
	static Stash_list	*Stash;
	Stash_list			*Current_fd;
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

Stash_list	*ft_update_stash(Stash_list **Stash, char *buff, int line_lengh)
{
	char		*old_buffer;
	char		*updated_buffer;
	Stash_list	*Current_fd;

	Current_fd = *Stash;
	old_buffer =  Current_fd -> Fd_stash -> buffer;
	updated_buffer = ft_strjoin(old_buffer + line_lengh, buff); 
	
	free(Current_fd -> Fd_stash -> buffer);
	Current_fd -> Fd_stash -> buffer = NULL;
	Current_fd -> Fd_stash -> buffer = ft_strjoin(updated_buffer, "");
	free(updated_buffer);
	updated_buffer = NULL;
	return (*Stash);
}

char	*ft_get_line(Stash_list *Stash)
{
	char	*line;
	char	*buffer;
	int		len;

	buffer = Stash -> Fd_stash -> buffer;
	if (ft_strchr(buffer, '\n'))
		len = ft_strlen(buffer) - ft_strlen(ft_strchr(buffer, '\n')) + 1 ;
	else
		len = ft_strlen(buffer);
	line = ft_substr(buffer, 0, len);
	return (line);
}

Stash_list	*ft_read_file(Stash_list **Stash, int fd)
{
	ssize_t		read_bytes;
	char		*temp_buffer;
	char		*temp_stash;
	Stash_list	*Current_fd;

	Current_fd = ft_get_file_stash(Stash, fd); 
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	temp_buffer[0]= '\0';
	temp_stash = Current_fd -> Fd_stash -> buffer; 
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
		temp_stash = Current_fd -> Fd_stash -> buffer;
	}
	free(temp_buffer);
	temp_buffer = NULL;
	return (*Stash);
}

Stash_list	*ft_get_file_stash(Stash_list **Stash, int fd)
{
	Stash_list	*Current;

	if (!*Stash)
		return (NULL);
	Current = *Stash;
	while (Current != NULL)
	{
		if (Current -> Fd_stash -> fd == fd)
			return (Current);
		Current = Current -> next;
	}
	return (ft_create_file_stash(Stash, fd));
}

Stash_list	*ft_create_file_stash(Stash_list **Stash, int fd)
{
	Stash_list	*Current;
	Stash_list	*Updated_Stash;

	Updated_Stash = *Stash;
	Current = malloc(sizeof(Stash_list));
	if (!Current)
		return (NULL);
	Current -> Fd_stash = malloc(sizeof(Fd_stash));
	if (!Current -> Fd_stash)
	{
		free(Current);
		Current = NULL;
		return (NULL);
	}
	while (Updated_Stash -> next != NULL)
		Updated_Stash = Updated_Stash -> next;
	Current -> Fd_stash -> fd = fd;
	Current -> Fd_stash -> buffer = malloc(1);
	if (!(Current -> Fd_stash -> buffer))
	{
		free(Current -> Fd_stash);
		free(Current);
		Current = NULL;
		return (NULL);
	}
	*(Current -> Fd_stash -> buffer) = '\0';
	Current -> next = NULL;
	Updated_Stash -> next = Current;
	return (Updated_Stash -> next);
}

int	ft_release_file_stash(Stash_list **Stash, int fd)
{
	Stash_list	*last;
	Stash_list	*Current;
	Current = *Stash;
	last = *Stash;
	if (Current -> Fd_stash -> fd == fd)
	{
		*Stash = Current -> next;
		free(Current -> Fd_stash -> buffer);
		free(Current -> Fd_stash);
		free(Current);
		Current = NULL;
		return (1);
	}
	while (Current != NULL)
	{
		if (Current -> Fd_stash -> fd == fd)
		{
			last -> next = Current -> next;
			free(Current -> Fd_stash -> buffer);
			free(Current -> Fd_stash);
			free(Current);
			Current = NULL;
			return (1);
		}
		if (Current -> next -> Fd_stash -> fd != fd)
		{
			Current = Current -> next;
			last = Current;
		}
		else
			Current = Current -> next;
	}
	return (-1);
}

Stash_list	*ft_init_stash(Stash_list **Stash, int fd)
{
	Stash_list	*New;
	
	New = malloc(sizeof(Stash_list));
	if (!New)
		return (NULL);
	New -> Fd_stash = malloc(sizeof(Fd_stash));
	if (!New -> Fd_stash)
	{
		free(New);
		New = NULL;
		return (NULL);
	}
	New -> Fd_stash -> fd = fd;
	New -> Fd_stash -> buffer = malloc(1);
	if (!(New -> Fd_stash -> buffer))
	{
		free(New -> Fd_stash);
		free(New);
		New = NULL;
		return (NULL);
	}
	*(New -> Fd_stash -> buffer) = '\0';
	New -> next = NULL;
	*Stash = New;
	return  (*Stash);
}
