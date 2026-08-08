NAME = libgetnextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INC)
RM = rm -rf
SRCS = get_next_line_utils.c get_next_line.c\

OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBS_PATH = -L. 
LIBS_DIR_PATH = ./ft_libft
LIBS = -lgetnextline
INC = -I. 

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
	$(CC) $(CFLAGS) $(MAIN) $(LIBS_PATH) $(LIBS) -o $(MAIN_EXE)

clean :
	$(RM) $(OBJ_DIR) $(MAIN_EXE)

fclean : clean
	$(RM) $(NAME) $(MAIN_EXE)

re : fclean all
	
.PHONY : all clean fclean re