NAME=fractol
SRC= main.c fractol.c complex.c zGL/zGL.a zGL/libft/libft.a
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	make -C zGL
	gcc $(SRC) -o $(NAME) -Wall -Wextra -Werror -lX11 -lXext -lm

clean:
	rm -f $(OBJ)

run:
	make
	./fractol

re: clean all
