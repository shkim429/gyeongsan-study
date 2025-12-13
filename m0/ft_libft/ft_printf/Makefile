NAME = printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INC)
RM = rm -rf
SRCS = ft_printf.c ft_print_c.c ft_print_id.c ft_print_u.c ft_print_hex.c ft_print_s.c ft_print_p.c\
	   ft_utoa.c ft_utoa_base.c\

OBJS = ${SRCS:.c=.o}
OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))
INC = -I./include \
      -I../libft


all : $(NAME)

$(NAME) : $(OBJS_FILES)
	ar -rcs $(NAME) $(OBJS_FILES)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all
	
.PHONY : all clean fclean re