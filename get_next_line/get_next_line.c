/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:31:05 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/16 02:31:08 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char	*buff;
	size_t	lines_read;
	
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	lines_read = read(fd, buff, BUFFER_SIZE);

	return (buff);
}
