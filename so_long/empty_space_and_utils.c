/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_space_and_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:38:51 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/02 14:37:39 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd ('-', fd);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd (nb / 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

void	fill_empty_space(t_windowvar ptr)
{
	ptr.i = mlx_xpm_file_to_image(ptr.p,
			"tileset/empty.xpm", &ptr.width, &ptr.height);
	if (!ptr.i)
		free_pointer(ptr.i, ptr);
	create_empty_space(ptr, ft_strlen(ptr.map[0]) - 1, count_lines(ptr.map));
}

void	create_empty_space(t_windowvar mlx, int width, int height)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
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
