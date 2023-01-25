#Setting Color
CCEND 		=   	\033[0m
CCYAN 		=   	\033[34m
CGREEN		=   	\033[32m
CCRED 		=   	\033[31m
CCPURPLE 	=   	\033[35m

NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra

RM = rm -f
RMR = rm -rf

PATH_OBJ = ./.objs/

SRCS =	main.c \
		parsing.c \
		split.c \
		check.c \
		create_list.c \
		free.c \
		pre_sort.c \
		sort.c \
		low_sort.c \
		get_min_max.c \
		swap.c \
		swap_suite.c \
		utils.c \

LIST_OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS = $(addprefix $(PATH_OBJ), $(LIST_OBJS))

HEADER = push_swap.h

all: $(NAME)

$(PATH_OBJ):
	mkdir -p $(PATH_OBJ)

$(PATH_OBJ)%.o: %.c $(HEADER)
	mkdir -p $(PATH_OBJ)
	@printf "\r\t\033[K$(CCYAN)\t$< $(CGREEN)--> $(CCYAN)$@ $(CCEND)"
	$(CC) $(FLAGS) -I. -c $< -o $@ 


$(NAME): $(OBJS) | $(PATH_OBJ) $(HEADER)
	@printf "\r\t\033[K$(CCYAN)[✅]\t $(CGREEN)--> $(CCYAN)Gen Objs$ (CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs ...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) 

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of Objects...$(CCEND)\n"
	$(RMR) $(PATH_OBJ)

fclean: clean	
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	$(RM) $(OBJS) $(NAME) 

re:		fclean all

.PHONY: all clean fclean re

