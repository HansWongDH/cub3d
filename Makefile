NAME		= cub3d

SRC_DIR		= src/cub3d
OBJ_DIR		= obj
LIBFT_DIR	= src/libft
INC_DIR		= inc

SRC_FILES	= main.c main2.c player_class.c map_class.c handle_key.c init_data.c float_utils.c game_class.c map_validation.c map_parsing.c xpm_utils.c player_class_utils.c vector_utils.c map_element_parsing.c

GCC 		= gcc
CFLAGS		= -Wall -Wextra -Werror
MINIFLAGS	= -lmlx -framework OpenGl -framework Appkit
SANITIZE	= -fsanitize=address -g3
RM			= rm -f

OBJ_FILES	= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIBFT		= $(LIBFT_DIR)/libft.a
LIBRARIES	= -L$(LIBFT_DIR) -lft

all:		$(NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
	$(GCC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

${NAME}:	${LIBFT} ${OBJ_FILES} ${OBJ_BANNER}
	${GCC} -o ${NAME} ${OBJ_FILES} $(LIBRARIES) $(SANITIZE) $(MINIFLAGS)

test: $(NAME)
	./$(NAME) map3.cub

retest: fclean $(NAME)
	./$(NAME) map3.cub

clean:
	$(RM) $(OBJ_DIR)/*
	make clean -C $(LIBFT_DIR)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)/*
	make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:		all clean fclean re
