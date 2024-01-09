
#include "get_next_line_bonus.h"

int	main(void)
{
	// int		fd1;
	// int		fd2;
	int		fd3;
	char	*line;
	int		i;

	// fd1 = open("../../tests_GNL/my_tests_gnl/fable_small.txt", O_RDONLY);
	// fd2 = open("../../tests_GNL/my_tests_gnl/file_test_nl.txt", O_RDONLY);
	fd3 = open("../../tests_GNL/my_tests_gnl/file_test_no_nl.txt", O_RDONLY);
<<<<<<< HEAD
	//
	// line = get_next_line(fd1);
	// i = 0;
	// while (line != NULL)
	// {
	// 	printf("result %d: |%s|\n", ++i, line);
	// 	line = get_next_line(fd1);
	// }
	// free(line);	

	// i = 0;
	// line = get_next_line(fd1);
	// printf("result: %d: |%s|\n", ++i, line);
=======
	 
	line = get_next_line(fd1);
	printf("result 1: %s\n\n", line);
	line = get_next_line(fd2);
	printf("result 2: %s\n\n", line);
	line = get_next_line(fd3);
	printf("result 3: %s\n\n", line);
	line = get_next_line(fd3);
	printf("result 3: %s\n\n", line);
	line = get_next_line(fd2);
	printf("result 2: %s\n\n", line);
	line = get_next_line(fd3);
	printf("result 3: %s\n\n", line);
	line = get_next_line(fd1);
	printf("result 1: %s\n\n", line);
	line = get_next_line(fd2);
	printf("result 2: %s\n\n", line);
>>>>>>> d3ac247 (gnl_bonus: update the linked list in ft_check_fd_stash function, free memory, freeing linked_list if ft_check_fd_stash function return NULL)
	// free(line);
	// line = get_next_line(fd1);
	// printf("result %d: |%s|\n", ++i, line);
	// free(line);	
	// line = get_next_line(fd1);
	// printf("result %d: |%s|\n", ++i, line);
	// free(line);	
	
	// line = get_next_line(fd2);
	// i = 0;
	// while (line != NULL)
	// {
	// 	printf("line %d: |%s|\n", ++i, line);
	// 	line = get_next_line(fd2);
	// }
	// free(line);
	// 
	// i = 0;
	// line = get_next_line(fd1);
	// printf("result %d: |%s|\n", ++i, line);
	// free(line);	

	line = get_next_line(fd3);
	i = 0;
	while (line != NULL)
	{
		printf("line %d: |%s|\n", ++i, line);
		line = get_next_line(fd3);
	}
	free(line);

	// i = 0;
	// line = get_next_line(fd1);
	// printf("result %d: |%s|\n", ++i, line);
	// free(line);	
	
	return (0);
}
