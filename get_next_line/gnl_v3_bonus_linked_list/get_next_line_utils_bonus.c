/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:03:35 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/30 16:03:36 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_fd_stash_list	*ft_init_stash(t_fd_stash_list **stash, int fd)
{
	t_fd_stash_list	*new;

	new = malloc(sizeof(t_fd_stash_list));
	if (!new)
		return (NULL);
	new->fd_stash = malloc(sizeof(t_fd_stash));
	if (!new->fd_stash)
		return (free(new), NULL);
	new->fd_stash->fd = fd;
	new->fd_stash->buffer = malloc(1);
	if (!(new->fd_stash->buffer))
		return (free(new->fd_stash), free(new), NULL);
	*(new->fd_stash->buffer) = '\0';
	new->next = NULL;
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
		if (current->fd_stash->fd == fd)
			return (current);
		current = current->next;
	}
	return (ft_create_file_stash(stash, fd));
}

void	ft_release_stash_list(t_fd_stash_list **stash, int fd)
{
	t_fd_stash_list	*last;
	t_fd_stash_list	*current;

	current = *stash;
	last = *stash;
	if (current->fd_stash->fd == fd)
	{
		*stash = current->next;
		return (free(current->fd_stash->buffer),
			free(current->fd_stash), free(current));
	}
	while (current != NULL)
	{
		if (current->fd_stash->fd == fd)
		{
			last->next = current->next;
			return (free(current->fd_stash->buffer),
				free(current->fd_stash), free(current));
		}
		current = current->next;
		if (last->next->fd_stash->fd != fd)
			last = current;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	new = (char *)malloc((i + j + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		new[i++] = s2[j];
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(char *s, int c)
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
