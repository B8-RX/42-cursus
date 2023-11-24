/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 04:45:09 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/24 06:33:14 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *s, char c)
{
	int		len_str;
	int		j;
	int		k;
	char	*child;
	char	**parent;
	char	*strclone;

	strclone = (char *)s;
	len_str = ft_strlen(s);
	parent = NULL;
	j = 0;

// TODO FAIRE DES PRINTF DE CHILD ET DE PARENT[0]... pour voir si strlcpy marche bien
	
	k = 0;
	while (*strclone || *strclone == c)
	{
		while ((len_str - j >= 0) || *(strclone + j) != c)
			j++;
		if (*(strclone + j) == c)
		{
			child = malloc ((j + 1) * sizeof(char) + 1);
			if (child == NULL)
				return (NULL);
			else
			{
				ft_strlcpy(child, strclone, j + 1);
				*(parent + k) = (char *)malloc((j + 1) * sizeof(char) + 1);
				if (*(parent + k) == NULL)
					return (NULL);
				else
				{
					ft_strlcpy(*(parent + k), child, ft_strlen(child) + 1);
					free(child);
					k++;
				}
			}
			strclone += (j + 1);
		}
		len_str -= j;
		j = 0;
	}
	return (parent);	
}
	// 1 - loop on string s until char c is found or '\0' is found
	// 2 - take from the first index of the search to last one before char c
	// 3 - malloc a child array with the length of target plus null character, i.e (last index - first index + 1) + 1 ('\0')
	// 4 - malloc a parent array of arrays with the lenght of child + 1 ('\0') 
	// 5 - append child array to the parent array
	// 6 - free(child);
	// 7 - increament str s with length of previous match and repeat step 1	
	// return parent array i.e **array




