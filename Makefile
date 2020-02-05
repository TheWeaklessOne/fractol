NAME = fractol

SRC  = sources/main.c sources/menu.c sources/fractals/mandelbrot.c sources/keys.c sources/hooks.c sources/buttons.c sources/initialization.c sources/info.c sources/threads.c sources/key_hooks.c sources/fractals/burningship.c sources/fractals/julia.c sources/fractals/biomorph.c sources/fractals/spider.c sources/fractals/newton.c sources/fractals/random.c sources/fractals/thorn.c

OBJ  = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -Ofast

OSVER := $(shell uname -s)

ifeq ($(OSVER), Linux)
	LIBFLAGS = -lmlx -lXext -lX11 minilibx/libmlx.a -lm
else
	LIBFLAGS = -framework OpenGL -framework AppKit -lm -lmlx
endif

RED= \033[1;31m
GREEN= \033[1;32m
YELLOW= \033[1;33m
BLUE= \033[1;34m
VIOLET= \033[1;35m

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFLAGS) -o $(NAME)
	@echo "$(GREEN)Project is successfully compiled"

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@echo "$(RED)Suspending library files$(VIOLET)"
	rm -rf *.o

fclean: clean
	@echo "$(RED)Suspending project files$(VIOLET)"
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all
