#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      map/map_checker_utils.c \
                          map/map_reader.c \
                          map/tilemap_generator.c \
                          map/map_checker.c \
                          map/enemy_generator.c \
                          map/comodetion.c \
                          game/enemy_behaviour.c \
                          game/input.c \
                          game/player_end.c \
                          game/end_program.c \
                          game/render.c \
                          game/reset.c \
                          game/draw_wall.c \
                          game/open_images.c \
                          game/follower_behaviour.c \
                          game/open_wall_images.c \
                          game/player_movement.c \
                          game/game_init.c \
                          game/ft_winable.c \
                          game/update.c \
                          main.c \
                          gnl/get_next_line.c \
                          gnl/get_next_line_utils.c \
                          libft/lst.c \
                          libft/itoa.c \
                          libft/str.c \
                          libft/digitcount.c \
                          libft/str_cmp.c \
                          libft/atoi.c \
                          libft/str_chr.c \
                          libft/put.c \
                          libft/put_hex.c \
                          libft/mem_set.c \
                          libft/mem_cmp.c \
                          libft/split.c \
                          libft/tables.c \
                          libft/str_malloc.c \
                          libft/put_nbr.c \
                          libft/is_chars.c \
                          libft/lst_fts.c \
                          libft/alphas.c \
                          libft/mem_alloc.c \
                          errors.c
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 minilibx-linux/configure
			@ $(MAKE) -C minilibx-linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Iminilibx-linux -Lminilibx-linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C minilibx-linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re


