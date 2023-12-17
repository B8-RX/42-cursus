/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:31:22 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/16 02:31:24 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nb, size_t n)
{
	void	*new;
	size_t	i;
	size_t	total;

	if (n && nb > (size_t)(-1) / n)
		return (NULL);
	total = nb * n;
	new = malloc(total);
	if (!new)
		return (NULL);
	i = 0;
	while (i < total)
	{
		((unsigned char *)new)[i] = 0;
		i++;
	}
	return (new);
}
