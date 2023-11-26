/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 04:08:27 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/26 07:11:04 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_childs(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			while (s[i] == c)
		i++;
	}
	return (j);
}

int	ft_memset_childs(char **parent, int nb_childs, const char *s, char c)
{
	int		index;
	int		str_len;
	size_t	child_len;
	int		i;

	index = 0;
	str_len = ft_strlen(s);
	i = 0;
	while (str_len > 0)
	{
		child_len = 0;
		while (s[i] == c && str_len)
		{
			i++;
			str_len--;
		}
		while (*(s + (i + child_len)) != c && str_len)
		{
			child_len++;
			str_len--;
		}
		if (index < nb_childs)
		{
			parent[index] = (char *)malloc((child_len + 1) * sizeof(char));
			if (!parent[index])
			{
				while ((index + 1) > 0)
				{
					free(parent[index]);
					index--;
				}
				free(parent);
			}
			ft_strlcpy(parent[index], s + i, child_len + 1);
			index++;
		}
		i += child_len;
	}
	parent[nb_childs] = 0;
	return (index);
}

char	**ft_split(const char *s, char c)
{
	char	**parent;
	int		nb_childs;

	parent = NULL;
	if (!s)
		return (NULL);
	nb_childs = ft_count_childs(s, c);
	parent = (char **) malloc(sizeof(char *) * (nb_childs + 1));
	if (!parent)
		return (parent);
	ft_memset_childs(parent, nb_childs, s, c);
	return (parent);
}
