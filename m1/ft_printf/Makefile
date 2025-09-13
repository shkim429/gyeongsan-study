NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INC)
RM = rm -rf
SRCS = ft_printf.c ft_print_c.c ft_print_id.c ft_print_u.c ft_print_hex.c ft_print_s.c ft_print_p.c\
	   ft_utoa.c ft_utoa_base.c\

OBJS = ${SRCS:.c=.o}
OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBS_PATH = -L. -L./ft_libft
LIBS_DIR_PATH = ./ft_libft
LIBS = -lftprintf -lft
INC = -I./include -I./ft_libft

MAIN = main.c
MAIN_EXE = a.out

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	make -C $(LIBS_DIR_PATH)
	ar -x ./ft_libft/libft.a
	mv *.o $(OBJ_DIR)
	ar -rcs $(NAME) $(OBJ_DIR)/*.o
	make -C $(LIBS_DIR_PATH) clean

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_EXE) : $(NAME) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(LIBS_PATH)  $(LIBS) -o $(MAIN_EXE)

clean :
	$(RM) $(OBJ_DIR) $(MAIN_EXE)

fclean : clean
	$(RM) $(NAME) $(MAIN_EXE)
	make -C $(LIBS_DIR_PATH) fclean

re : fclean all
	
.PHONY : all clean fclean re