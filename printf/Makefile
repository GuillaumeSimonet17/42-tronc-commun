#Setting Color
CCEND 		=   	\033[0m
CCYAN 		=   	\033[34m
CGREEN		=   	\033[32m
CCRED 		=   	\033[31m
CCPURPLE 	=   	\033[35m

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra

RM = rm -f
RMR = rm -rf

PATH_OBJ = ./.objs/

SRCS = libftprintf.c \
		ft_utils.c \
		ft_address.c \

LIST_OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS = $(addprefix $(PATH_OBJ), $(LIST_OBJS))

HEADER = ft_printf.h

all: $(NAME)

$(PATH_OBJ):
	mkdir -p $(PATH_OBJ)

$(PATH_OBJ)%.o: %.c $(HEADER)
	mkdir -p $(PATH_OBJ)
	@printf "\r\t\033[K$(CCYAN)\t$< $(CGREEN)--> $(CCYAN)$@ $(CCEND)"
	$(CC) $(FLAGS) -I. -Ilibft -c $< -o $@ 


$(NAME): libft/libft.a $(OBJS) | $(PATH_OBJ) $(HEADER)
	cp libft/libft.a $(NAME)
	@printf "\r\t\033[K$(CCYAN)[✅]\t $(CGREEN)--> $(CCYAN)Gen Objs$ (CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs ...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	ar rcs $(NAME) $(OBJS) 

libft/libft.a:
	$(MAKE) -C libft

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of Objects...$(CCEND)\n"
	$(RMR) $(PATH_OBJ) libft/libft.a 

fclean: clean	
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	$(RM) $(OBJS) $(NAME) 

re:		fclean all

.PHONY: all clean fclean re

