NAME		= FdF

CC			= cc

FLAGS		= -Wall -Wextra -Werror  -fsanitize=address -g -Ofast

SRC			=	src/main.c \
				src/parcer/utils/utils.c src/parcer/utils/g_n_l.c src/parcer/utils/gnl_utils.c src/parcer/utils/gcollector.c src/parcer/utils/utils_ls.c src/parcer/utils/utils_map.c \
				src/parcer/parce.c \
				src/render/draw_line.c src/render/draw_map.c src/render/rotation.c src/render/rend_utils.c src/render/hooks.c \

OBJ			= $(SRC:%.c=%.o)

LIBMLX = MLX/build/libmlx42.a
LIBMLX_INC = -IMLX/include/MLX42 -Iinclude
MLXFLG = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit

HEADER		= 	include/FdF.h \


all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) $(LIBMLX_INC) -c $< -o $@
	@echo "🛠️ Creating Objects!!"

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(MLXFLG) $(LIBMLX) -o $(NAME)
	@echo "👌 Done"

clean:
	@rm -f $(OBJ) $(BNS_OBJ)
	@echo  "🧨 Deleting OBJS."

fclean: clean
	@rm -f  $(NAME) $(BNS_NAME)
	@echo  "💣 Destroy all"

re: fclean all

.PHONY: clean 