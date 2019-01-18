NAME=fractol
SRC= main.c fractol.c complex.c algo.c fractals.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) fractol.h
	make -C zGL
	gcc $(SRC) zGL/zgl.a zGL/libft/libft.a -o $(NAME) -Wall -Wextra -Werror -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)

run:
	make
	./fractol

re: clean all
