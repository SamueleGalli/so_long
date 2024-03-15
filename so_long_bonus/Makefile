#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long_bonus
CC        := gcc
FLAGS    := -g -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      libft_bonus/put_hex_bonus.c \
                          libft_bonus/str_bonus.c \
                          libft_bonus/itoa_bonus.c \
                          libft_bonus/put_nbr_bonus.c \
                          libft_bonus/is_chars_bonus.c \
                          libft_bonus/str_cmp_bonus.c \
                          libft_bonus/split_bonus.c \
                          libft_bonus/mem_alloc_bonus.c \
                          libft_bonus/mem_cmp_bonus.c \
                          libft_bonus/alphas_bonus.c \
                          libft_bonus/tables_bonus.c \
                          libft_bonus/lst_fts_bonus.c \
                          libft_bonus/mem_set_bonus.c \
                          libft_bonus/atoi_bonus.c \
                          libft_bonus/put_bonus.c \
                          libft_bonus/digitcount_bonus.c \
                          libft_bonus/str_malloc_bonus.c \
                          libft_bonus/lst_bonus.c \
                          libft_bonus/str_chr_bonus.c \
                          gnl_bonus/get_next_line_utils_bonus.c \
                          gnl_bonus/get_next_line_bonus.c \
                          main_bonus.c \
                          errors_bonus.c \
                          game_bonus/render_bonus.c \
                          game_bonus/player_end_bonus.c \
                          game_bonus/game_init_bonus.c \
                          game_bonus/input_bonus.c \
                          game_bonus/draw_wall_bonus.c \
                          game_bonus/open_wall_images_bonus.c \
                          game_bonus/enemy_behaviour_bonus.c \
                          game_bonus/open_images_bonus.c \
                          game_bonus/player_movement_bonus.c \
                          game_bonus/update_bonus.c \
                          game_bonus/end_program_bonus.c \
                          game_bonus/reset_bonus.c \
                          game_bonus/follower_behaviour_bonus.c \
                          game_bonus/ft_winable_bonus.c \
                          game_bonus/win_bonus.c \
                          map_bonus/enemy_generator_bonus.c \
                          map_bonus/map_checker_bonus.c \
                          map_bonus/tilemap_generator_bonus.c \
                          map_bonus/map_reader_bonus.c \
                          map_bonus/comodetion_bonus.c \
                          map_bonus/map_checker_utils_bonus.c \
                          
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


