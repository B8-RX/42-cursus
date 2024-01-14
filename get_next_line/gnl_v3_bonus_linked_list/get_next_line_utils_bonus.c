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

t_stash_list	*ft_init_stash(t_stash_list **stash, int fd)
{
	t_stash_list	*new;

	new = malloc(sizeof(t_stash_list));
	if (!new)
		return (NULL);
	new -> fd_stash = malloc(sizeof(t_fd_stash));
	if (!new -> fd_stash)
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	new -> fd_stash -> fd = fd;
	new -> fd_stash -> buffer = malloc(1);
	if (!(new -> fd_stash -> buffer))
	{
		free(new -> fd_stash);
		free(new);
		new = NULL;
		return (NULL);
	}
	*(new -> fd_stash -> buffer) = '\0';
	new -> next = NULL;
	*stash = new;
	return (*stash);
}

t_stash_list	*ft_create_file_stash(t_stash_list **stash, int fd)
{
	t_stash_list	*current;
	t_stash_list	*updated_stash;

	updated_stash = *stash;
	current = malloc(sizeof(t_stash_list));
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
		return (free(current -> fd_stash), free(current), NULL);
	*(current -> fd_stash -> buffer) = '\0';
	current -> next = NULL;
	updated_stash -> next = current;
	return (updated_stash -> next);
}

char	*ft_get_line(t_stash_list *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (ft_strchr(stash -> fd_stash -> buffer, '\n'))
	{
		while ((stash -> fd_stash -> buffer)[i] != '\n')
			i++;
		i++;
	}
	else
		while ((stash -> fd_stash -> buffer)[i])
			i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while ((stash -> fd_stash -> buffer)[j] && j < i)
	{
		line[j] = (stash -> fd_stash -> buffer)[j];
		j++;
	}
	line[j] = '\0';
	return (line);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	new = (char *)malloc((i + j + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[i++] = s2[j];
	new[i] = '\0';
	return (new);
}
