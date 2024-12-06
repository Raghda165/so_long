/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bwindow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:09:52 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/03 10:33:08 by ryagoub          ###   ########.fr       */
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

char	*breturn_file_name(char c, int dflag, int pflag, int eflag)
{
	char	*name;

	eflag = 0;
	name = NULL;
	if (c == 'P' && pflag == 1)
		name = "tileset/left.xpm";
	else if (c == 'P')
		name = "tileset/right.xpm";
	else if (c == 'C')
		name = "tileset/cheese.xpm";
	else if (c == 'X' && eflag == 1)
		name = "tileset/walkingtom.xpm";
	else if (c == 'X')
		name = "tileset/walkingtom2.xpm";
	else if (c == 'E' && dflag == 1)
		name = "tileset/openeddoor.xpm";
	else if (c == 'E')
		name = "tileset/closeddoor.xpm";
	else if (c == '1')
		name = "tileset/wall2.xpm";
	else if (c == '0')
		name = "tileset/empty.xpm";
	return (name);
}

void	brendering(t_windowvar ptr, int df, int pf, int ef)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	fill_empty_space(ptr);
	while (j < count_lines(ptr.map))
	{
		i = 0;
		while (i < ft_strlen(ptr.map[j]))
		{
			if (ptr.map[j][i] == 'C' || ptr.map[j][i] == 'P' || ptr.map[j][i]
			== 'E' || ptr.map[j][i] == '1' || ptr.map[j][i] == 'X')
			{
				ptr.i = mlx_xpm_file_to_image(ptr.p, breturn_file_name
						(ptr.map[j][i], df, pf, ef), &ptr.width, &ptr.height);
				if (!ptr.i)
					free_pointer(ptr.i, ptr);
				mlx_put_image_to_window(ptr.p, ptr.w, ptr.i, i * 60, j * 60);
			}
			i++;
		}
		j++;
	}
	mlx_string_put(ptr.p, ptr.w, 40, 20, 1, "Moves Count : ");
}

int	create_window(char **map, int y, int x)
{
	t_windowvar	mlx;
	int			l;
	int			w;

	l = count_lines(map);
	w = ft_strlen(map[0]) - 1;
	mlx.height = 60;
	mlx.width = 60;
	mlx.player.y = y;
	mlx.player.x = x;
	mlx.p = mlx_init();
	mlx.map = map;
	if (mlx.p)
	{
		mlx.w = mlx_new_window(mlx.p, w * PIXIL, l * PIXIL, "so long");
		if (!mlx.w)
			free_pointer(mlx.w, mlx);
		brendering(mlx, 0, 0, 0);
		change_image(mlx, 0);
		mlx_hook(mlx.w, 2, 1L << 0, handling_kees, &mlx);
		mlx_hook(mlx.w, 17, 0, free_exit, &mlx);
		mlx_loop_hook(mlx.p, move_enemy, &mlx);
		mlx_loop (mlx.p);
	}
	return (free_pointer(mlx.p, mlx), 0);
}
