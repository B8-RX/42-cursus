
#include "get_next_line_bonus.h"

int	main(void)
{
<<<<<<< HEAD
<<<<<<< HEAD
	// int		fd1;
	// int		fd2;
=======
	int		fd1;
	int		fd2;
>>>>>>> b7d415a (gnl_bonus: work on the ft_read_file branch. When initializing stash fd, assign an empty string to buffer fd. Todo: in ft_read_file function check that the linked lists have not lost a link when a list is freed.)
=======
	int		fd1;
	int		fd2;
>>>>>>> b7d415a (gnl_bonus: work on the ft_read_file branch. When initializing stash fd, assign an empty string to buffer fd. Todo: in ft_read_file function check that the linked lists have not lost a link when a list is freed.)
	int		fd3;
	char	*line;
	int		i;

<<<<<<< HEAD
<<<<<<< HEAD
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
=======
=======
>>>>>>> b7d415a (gnl_bonus: work on the ft_read_file branch. When initializing stash fd, assign an empty string to buffer fd. Todo: in ft_read_file function check that the linked lists have not lost a link when a list is freed.)
	i = 0;
	fd1 = open("../../tests_GNL/my_tests_gnl/fable_small.txt", O_RDONLY);
	fd2 = open("../../tests_GNL/my_tests_gnl/file_test_nl.txt", O_RDONLY);
	fd3 = open("../../tests_GNL/my_tests_gnl/file_test_no_nl.txt", O_RDONLY);

<<<<<<< HEAD
>>>>>>> b7d415a (gnl_bonus: work on the ft_read_file branch. When initializing stash fd, assign an empty string to buffer fd. Todo: in ft_read_file function check that the linked lists have not lost a link when a list is freed.)
	 
	line = get_next_line(fd1);
	printf("result %d: |%s|\n\n", ++i, line); // 1
	// free(line);
	
	line = get_next_line(fd2);
	printf("result %d: |%s|\n\n", ++i, line); // 2
	// free(line);
	
	line = get_next_line(fd3);
	printf("result %d: |%s|\n\n", ++i, line); // 3
	// free(line);
	
	line = get_next_line(fd1);
<<<<<<< HEAD
<<<<<<< HEAD
	printf("result 1: %s\n\n", line);
	line = get_next_line(fd2);
	printf("result 2: %s\n\n", line);
<<<<<<< HEAD
>>>>>>> d3ac247 (gnl_bonus: update the linked list in ft_check_fd_stash function, free memory, freeing linked_list if ft_check_fd_stash function return NULL)
=======
	printf("result %d: %s\n\n", ++i, line); // 4
=======
	printf("result %d: |%s|\n\n", ++i, line); // 4
>>>>>>> 57db75a (gnl_bonus: work on the ft_read_file branch. Buffer update on each call is implemented. To do: cut and update the buffer, keeping the part after the linefeed if a linefeed is found during reading.)
=======
=======
	 
	line = get_next_line(fd1);
	printf("result %d: %s\n\n", ++i, line); // 1
	// free(line);
	
	line = get_next_line(fd2);
	printf("result %d: %s\n\n", ++i, line); // 2
	// free(line);
	
>>>>>>> b7d415a (gnl_bonus: work on the ft_read_file branch. When initializing stash fd, assign an empty string to buffer fd. Todo: in ft_read_file function check that the linked lists have not lost a link when a list is freed.)
	line = get_next_line(fd3);
	printf("result %d: %s\n\n", ++i, line); // 3
	// free(line);
	
	line = get_next_line(fd1);
<<<<<<< HEAD
	printf("result 1: %s\n\n", line);
	line = get_next_line(fd2);
	printf("result 2: %s\n\n", line);
>>>>>>> d3ac247 (gnl_bonus: update the linked list in ft_check_fd_stash function, free memory, freeing linked_list if ft_check_fd_stash function return NULL)
=======
	printf("result %d: %s\n\n", ++i, line); // 4
	// free(line);

	line = get_next_line(fd1);
	printf("result %d: %s\n\n", ++i, line); // 5
	// free(line);
	// 
	// line = get_next_line(fd3);
	// printf("result %d: %s\n\n", ++i, line); // 6
	// // free(line);
	// 
	// line = get_next_line(fd1);
	// printf("result %d: %s\n\n", ++i, line); // 7
	// // free(line);
	// 
	// line = get_next_line(fd2);
	// printf("result %d: %s\n\n", ++i, line); // 8
>>>>>>> b7d415a (gnl_bonus: work on the ft_read_file branch. When initializing stash fd, assign an empty string to buffer fd. Todo: in ft_read_file function check that the linked lists have not lost a link when a list is freed.)
	// free(line);

	line = get_next_line(fd3);
	printf("result %d: |%s|\n\n", ++i, line); // 5
	// free(line);
	// 
	// line = get_next_line(fd3);
	// printf("result %d: |%s|\n\n", ++i, line); // 6
	// // free(line);
	// 
	// line = get_next_line(fd1);
	// printf("result %d: |%s|\n\n", ++i, line); // 7
	// // free(line);
	// 
	// line = get_next_line(fd2);
<<<<<<< HEAD
	// printf("result %d: %s\n\n", ++i, line); // 8
>>>>>>> b7d415a (gnl_bonus: work on the ft_read_file branch. When initializing stash fd, assign an empty string to buffer fd. Todo: in ft_read_file function check that the linked lists have not lost a link when a list is freed.)
=======
	// printf("result %d: |%s|\n\n", ++i, line); // 8
>>>>>>> 57db75a (gnl_bonus: work on the ft_read_file branch. Buffer update on each call is implemented. To do: cut and update the buffer, keeping the part after the linefeed if a linefeed is found during reading.)
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
