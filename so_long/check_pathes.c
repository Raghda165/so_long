/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pathes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:54:13 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/02 10:35:57 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char **map)
{
	int	j;

	j = 0;
	while (map[j] != NULL)
	{
		j++;
	}
	return (j);
}

char	**tmp_map(char **map)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = malloc(sizeof(char *) * (count_lines(map) + 1));
	while (map[j] != NULL)
	{
		tmp[j] = ft_strdup(map[j]);
		j++;
	}
	tmp[j] = NULL;
	return (tmp);
}

int	count_c(char **map)
{
	int	j;
	int	i;
	int	c;

	i = 0;
	j = 0;
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

int	check_pathes(char **map, char **tmp, int i, int j)
{
	static int	c;
	static int	e;

	if ((j >= 0 && j < count_lines(map))
		&& ((i >= 0 && (size_t)i < (ft_strlen(map[0]) - 2))))
	{
		if (tmp[j][i] == '1')
			return (0);
		if (tmp[j][i] == 'C')
			c++;
		if (tmp[j][i] == 'E')
			e++;
		tmp[j][i] = '1';
		check_pathes (map, tmp, i, j + 1);
		check_pathes(map, tmp, i, j - 1);
		check_pathes(map, tmp, i - 1, j);
		check_pathes(map, tmp, i + 1, j);
	}
	if (c != count_c(map) && e != 1)
		return (0);
	else
		return (1);
}
