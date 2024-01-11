
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;
	int		i;

	i = 0;
	fd1 = open("../../tests_GNL/my_tests_gnl/fable_small.txt", O_RDONLY);
	fd2 = open("../../tests_GNL/my_tests_gnl/file_test_nl.txt", O_RDONLY);
	fd3 = open("../../tests_GNL/my_tests_gnl/file_test_no_nl.txt", O_RDONLY);

	 
	line = get_next_line(fd1);
	printf("result %d: |%s|\n\n", ++i, line); // 1
	free(line);
	
	line = get_next_line(fd2);
	printf("result %d: |%s|\n\n", ++i, line); // 2
	free(line);
	// 
	line = get_next_line(fd2);
	printf("result %d: |%s|\n\n", ++i, line); // 3
	free(line);
	
	line = get_next_line(fd2);
	printf("result %d: |%s|\n\n", ++i, line); // 4
	free(line);
	//
	// line = get_next_line(fd3);
	// printf("result %d: |%s|\n\n", ++i, line); // 5
	// // free(line);
	// // 
	// line = get_next_line(fd3);
	// printf("result %d: |%s|\n\n", ++i, line); // 6
	// // // free(line);
	// 
	line = get_next_line(fd1);
	printf("result %d: |%s|\n\n", ++i, line); // 7
	free(line);
	// 
	// line = get_next_line(fd2);
	// printf("result %d: |%s|\n\n", ++i, line); // 8
	// free(line);
	return (0);
}
