LIBPATH= libft

SDLPATH= SDL2-2.0.5

LIB= $(LIBPATH)/libft.a

SDL= $(SDLPATH)/lib/

NAME= rtv1

CC= gcc

CFLAGS= -Wall -Wextra -Werror

LDFLAGS= -L libft -lft -I$(LIBPATH)/includes -L $(SDL) -lSDL2 -lSDL2main -I$(SDLPATH)/include

SRC= main.c

OBJ= $(SRC:.c=.o)

all: $(LIB) $(SDL) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	make -C $(LIBPATH)

$(SDL):
	cd SDL2-2.0.5; \
		./configure --prefix=$(shell pwd)/SDL2-2.0.5/ && make && make install

clean:
	rm -f $(OBJ)
	make clean -C $(LIBPATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBPATH)
	cd SDL2-2.0.5; \
		rm -Rf bin \
		rm -Rf lib \
		rm -Rf build \
		rm -f config.log

re: fclean all
