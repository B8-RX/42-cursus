#include <stdio.h>
#include <stdarg.h>
#include <unistdio.h>

typedef struct list 
{
	

}

int	main(void)
{
//	int		arg1;
	char	arg2[] = "test";
	int		count;

//	arg1 = 5;
	count = ft_printf("%c", 'z');
	ft_printf("result :%d\n", count);
	return (0);
}
