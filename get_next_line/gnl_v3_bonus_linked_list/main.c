
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	char	*line;
	int		i;

	i = 0;
	fd1 = open("../../tests_GNL/my_tests_gnl/fable_small.txt", O_RDONLY);
	// fd2 = open("../../tests_GNL/my_tests_gnl/file_test_nl.txt", O_RDONLY);
	// fd3 = open("../../tests_GNL/my_tests_gnl/file_test_no_nl.txt", O_RDONLY);
	line = get_next_line(fd1);
	i = 0;
	while (line != NULL)
	{
		printf("line %d: |%s|\n", ++i, line);
		free(line);
		line = get_next_line(fd1);
	}
	// i = 0;
	// line = get_next_line(fd1);
	// printf("result %d: |%s|\n", ++i, line);
	// free(line);	
	
	return (0);
}
