/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:03:11 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/30 16:03:14 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE__BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif // !BUFFER_SIZE

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct Fd_buffer {
	int		fd;
	char	*buffer;
}

typedef struct Base_stash {
	Fd_stash			*Fd_buffer;
	struct Base_stash	*next;
}

char		*get_next_line(int fd);
Base_stash	*ft_init_stash(int fd);


#endif // !GET_NEXT_LINE_H
