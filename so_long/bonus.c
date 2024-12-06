/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:28:28 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/02 20:40:22 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *str)
{
	int		fd;

	fd = 0;
	if (ft_strncmp(ft_strnstr(str + (ft_strlen(str) - 4)
				, ".ber", 4), ".ber", 4) == 0)
	{
		fd = open(str, O_RDONLY);
		if (fd < 0)
		{
			write(2, "Error\n", 7);
			write(2, "The file of the map does not exist\n", 36);
			exit(EXIT_FAILURE);
		}
		return (fd);
	}
	else
	{
		write(2, "Error\n", 7);
		exit(1);
	}
}

t_map	create_map_dim(int fd)
{
	int		j;
	char	*line;
	t_map	map;

	j = 0;
	line = NULL;
	while (line || j == 0)
	{
		line = get_next_line(fd);
		if (line == NULL && j == 0)
		{
			free(line);
			write(2, "Error\n", 7);
			write(2, "The file is empty\n", 19);
			close(fd);
			exit(EXIT_FAILURE);
		}
		if (j == 0)
			map.width = ft_strlen(line) - 1;
		free(line);
		j++;
	}
	map.height = j - 1;
	close(fd);
	return (map);
}

char	**create_map(int fd, char *str)
{
	int		j;
	int		i;
	char	**map;
	t_map	dim;
	char	*line;

	i = open_file(str);
	j = 0;
	line = NULL;
	dim = create_map_dim(fd);
	map = malloc(sizeof(char *) * (dim.height + 1));
	while (line || j == 0)
	{
		line = get_next_line(i);
		map[j] = line;
		j++;
	}
	close (i);
	return (map);
}

t_player	player_loc(char **map)
{
	int			j;
	int			i;
	t_player	player;

	i = 0;
	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\n')
		{
			if (map[j][i] == 'P')
			{
				player.x = i;
				player.y = j;
			}
			i++;
		}
		j++;
	}
	return (player);
}

int	main(int ac, char **av)
{
	char		**map;
	char		**tmp_m;
	t_player	p;

	if (ac == 2)
	{
		map = create_map(open_file(av[1]), av[1]);
		tmp_m = tmp_map(map);
		p = player_loc(map);
		is_valid(map, tmp_m);
		check_player_and_exit(map, tmp_m);
		check_collectables(map, tmp_m);
		is_rectangular(map, tmp_m);
		check_walls(map, tmp_m, av[1]);
		if (!check_pathes(map, tmp_m, p.x, p.y))
			free_map(map, tmp_m, "there is not a valid path\n");
		else
			write(1, "there is a valid path\n", 23);
		freem(tmp_m);
		create_window(map, p.y, p.x);
	}
	write(2, "Error\n", 7);
	exit(1);
}
