NAME = libftprintfgnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJ_DIR = obj
OBJ = $(OBJ_DIR)/libftprintfgnl.o 

LIBFT_DIR_PATH = libft
PRINTF_DIR_PATH = ft_printf
GNL_DIR_PATH = ft_get_next_line

LIBFT_A = $(LIBFT_DIR_PATH)/libft.a
PRINTF_A = $(PRINTF_DIR_PATH)/printf.a
GNL_A = $(GNL_DIR_PATH)/getnextline.a

all : $(NAME)

$(LIBFT_A) : 
	make -C $(LIBFT_DIR_PATH)

$(PRINTF_A) :
	make -C $(PRINTF_DIR_PATH)
$(GNL_A) :
	make -C $(GNL_DIR_PATH)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)
	
$(OBJ) : $(LIBFT_A) $(PRINTF_A) $(GNL_A) | $(OBJ_DIR)
	ld -r --whole-archive $(LIBFT_A) $(PRINTF_A) $(GNL_A) -o $(OBJ)



$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJ_DIR) 
	make -C $(LIBFT_DIR_PATH) clean
	make -C $(PRINTF_DIR_PATH) clean
	make -C $(GNL_DIR_PATH) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR_PATH) fclean
	make -C $(PRINTF_DIR_PATH) fclean
	make -C $(GNL_DIR_PATH) fclean
	


re : fclean all
	
.PHONY : all clean fclean re