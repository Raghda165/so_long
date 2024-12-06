/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bplay.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:28:41 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/03 10:26:29 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_windowvar	go_up(t_windowvar ptr, int dflag)
{
	if (ptr.map[ptr.player.y - 1][ptr.player.x] == 'E' && dflag == 1)
		free_all_and_exit(ptr, "Yeeey Jerry won 🎊\n");
	if (ptr.map[ptr.player.y - 1][ptr.player.x] == 'X')
		free_all_and_exit(ptr, "GAME OVER... Tom won 👹\n");
	if (ptr.map[ptr.player.y - 1][ptr.player.x] != '1'
	&& ptr.map[ptr.player.y - 1][ptr.player.x] != 'E')
	{
		ptr.map[ptr.player.y][ptr.player.x] = '0';
		ptr.map[ptr.player.y - 1][ptr.player.x] = 'P';
		ptr.player.y--;
	}
	return (ptr);
}

t_windowvar	go_down(t_windowvar ptr, int dflag)
{
	if (ptr.map[ptr.player.y + 1][ptr.player.x] == 'E' && dflag == 1)
		free_all_and_exit(ptr, "Yeeey Jerry won 🎊\n");
	if (ptr.map[ptr.player.y + 1][ptr.player.x] == 'X')
		free_all_and_exit(ptr, "GAME OVER... Tom won 👹\n");
	if (ptr.map[ptr.player.y + 1][ptr.player.x] != '1'
	&& ptr.map[ptr.player.y + 1][ptr.player.x] != 'E')
	{
		ptr.map[ptr.player.y][ptr.player.x] = '0';
		ptr.map[ptr.player.y + 1][ptr.player.x] = 'P';
		ptr.player.y++;
	}
	return (ptr);
}

t_windowvar	go_left(t_windowvar ptr, int dflag)
{
	if (ptr.map[ptr.player.y][ptr.player.x - 1] == 'E' && dflag == 1)
		free_all_and_exit(ptr, "Yeeey Jerry won 🎊\n");
	if (ptr.map[ptr.player.y][ptr.player.x - 1] == 'X')
		free_all_and_exit(ptr, "GAME OVER... Tom won 👹\n");
	if (ptr.map[ptr.player.y][ptr.player.x - 1] != '1'
	&& ptr.map[ptr.player.y][ptr.player.x - 1] != 'E')
	{
		ptr.map[ptr.player.y][ptr.player.x] = '0';
		ptr.map[ptr.player.y][ptr.player.x - 1] = 'P';
		ptr.player.x--;
	}
	return (ptr);
}

t_windowvar	go_right(t_windowvar ptr, int dflag)
{
	if (ptr.map[ptr.player.y][ptr.player.x + 1] == 'E' && dflag == 1)
		free_all_and_exit(ptr, "Yeeey Jerry won 🎊\n");
	if (ptr.map[ptr.player.y][ptr.player.x + 1] == 'X')
		free_all_and_exit(ptr, "GAME OVER... Tom won 👹\n");
	if (ptr.map[ptr.player.y][ptr.player.x + 1] != '1'
	&& ptr.map[ptr.player.y][ptr.player.x + 1] != 'E')
	{
		ptr.map[ptr.player.y][ptr.player.x] = '0';
		ptr.map[ptr.player.y][ptr.player.x + 1] = 'P';
		ptr.player.x++;
	}
	return (ptr);
}

int	handling_kees(int key_code, t_windowvar *p)
{
	t_windowvar	ptr;
	static int	dflag;
	int			pflag;
	static int	moves_count;

	pflag = 0;
	ptr = *p;
	if (key_code == 53 || key_code == 13 || key_code == 126
		|| key_code == 1 || key_code == 125 || key_code == 2 || key_code == 124)
		*p = handling(key_code, p, ptr, dflag);
	if (key_code == 0 || key_code == 123)
	{
		*p = go_left(ptr, dflag);
		pflag = 1;
	}
	ptr = *p;
	if (cheese_count(ptr.map) == 0)
		dflag = 1;
	moves_count++;
	brendering(ptr, dflag, pflag, 0);
	mlx_string_put(ptr.p, ptr.w, 130, 20, 1, ft_itoa(moves_count));
	write(1, "move_count : ", 14);
	ft_putnbr_fd(moves_count, 1);
	write(1, "\n", 1);
	return (ft_itoa(moves_count), 0);
}
