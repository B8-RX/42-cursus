/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:03:11 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/30 16:03:14 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	char	*line;
	int		i;

	i = 0;
	fd1 = open("../../tests_GNL/my_tests_gnl/fable_small.txt", O_RDONLY);
	line = get_next_line(fd1);
	i = 0;
	while (line != NULL)
	{
		printf("line %d: |%s|\n", ++i, line);
		free(line);
		line = get_next_line(fd1);
	}
	return (0);
}
