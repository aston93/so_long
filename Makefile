NAME 	= so_long
CC		= gcc
SRC 	= src
HEADERS	= so_long.h libft.h mlx.h
CFLAGS	= -Wall -Wextra -Werror
LIBS	= libs
LIBFT	= libft/libft.a

OBJ = $(SRC)/main.o $(SRC)/utils.o $(SRC)/map_checker.o $(SRC)/map_checker_2.o \
		$(SRC)/initializers.o $(SRC)/keys_manipulation.o $(SRC)/rendering.o

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS) create_libft
	gcc -o $(NAME) $(OBJ) $(LIBS)/libmlx_Linux.a -L /usr/include/X11/extensions/ -lXext -lX11 -g $(LIBFT)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

create_libft:
	cd libft && make

clean:
	rm -f $(OBJ)
	@echo "clean done"

fclean: clean
	rm -f $(NAME)
	@echo "fclean done"

re: fclean all
