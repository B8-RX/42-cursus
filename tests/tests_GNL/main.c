


#include <../get_next_line/get_next_line.h>

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("./fable.txt", O_RDONLY);
	next_line = get_next_line(fd);
	count++;
	printf("line [%d]:\n%s\n", count, next_line);
	next_line = NULL;

	close(fd);
	return (0);
}
