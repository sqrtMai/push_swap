NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/
AR = ar rcs
RM = rm -f

SRC = push_swap.c \
		instructions/push.c instructions/reverse_rotate.c instructions/rotate.c instructions/swap.c \
		utils/error_checking.c utils/ft_atol.c utils/initialize.c utils/min_and_max.c \
		utils/lst_utils/ft_lstadd_back_ps.c utils/lst_utils/ft_lstadd_front.c utils/lst_utils/ft_lstlast.c utils/lst_utils/ft_lstnew_ps.c utils/lst_utils/ft_lstsize.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
