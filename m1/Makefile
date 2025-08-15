NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
SRCS = ft_printf.c ft_print_c.c ft_print_id.c ft_print_u.c ft_print_hex.c ft_print_s.c ft_print_p.c\
ft_strlen.c ft_strdup.c ft_itoa.c ft_utoa.c ft_utoa_base.c ft_memset.c\

OBJS = ${SRCS:.c=.o}
OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
MAIN = main.c
MAIN_EXE = a.out

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	ar -rcs $(NAME) $(OBJS_FILES)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_EXE) : $(NAME) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -L. -lftprintf -o $(MAIN_EXE)

clean :
	$(RM) $(OBJS_FILES) $(MAIN_EXE)

fclean : clean
	$(RM) $(NAME) $(MAIN_EXE)

re : fclean all
	
.PHONY : all clean fclean re