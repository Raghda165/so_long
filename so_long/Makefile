NAME = so_long
BONUSNAME = so_long_bonus
CFILES = check_pathes.c get_next_line.c get_next_line_utils.c map_parsing.c so_long_utils.c so_long.c window.c play.c putnbr.c free_all.c
BCFILES = bcheck_pathes.c get_next_line.c get_next_line_utils.c bmap_parsing.c bonus_utils.c bonus.c bwindow.c bplay.c empty_space_and_utils.c move_enemy.c free_all.c itoa.c
CFLAGS = -Wall -Werror -Wextra
OFILES = $(CFILES:.c=.o)
BOFILES = $(BCFILES:.c=.o)
MINILIBX = mlx/libmlx.a
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all : $(NAME)
bonus : $(BONUSNAME)

$(NAME) : $(OFILES)
	make all -C mlx
	$(CC) $(CFLAGS) $(OFILES) -Lmlx -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

$(BONUSNAME) : $(BOFILES)
	make all -C mlx
	$(CC) $(CFLAGS) $(BOFILES) -Lmlx -lmlx -framework OpenGL -framework AppKit  -o $(BONUSNAME)

clean :
	make clean -C mlx
	$(RM) $(OFILES) $(BOFILES)

fclean : clean
	$(RM) $(NAME) $(BONUSNAME)

re: fclean all
.PHONY: all clean fclean re bonus






