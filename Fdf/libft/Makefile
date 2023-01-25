#Setting Color
CCEND 		=   	\033[0m
CCYAN 		=   	\033[34m
CGREEN		=   	\033[32m
CCRED 		=   	\033[31m
CCPURPLE 	=   	\033[35m

NAME = libft.a
CC = cc
FLAGS = -Wall -Werror -Wextra

RM = rm -f
RMR = rm -rf

PATH_OBJ = ./.objs/

SRCS = 	ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   get_next_line.c \

SRCS_BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

LIST_OBJS = $(patsubst %.c, %.o, $(SRCS))
LIST_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))

OBJS = $(addprefix $(PATH_OBJ), $(LIST_OBJS))
OBJS_B = $(addprefix $(PATH_OBJ), $(LIST_BONUS))

HEADER = libft.h

all: $(NAME)

$(PATH_OBJ):
	@mkdir -p $(PATH_OBJ)

$(PATH_OBJ)%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJ)
	@-$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)\t$< $(CGREEN)--> $(CCYAN)$@ $(CCEND)"
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@ 

$(NAME): $(PATH_OBJ) $(OBJS) $(HEADER)
	@printf "\r\t\033[K$(CCYAN)[✅]\t $(CGREEN)--> $(CCYAN)Gen Objs$ (CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs ...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rcs $(NAME) $(OBJS) 

bonus: $(PATH_OBJ) $(OBJS_B) $(HEADER)
	@ar rcs $(NAME) $(OBJS_B)

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of Objects...$(CCEND)\n"
	@$(RMR) $(PATH_OBJ)
	
fclean: clean	
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@$(RM) $(OBJS) $(NAME) 

re:		fclean all

.PHONY: all clean fclean re