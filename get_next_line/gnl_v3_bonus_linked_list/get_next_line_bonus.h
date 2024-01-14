/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:03:11 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/30 16:03:14 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55 
# endif // !BUFFER_SIZE

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct Fd_stash
{
	int		fd;
	char	*buffer;
}	t_fd_stash;

typedef struct Base_stash
{
	t_fd_stash			*fd_stash;
	struct Base_stash	*next;
}	t_stash_list;

char			*get_next_line(int fd);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_get_line(t_stash_list *Stash);
void			*ft_release_file_stash(t_stash_list **Stash, int fd);
t_stash_list	*ft_init_stash(t_stash_list **Stash, int fd);
t_stash_list	*ft_create_file_stash(t_stash_list **Stash, int fd);
t_stash_list	*ft_get_file_stash(t_stash_list **Stash, int fd);
t_stash_list	*ft_read_file(t_stash_list **Stash, int fd);
t_stash_list	*ft_update_stash(t_stash_list **Stash, char *buff, int len);

#endif // !GET_NEXT_LINE_H
