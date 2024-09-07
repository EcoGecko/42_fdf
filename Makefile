#MAKEFLAGS += --no-print-directory

#NAME
NAME= fdf
NAME_B= fdf_bonus

#COMPILING
CC= cc
CFLAGS= -Wall -Wextra -Werror -O3
LIBS= -lXext -lX11 -lm

#LIBS
LIBFT= ${LIBFT_DIR}/libft.a
LIBFT_LIB= -L${LIBFT_DIR} -lft
MLX= ${MLX_DIR}/libmlx.a
MLX_LIB= -Lmlx -lmlx

#DIRECTORIES
SRCS_DIR= src
INC= include
OBJS_DIR= obj
LIBFT_DIR= libft
MLX_DIR= mlx
MAPS= extras/maps

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#SOURCES
SRCF= control_keys control_mouse draw error_utils geometry map map_utils matrix \
	  menu mlx_utils render utils

SRCBF= control_keys control_mouse draw error_utils geometry map map_utils matrix \
	  menu mlx_utils render utils

SRCS= $(addprefix ${SRCS_DIR}/, $(addsuffix .c, ${SRCF}))
OBJS= $(addprefix ${OBJS_DIR}/, $(addsuffix .o, ${SRCF}))
SRCSB= $(addprefix ${SRCS_DIR}/, $(addsuffix .c, ${SRCBF}))
OBJSB= $(addprefix ${OBJS_DIR}/, $(addsuffix .o, ${SRCBF}))

all: ${NAME} ${MAPS}

${NAME}: ${LIBFT} ${MLX} ${OBJS} main.c
	${CC} ${CFLAGS} main.c ${OBJS} -I./${INC} ${LIBFT_LIB} ${MLX_LIB} ${LIBS} -o ${NAME}
	@echo "$(GRAY)${CC} ${CFLAGS} main.c ${OBJS} -I./${INC} ${LIBFT_LIB} ${MLX_LIB} ${LIBS} -o ${NAME}"
	@echo "$(GREEN)FDF compiled!$(DEF_COLOR)"

${NAME_B}: ${LIBFT} ${MLX} ${OBJSB} main.c
	${CC} ${CFLAGS} main.c ${OBJSB} -I./${INC} ${LIBFT_LIB} ${MLX_LIB} ${LIBS} -o ${NAME_B}
	@echo "$(GRAY)${CC} ${CFLAGS} main.c ${OBJBS} -I./${INC} ${LIBFT_LIB} ${MLX_LIB} ${LIBS} -o ${NAME_B}"
	@echo "$(GREEN)FDF compiled!$(DEF_COLOR)"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	@echo "$(YELLOW)🔧Compiling: $< $(DEF_COLOR)"
	${CC} ${CFLAGS} -I./${INC} -c $< -o $@

${OBJS_DIR}:
	@mkdir -p ${OBJS_DIR}

${LIBFT}:
	@${MAKE} bonus -sC ${LIBFT_DIR}

${MLX}: | ${MLX_DIR}
	@${MAKE} -sC ${MLX_DIR}
	@echo "$(GREEN)mlx compiled!$(DEF_COLOR)"

${MLX_DIR}:
	@wget -q https://cdn.intra.42.fr/document/document/14422/minilibx-linux.tgz
	@echo "$(BLUE)Minilibx downloaded$(DEF_COLOR)"
	@tar -zxf minilibx-linux.tgz
	@rm -rf minilibx-linux.tgz
	@mv minilibx-linux ${MLX_DIR}

${MAPS}:
	@wget -q https://cdn.intra.42.fr/document/document/14419/maps.zip
	@unzip -q maps.zip
	@rm maps.zip
	@rm -rf __MACOSX
	@mv test_maps ${MAPS}
	@echo "$(BLUE)Example maps downloaded$(DEF_COLOR)"

bonus: ${NAME_B} ${MAPS}

clean:
	rm -rf ${OBJS_DIR}
	@echo "$(MAGENTA)Fdf object files cleaned!$(DEF_COLOR)"
	make clean -sC ${LIBFT_DIR}
	@echo "$(MAGENTA)libft object and dependency files cleaned.$(DEF_COLOR)"
	make clean -sC ${MLX_DIR}
	@echo "$(MAGENTA)mlx object and dependency files cleaned.$(DEF_COLOR)"

fclean: clean
	rm -f ${NAME} ${NAME_B}
	@echo "$(CYAN)Fdf executable files cleaned!$(DEF_COLOR)"
	make fclean -sC ${LIBFT_DIR}
	@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"

debug: ${LIBFT} ${MLX} ${MAPS}
	${CC} -g3 main.c ${SRCS} -I./${INC} -L${LIBFT_DIR} -lft -I./${MLX_INC} ${MLX_LIB} ${LIBS} -o ${NAME}

run: ${NAME}
	@./fdf maps/42.fdf

sclean: fclean
	rm -rf ${MLX_DIR} ${MAPS}
	@echo "$(MAGENTA)Dir cleaned!$(DEF_COLOR)"

.PHONY: all clean fclean re sclean bonus
.SILENT:
