NAME=fractol
SRC= main.c fractol.c complex.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	make -C zGL
	gcc $(SRC) zGL/zGL.a zGL/libft/libft.a -o $(NAME) -Wall -Wextra -Werror -lX11 -lXext -lm

clean:
	rm -f $(OBJ)

run:
	make
	./fractol

re: clean all
