NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

INCLUDES    = -I includes -I libft -I minilibx-linux

LDFLAGS     = -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRCS        = $(shell find src -name "*.c")

OBJDIR      = obj
OBJS        = $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRCS))

LIBFT       = libft/libft.a


all: $(NAME)


$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "cub3D compiled!"


$(LIBFT):
	@make -sC libft


$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	@rm -rf $(OBJDIR)
	@make -sC libft clean
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@make -sC libft fclean
	@echo "Full clean done."

re: fclean all


.PHONY: all clean fclean re