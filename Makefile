NAME        = cub3D

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP
INCLUDES    = -I includes -I libft -I minilibx-linux
LDFLAGS     = -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm

DIR_SRCS	=	src \
				src/exec \
				src/parsing \
				src/free \

vpath %.c $(DIR_SRCS)
vpath %.h includes

SRC_DIR    = src
OBJ_DIR    = .obj
LIBFT_DIR  = libft

SRCS =	main.c \
		dda.c \
		draw.c \
		events.c \
		game_loop.c \
		init_data.c \
		init_texture.c \
		raycasting.c \
		texture_handler.c \
		check_error.c \
		map_parser.c \
		map_validation.c \
		parser.c \
		parsing_element.c \
		parsing_element_utils.c \
		parsing_utils.c \
		read_map_file.c \
		free_close.c \
		

OBJS    = $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS    = $(SRCS:%.c=$(OBJ_DIR)/%.d)

LIB_LIBFT      = $(LIBFT_DIR)/libft.a

all: lib $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS) $(LIB_LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_LIBFT) $(LDFLAGS) -o $@
	@echo "cub3D compiled!"

lib:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)
	@echo "Object files cleaned."

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	@echo "Full clean done."

re: fclean all

-include $(DEPS)

.PHONY: lib all clean fclean re