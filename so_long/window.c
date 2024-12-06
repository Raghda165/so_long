/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:09:52 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/03 10:34:17 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all_and_exit(t_windowvar mlx, char *str)
{
	freem(mlx.map);
	ft_putstr_fd(str, 1);
	mlx_destroy_window(mlx.p, mlx.w);
	free(mlx.p);
	free(mlx.i);
	exit(EXIT_SUCCESS);
}

void	create_empty_space(t_windowvar mlx, int width, int height)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	mlx.i = mlx_xpm_file_to_image(mlx.p,
			"tileset/empty.xpm", &mlx.width, &mlx.height);
	if (!mlx.i)
		free_pointer(mlx.i, mlx);
	while (k < height)
	{
		l = 0;
		while (l < width)
		{
			mlx_put_image_to_window(mlx.p, mlx.w, mlx.i, l * 60, k * 60);
			l++;
		}
		k++;
	}
}

char	*return_file_name(char c, int dflag, int pflag)
{
	char	*name;

	if (c == 'P')
		name = "tileset/right.xpm";
	if (c == 'P' && pflag == 1)
		name = "tileset/left.xpm";
	if (c == 'C')
		name = "tileset/cheese.xpm";
	else if (c == 'E' && dflag == 1)
		name = "tileset/openeddoor.xpm";
	else if (c == 'E')
		name = "tileset/closeddoor.xpm";
	if (c == '1')
		name = "tileset/wall2.xpm";
	if (c == '0')
		name = "tileset/empty.xpm";
	return (name);
}

void	rendering(t_windowvar ptr, int dflag, int pflag)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	create_empty_space(ptr, ft_strlen(ptr.map[0]) - 1, count_lines(ptr.map));
	while (j < count_lines(ptr.map))
	{
		i = 0;
		while (i < ft_strlen(ptr.map[j]))
		{
			if (ptr.map[j][i] == 'C' || ptr.map[j][i] == 'P'
				|| ptr.map[j][i] == 'E' || ptr.map[j][i] == '1')
			{
				ptr.i = mlx_xpm_file_to_image(ptr.p, return_file_name
						(ptr.map[j][i], dflag, pflag), &ptr.width, &ptr.height);
				if (!ptr.i)
					free_pointer(ptr.i, ptr);
				mlx_put_image_to_window(ptr.p, ptr.w, ptr.i, i * 60, j * 60);
			}
			i++;
		}
		j++;
	}
}

int	create_window(char **map, int y, int x)
{
	t_windowvar	mlx;
	int			l;
	int			w;

	l = count_lines(map);
	w = ft_strlen(map[0]) - 1;
	mlx.player.y = y;
	mlx.player.x = x;
	mlx.height = 60;
	mlx.width = 60;
	mlx.p = mlx_init();
	mlx.map = map;
	if (mlx.p)
	{
		mlx.w = mlx_new_window(mlx.p, w * PIXIL, l * PIXIL, "so long");
		if (mlx.w)
		{
			rendering(mlx, 0, 0);
			mlx_hook(mlx.w, 2, 1L << 0, handling_kees, &mlx);
			mlx_hook(mlx.w, 17, 0, free_exit, &mlx);
			mlx_loop (mlx.p);
		}
		free_pointer(mlx.w, mlx);
	}
	return (free_pointer(mlx.p, mlx), 0);
}
