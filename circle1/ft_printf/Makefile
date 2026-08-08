NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INC)
RM = rm -rf
SRCS = ft_printf.c ft_print_c.c ft_print_id.c ft_print_u.c ft_print_hex.c ft_print_s.c ft_print_p.c\
	   ft_utoa.c ft_utoa_base.c\

OBJS = ${SRCS:.c=.o}
OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBS_PATH = -L. \
			-L../../m0/ft_libft/libft
LIBS_DIR_PATH = ../../m0/ft_libft/libft
LIBS = -lftprintf -lft

INC = -I./include \
	  -I../../m0/ft_libft/libft

MAIN = main.c
MAIN_EXE = a.out

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	make -C $(LIBS_DIR_PATH)
	ar -rcs $(NAME) $(OBJ_DIR)/*.o

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_EXE) : $(NAME) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(LIBS_PATH)  $(LIBS) -o $(MAIN_EXE)

clean :
	$(RM) $(OBJ_DIR) $(MAIN_EXE)
	make -C $(LIBS_DIR_PATH) clean


fclean : clean
	$(RM) $(NAME) $(MAIN_EXE)
	make -C $(LIBS_DIR_PATH) fclean

re : fclean all
	
.PHONY : all clean fclean re