/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:31:51 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/16 02:31:53 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;
	int		nb_line;

	nb_line = 0;
	fd = open("../../tests_GNL/my_tests_gnl/fable_small.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		nb_line++;
		printf("\n==========================================================\n\n");
		printf("total lines |%d|:\n|%s|\n", nb_line, next_line);
		printf("\n==========================================================\n\n");
		free(next_line);
		next_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
