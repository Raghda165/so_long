/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:54:44 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/02 10:36:54 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)haystack;
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while ((needle[j] != '\0') && (str[i + j] != '\0') && (i < len)
		&& ((i + j) < len))
	{
		if (str[i + j] == needle[j])
			j++;
		else
		{
			i++;
			j = 0;
		}
	}
	if (needle[j] == '\0')
		return (str + i);
	else
		return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (1);
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < n) && (s1[i] == s2[i]))
	{
		i++;
	}
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	freem(char **map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		free(map[j]);
		j++;
	}
	free(map);
}

void	free_map(char **map, char **tmp_map, char *str )
{
	write(1, "Error\n", 7);
	write (1, str, ft_strlen(str));
	freem(map);
	freem(tmp_map);
	exit(1);
}

int	cheese_count(char **map)
{
	int	j;
	int	i;
	int	c;

	j = 0;
	i = 0;
	c = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\n')
		{
			if (map[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	return (c);
}
