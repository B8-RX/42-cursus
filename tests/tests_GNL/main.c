


#include "../../get_next_line/gnl_v2_single_static/get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;
	int		nb_line;

	nb_line = 0;
	fd = open("./fable_small.txt", O_RDONLY);	if (fd == -1)
		return (0);
	next_line = get_next_line(fd);
	while(next_line != NULL)
	{
		nb_line++;
		
		printf("\n==========================================================\n\n");
		printf("total lines |%d|:\n|%s|\n", nb_line, next_line);
		printf("\n==========================================================\n\n");	
		
		free(next_line);
		next_line = NULL;
		next_line = get_next_line(fd);
		if (next_line)
			printf("/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
		
	}
	free(next_line);
	close(fd);
	return (0);
}

