NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra

SRCDIR = src
OBJDIR = obj
LIBFTDIR = src/libft

MLX_CFLAGS = -I minilibx-linux
MLX_LDFLAGS = -L minilibx-linux -lmlx -lX11 -lXext -lm
LIBXDIR = minilibx-linux

SRCS = parsing/check_map_doable parsing/checker parsing/map_content \
		parsing/map_name parsing/struct_init parsing/free_struct \
		parsing/handle_collectibles \
		SL_utils/map_utils SL_utils/maxes SL_utils/mem_related\
		render/mlx_init render/load_all\
		render/textures_load render/render algo/handle_all \
		algo/movement algo/steps\
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
