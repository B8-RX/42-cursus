
#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd;
	
	fd = open("../../tests_GNL/my_tests_gnl/fable_small.txt", O_RDONLY);
	
	printf("result: %s\n", get_next_line(fd));
	return (0);
}
