NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

NAME =	fdf

PATH_OBJ = ./.objs/

SRC =   main.c \
		read_file.c \
		draw.c \
		event.c \
		param.c \
		utils.c \
		free.c \

LIST_OBJS = $(patsubst %.c, %.o, $(SRC))
OBJ = $(addprefix $(PATH_OBJ), $(LIST_OBJS))

FLAGS = -Wall -Wextra -Werror -O3 
LINKS = -framework OpenGL -framework AppKit
HEADER = fdf.h

all: $(NAME)

$(PATH_OBJ):
	@mkdir -p $(PATH_OBJ)

$(PATH_OBJ)%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	$(CC) $(FLAGS) -I $(HEADER) -c -Imlx $< -o $@ 


$(NAME): $(PATH_OBJ) $(OBJ)
	make -C ./mlx
	make -C libft
	@cc $(FLAGS) $(OBJ) $(LINKS) mlx/libmlx.a libft/libft.a  -o $(NAME) 
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@echo $(GREEN)"- Compiled -"$(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(PATH_OBJ)
	make -C mlx clean
	make -C libft fclean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf  $(PATH_OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re
