NAME		= libftprintf.a
LIBFT_DIR	= ./libft
LIBFT		= ./libft/libft.a
SRCS_DIR	= ./srcs
INCLUDE_DIR	= ./includes
SRCS_NAME	= ft_printf.c\
			  parse.c \
			  utils_init.c \
			  utils_toa.c \
			  utils_padding.c \
			  utils_free.c \
			  output_c.c \
			  output_s.c \
			  output_per.c \
			  output_p.c \
			  output_d.c \
			  output_u.c \

SRCS		= $(addprefix $(SRCS_DIR)/,$(SRCS_NAME))
OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE_DIR)
AR			= ar rcs
RM			= rm -f

$(NAME): $(OBJS)
	$(MAKE) all -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

all		: $(NAME)

bonus	: $(NAME)

clean	:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean	: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re bonus
