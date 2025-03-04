NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra

SRCDIR = src
OBJDIR = obj
LIBFTDIR = src/libft

MLX_CFLAGS = -I./src/minilibx-linux
MLX_LDFLAGS = -L./src/minilibx-linux -lmlx -lX11 -lXext -lm
LIBXDIR = src/minilibx-linux

SRCS = parsing/check_map_doable parsing/checker parsing/map_content \
		parsing/map_name parsing/struct_init \
		SL_utils/map_utils SL_utils/maxes SL_utils/utils \
		mlx_related/mlx_free mlx_related/mlx_init \
		main

SOURCES  = $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRCS)))
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))

LIB = $(LIBFTDIR)/libft.a
LIBX = $(LIBXDIR)/libmlx.a

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(MLX_CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB) $(LIBX)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBX) $(MLX_LDFLAGS)

$(LIB):
	@$(MAKE) -C $(LIBFTDIR)

$(LIBX):
	@$(MAKE) -C $(LIBXDIR)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@if [ -f $(LIBXDIR)/Makefile.gen ]; then \
		$(MAKE) -C $(LIBXDIR) clean; \
	fi
	rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@if [ -f $(LIBXDIR)/Makefile.gen ]; then \
		$(MAKE) -C $(LIBXDIR) clean; \
	fi
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re