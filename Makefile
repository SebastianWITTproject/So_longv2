
FLAGS = -Wall -Werror -Wextra

CFILES = main.c \
	render.c \
	move_player.c \
	move_action.c \
	ft_split.c \
	get_next_line_utils.c \
	ft_strdup.c \
	ft_strjoinbis.c \
	get_next_line.c 

OFILES = $(CFILES:%.c=%.o)

NAME = so_long

INCLUDES = -I/opt/X11/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OFILES) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)
	
clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all 
