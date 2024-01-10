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
	Stash_list			*Current_fd_stash;

	if (fd < 0 || !BUFFER_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!Stash)
	{
		printf("FD %d NOT EXIST\n", fd);
		Stash = ft_init_stash(fd);
	}
	if (ft_check_fd_stash(&Stash, fd))
		Stash = ft_read_file(&Stash, fd);
	else
		return (NULL);
	Current_fd_stash = Stash;
	int i;

	i = 0;
	while (Current_fd_stash != NULL)
	{
		printf("list %d, fd : %d, buffer: |%s|\n", ++i, Current_fd_stash -> Fd_stash -> fd, Current_fd_stash -> Fd_stash -> buffer);
		Current_fd_stash = Current_fd_stash -> next;
	}
	return ("OK");
}

Stash_list	*ft_read_file(Stash_list **Stash, int fd)
{
	ssize_t		read_bytes;
	char		*temp_buffer;
	char		*stash_buffer;
	Stash_list	*Current_fd_stash;

	Current_fd_stash = ft_check_fd_stash(Stash, fd); 
	temp_buffer = malloc(sizeof(BUFFER_SIZE));
	if (!temp_buffer)
		return (NULL);
	stash_buffer = Current_fd_stash -> Fd_stash -> buffer;
	read_bytes = 1;
	while (read_bytes && !ft_strchr(temp_buffer, '\n'))
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if ((read_bytes == 0 
			&&	*stash_buffer == '\0')
			||	read_bytes == -1)
		{
			Stash_list	*temp_fd_stash;
			
			Current_fd_stash = *Stash;
			temp_fd_stash = Current_fd_stash;
			free(temp_buffer);
			while (Current_fd_stash != NULL)
			{
				if (Current_fd_stash -> Fd_stash -> fd == fd)
				{
					temp_fd_stash = Current_fd_stash -> next;
					free(Current_fd_stash -> Fd_stash -> buffer);
					free(Current_fd_stash -> Fd_stash);
					free(Current_fd_stash);
					return (NULL);
				}
				if (Current_fd_stash -> next -> Fd_stash -> fd != fd)
					temp_fd_stash = Current_fd_stash -> next;
				Current_fd_stash = Current_fd_stash -> next;
			}
			return (NULL);
		}
		temp_buffer[read_bytes] = '\0';
		stash_buffer = ft_strjoin(stash_buffer, temp_buffer);
	}
	Current_fd_stash -> Fd_stash -> buffer = ft_substr(stash_buffer, 0, ft_strlen(stash_buffer));
	return (*Stash);
}

Stash_list	*ft_check_fd_stash(Stash_list **Stash, int fd)
{
	Stash_list	*Current;
	Stash_list	*Updated_Stash;

	if (!*Stash)
		return (NULL);
	Current = *Stash;
	Updated_Stash = Current;
	while (Current != NULL)
	{
		if (Current -> Fd_stash -> fd == fd)
			break;
		Current = Current -> next;
	}
	if (!Current)
	{
		printf("FD %d NOT FOUND \n", fd);
		Current = malloc(sizeof(Stash_list));
		if (!Current)
			return (NULL);
		Current -> Fd_stash = malloc(sizeof(Fd_stash));
		if (!Current -> Fd_stash)
		{
			free(Current);
			return (NULL);
		}
		while (Updated_Stash -> next != NULL)
			Updated_Stash = Updated_Stash -> next;
		Current -> Fd_stash -> fd = fd;
		Current -> Fd_stash -> buffer = malloc(1);
		*(Current -> Fd_stash -> buffer) = '\0';
		Current -> next = NULL;
		Updated_Stash -> next = Current;
		printf("FD %d CREATED\n", fd);
	}
	return (Current);
}

Stash_list	*ft_init_stash(int fd)
{
	Stash_list	*New;

	New = malloc(sizeof(Stash_list));
	if (!New)
		return (NULL);
	New -> Fd_stash = malloc(sizeof(Fd_stash));
	if (!New -> Fd_stash)
	{
		free(New);
		return (NULL);
	}
	New -> Fd_stash -> fd = fd;
	New -> Fd_stash -> buffer = malloc(1);
	*(New -> Fd_stash -> buffer) = '\0';
	New -> next = NULL;
	printf("FD %d CREATED\n", fd);
	return  (New);
}


