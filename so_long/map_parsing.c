/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:39:16 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/02 17:38:45 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid(char **map, char **tmp_map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (map[j] != NULL)
	{
		i = 0;
		if (map[j][0] == '\n')
			free_map(map, tmp_map, "The map is not valid \n");
		while (map[j][i] != '\n')
		{
			if (map[j][i] == '1' || map[j][i] == '0' || map[j][i] == 'C'
				|| map[j][i] == 'E' || map[j][i] == 'P')
				i++;
			else
				free_map(map, tmp_map, "The map is not valid \n");
		}
		j++;
	}
	write(2, "The map is valid\n", 18);
}

void	check_player_and_exit(char **map, char **tmp_map)
{
	int	j;
	int	i;
	int	e;
	int	p;

	j = 0;
	i = 0;
	e = 0;
	p = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\n')
		{
			if (map[j][i] == 'E')
				e++;
			else if (map[j][i] == 'P')
				p++;
			i++;
		}
		j++;
	}
	if (e != 1 || p != 1)
		free_map(map, tmp_map, "the number of player or exit is not one\n");
	write(1, "There is one player and one exit\n", 33);
}

void	check_collectables(char **map, char **tmp_map)
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
	if (c < 1)
	{
		free_map(map, tmp_map, "there is no collectables to collect\n");
	}
	write(1, "The number of collectables is greater than zero\n", 49);
}

void	is_rectangular(char **map, char **tmp_map)
{
	int		j;
	size_t	width;

	j = 0;
	width = ft_strlen(map[0]);
	if (width > 43)
		free_map(map, tmp_map, "the map size is greater than the monitor\n");
	while (map[j] != NULL)
	{
		if (ft_strlen(map[j]) == width)
			j++;
		else
			free_map(map, tmp_map, "the map is not rectangular\n");
	}
	if (j > 24)
		free_map(map, tmp_map, "the map size is greater than the monitor\n");
	write(1, "The map is rectangualr\n", 24);
}

void	check_walls(char **map, char **tmp_map, char*str)
{
	int		j;
	size_t	i;
	t_map	dim;

	j = 0;
	dim = create_map_dim(open_file(str));
	while (map[j] != NULL)
	{
		if (j == 0 || j == dim.height - 1)
		{
			i = 0;
			while (map[j][i] != '\n')
			{
				if (map[j][i] == '1')
					i++;
				else
					free_map(map, tmp_map, "All the ends are not walls\n");
			}
		}
		else
			if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 2] != '1')
				free_map(map, tmp_map, "All the ends are not walls\n");
		j++;
	}
	write (1, "All the ends are walls\n", 24);
}
