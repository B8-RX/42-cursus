/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:09:12 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/10 20:09:17 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/libftprintf.h"

int	main(void)
{
	int	count_ft_printf = 0;
	int	count_printf = 0;
	
//------------------------------test char--------------------------------//

	// char	c = 'z';	
	// count_ft_printf = ft_printf("|%c|\n", c);
	// ft_printf("result ft_printf:|%d|\n", count_ft_printf); 

	//---- test with original printf function------//
	
	// count_printf = printf("|%c|\n", c);
	// printf("result printf :|%d|\n", count_printf);


//------------------------------test string--------------------------------//
	
	// char	str[] = "test 1 2 3 abracadabra";
	// count_ft_printf = ft_printf("|%s|\n", str); // test string
	// ft_printf("result ft_printf:|%d|\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("|%s|\n", str);
	// printf("result printf :|%d|\n", count_printf);



//------------------------------test INT_MIN--------------------------------//
	
	// int		int_min = -2147483648;
	// count_ft_printf = ft_printf("|%d|\n", int_min); // test INT_MIN
	// ft_printf("result ft_printf:|%d|\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("|%d|\n", int_min);
	// printf("result printf :|%d|\n", count_printf);

//------------------------------test INT_MAX--------------------------------//
	
	// int		int_max = 2147483647;
	// count_ft_printf = ft_printf("|%d|\n", int_max); // test INT_MAX
	// ft_printf("result ft_printf:|%d|\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("|%d|\n", int_max);
	// printf("result printf :|%d|\n", count_printf);

//------------------------------test positive num--------------------------------//
	
	// int		nbr_positive = 42;
	// count_ft_printf = ft_printf("|%d|\n", nbr_positive); // test positive num
	// ft_printf("result ft_printf:|%d|\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("|%d|\n", nbr_positive);
	// printf("result printf :|%d|\n", count_printf);

//------------------------------test negative num--------------------------------//
	
	// int		nbr_negative = -421154562;
	// count_ft_printf = ft_printf("|%d|\n", nbr_negative); // test negative num
	// ft_printf("result ft_printf:|%d|\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("|%d|\n", nbr_negative);
	// printf("result printf :|%d|\n", count_printf);

//------------------------------test unsigned int--------------------------------//
	
	// int		nbr_unsigned = 42;
	// count_ft_printf = ft_printf("|%u|\n", nbr_unsigned); // test unsigned int
	// ft_printf("result ft_printf:|%d|\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("|%u|\n", nbr_unsigned);
	// printf("result printf :|%d|\n", count_printf);

//------------------------------test hexa lower--------------------------------//
	
	// int		nbr_positive = 42;
	// count_ft_printf = ft_printf("|%x|\n", nbr_positive); // test hexa lower case
	// ft_printf("result ft_printf:|%d|\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("|%x|\n", nbr_positive);
	// printf("result printf :|%d|\n", count_printf);

//------------------------------test hexa upper--------------------------------//
	
	// int		nbr_positive = 42;
	// count_ft_printf = ft_printf("|%X|\n", nbr_positive); // test hexa upper case
	// ft_printf("result ft_printf:|%d|\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("|%X|\n", nbr_positive);
	// printf("result printf :|%d|\n", count_printf);

//------------------------------test pointer--------------------------------//

	// int		nbr_positive = 42;
	// int		*ptr = &nbr_positive;
	// count_ft_printf = ft_printf("|%p|\n", ptr); // test pointer	
	// ft_printf("result ft_printf:|%d|\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("|%p|\n", ptr);
	// printf("result printf :|%d|\n", count_printf);


//------------------------------test %%--------------------------------//
	count_ft_printf = ft_printf("|%%|\n");
	ft_printf("result ft_printf: |%d|\n", count_ft_printf);

	count_printf = printf("|%%|\n");
	printf("result printf: |%d|\n", count_printf);
	return (0);
}
