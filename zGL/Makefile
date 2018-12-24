NAME=zGL.a
SRC= src/draw.c src/line.c src/utils.c src/zGL.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	make -C minilib
	mv minilib/libmlx.a zGL.a
	make -C libft
	ar rcs zGL.a libft/*.o
	gcc -c $(SRC) -Wall -Werror -Wextra
	ar rcs zGL.a $(OBJ)
	rm -f draw.o line.o utils.o zGL.o
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f draw.o line.o utils.o zGL.o zGL.a

re: clean all
