/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:00:03 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/03 10:32:33 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_pointer(void *p, t_windowvar	mlx)
{
	if (p == mlx.i)
	{
		mlx_destroy_window(mlx.p, mlx.w);
		free(mlx.p);
		free(mlx.i);
		freem(mlx.map);
		ft_putstr_fd("there is a problem in initializing the image\n", 1);
	}
	if (p == mlx.w)
	{
		free(mlx.p);
		freem(mlx.map);
		ft_putstr_fd("there is a problem in initializing the window\n", 1);
	}
	if (p == mlx.p)
	{
		free(mlx.p);
		freem(mlx.map);
		ft_putstr_fd("there is a problem in initializing the mlx\n", 1);
	}
	exit(EXIT_FAILURE);
}

t_windowvar	handling(int key_code, t_windowvar *p, t_windowvar	ptr, int dflag)
{
	if (key_code == 53)
		free_all_and_exit(ptr, "Why did you exit 😢 ... try again\n");
	if (key_code == 13 || key_code == 126)
		*p = go_up(ptr, dflag);
	if (key_code == 1 || key_code == 125)
		*p = go_down(ptr, dflag);
	if (key_code == 2 || key_code == 124)
		*p = go_right(ptr, dflag);
	return (*p);
}

int	free_exit(t_windowvar *ptr)
{
	t_windowvar	mlx;

	mlx = *ptr;
	mlx_destroy_window(mlx.p, mlx.w);
	freem(mlx.map);
	free(mlx.p);
	free(mlx.i);
	exit(EXIT_SUCCESS);
}
