/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:31:32 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/03 10:32:16 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# ifndef PIXIL
#  define PIXIL 60
# endif

typedef struct s_map
{
	int	width;
	int	height;
}t_map;

typedef struct s_enemy
{
	int		y;
	int		x;
}t_enemy;
typedef struct s_player
{
	int		y;
	int		x;
}t_player;

typedef struct s_windowvar
{
	void		*p;
	void		*w;
	void		*i;
	char		**map;
	int			width;
	int			height;
	t_player	player;
	t_enemy		enemy;
}t_windowvar;
t_player	player_loc(char **map);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t	dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
void		free_map(char **map, char **tmp_map, char *str );
void		is_valid(char **map, char **tmp_map);
void		check_player_and_exit(char **map, char **tmp_map);
void		check_collectables(char **map, char **tmp_map);
void		is_rectangular(char **map, char **tmp_map);
t_map		create_map_dim(int fd);
int			open_file(char *str);
void		check_walls(char **map, char **tmp_map, char*str);
void		ft_putstr_fd(char *s, int fd);
int			check_pathes(char **map, char **tmp, int i, int j);
char		**tmp_map(char **map);
void		freem(char **map);
int			count_lines(char **map);
int			create_window(char **map, int x, int y);
int			handling_kees(int key_code, t_windowvar *p);
void		rendering(t_windowvar ptr, int dflag, int pflag);
void		change_image(t_windowvar mlx, int dflag);
int			cheese_count(char **map);
void		ft_putnbr_fd(int n, int fd);
void		freem(char **map);
void		free_all_and_exit(t_windowvar mlx, char *str);
void		ft_putstr_fd(char *s, int fd);
char		*breturn_file_name(char c, int dflag, int pflag, int eflag);
void		brendering(t_windowvar ptr, int dflag, int pflag, int eflag);
int			move_enemy(t_windowvar *p);
t_enemy		enemy_loc(char **map);
t_windowvar	go_up(t_windowvar ptr, int dflag);
t_windowvar	go_down(t_windowvar ptr, int dflag);
t_windowvar	go_left(t_windowvar ptr, int dflag);
t_windowvar	go_right(t_windowvar ptr, int dflag);
t_windowvar	handling(int key_code, t_windowvar *p, t_windowvar	ptr, int dflag);
void		free_pointer(void *p, t_windowvar	mlx);
void		fill_empty_space(t_windowvar ptr);
void		create_empty_space(t_windowvar mlx, int width, int height);
char		*ft_itoa(int n);
int			free_exit(t_windowvar *mlx);
#endif
