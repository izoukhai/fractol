NAME=zgl.a
SRC= src/draw.c src/line.c src/utils.c src/zgl.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	make -C minilib
	mv minilib/libmlx.a zgl.a
	make -C libft
	ar rcs zgl.a libft/*.o
	gcc -c $(SRC) -Wall -Werror -Wextra
	ar rcs zgl.a $(OBJ)
	rm -f draw.o line.o utils.o zgl.o
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f draw.o line.o utils.o zgl.o zgl.a

re: clean all
