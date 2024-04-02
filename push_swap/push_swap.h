#include <stdio.h>

typedef struct stack_a {
	int	nbr;
	struct stack_a	previous;
	struct stack_a	next;
} t_stack_a;

typedef struct stack_b {
	int	nbr;
	struct stack_b	previous;
	struct stack_b	next;
} t_stack_b;


