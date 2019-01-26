NAME=fractol
SRC= src/main.c src/fractol.c src/complex.c src/algo.c src/fractals.c src/draw.c src/utils.c src/zgl.c
OBJ=$(SRC:.c=.o)

all: $(NAME)
	make -C libft/
	
$(NAME):$(OBJ) fractol.h
	make -C libft/
	make -C minilib/
	gcc $(SRC) minilib/libmlx.a libft/libft.a -o $(NAME) -Wall -Wextra -Werror -framework OpenGL -framework AppKit

clean:
		make clean -C libft/
		make clean -C minilib/
	   	rm -f $(OBJ)

fclean: clean 
		rm -rf $(NAME)

re: fclean all
