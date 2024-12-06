/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:40:13 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/02 14:37:06 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	enemy_loc(char **map)
{
	int			j;
	int			i;
	t_enemy		enemy;

	i = 0;
	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\n')
		{
			if (map[j][i] == 'X')
			{
				enemy.x = i;
				enemy.y = j;
			}
			i++;
		}
		j++;
	}
	return (enemy);
}

int	move_enemy(t_windowvar *p)
{
	static int	timer;

	if (timer <= 10)
	{
		change_image(*p, 0);
		timer++;
	}
	else if (timer <= 20)
		timer++;
	else if (timer <= 30)
	{
		change_image(*p, 1);
		timer++;
	}
	else if (timer < 40)
		timer++;
	else if (timer == 40)
		timer = 0;
	return (0);
}

void	put_empty(t_windowvar mlx, int i, int j)
{
	mlx.i = mlx_xpm_file_to_image(mlx.p,
			"tileset/empty.xpm", &mlx.width, &mlx.height);
	if (!mlx.i)
		free_pointer(mlx.i, mlx);
	mlx_put_image_to_window(mlx.p, mlx.w, mlx.i, i * 60, j * 60);
}

void	*put_image(t_windowvar mlx, int eflag)
{
	if (eflag == 0)
		mlx.i = mlx_xpm_file_to_image(mlx.p,
				"tileset/walkingtom.xpm", &mlx.width, &mlx.height);
	else if (eflag == 1)
		mlx.i = mlx_xpm_file_to_image(mlx.p,
				"tileset/walkingtom2.xpm", &mlx.width, &mlx.height);
	return (mlx.i);
}

void	change_image(t_windowvar mlx, int eflag)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (j < count_lines(mlx.map))
	{
		i = 0;
		while (i < ft_strlen(mlx.map[j]))
		{
			if (mlx.map[j][i] == 'X')
			{
				put_empty(mlx, i, j);
				mlx.i = put_image(mlx, eflag);
				if (!mlx.i)
					free_pointer(mlx.i, mlx);
				mlx_put_image_to_window(mlx.p, mlx.w, mlx.i, i * 60, j * 60);
			}
			i++;
		}
		j++;
	}
}
