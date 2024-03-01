
FLAGS = -Wall -Werror -Wextra

CFILES= action.c \
	parse.c \
	parse_utils.c \
	render_display.c \
	render_load.c \
	so_long.c \
	valid_path.c \
	get_next_line.c \
	keyboard.c \
	get_next_line_utils.c

OFILES = $(CFILES:%.c=%.o)

NAME = so_long

INCLUDES = -I/opt/X11/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OFILES) $(MLX_FLAGS)

%.o: %.c %.h
	$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)
	
clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all 
