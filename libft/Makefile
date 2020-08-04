# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/23 22:00:55 by hyuki             #+#    #+#              #
#    Updated: 2020/07/27 20:45:04 by hyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_calloc.c ft_isascii.c ft_memccpy.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strnstr.c \
ft_toupper.c ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_strdup.c ft_strlen.c \
ft_strrchr.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_strncmp.c \
ft_tolower.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c  ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SONAME = libft.so
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}
B_SRCS = $(SRCS) ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
B_OBJS = $(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(B_OBJS)
	ar rcs $(NAME) $(B_OBJS)

clean:
	/bin/rm -f $(B_OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

so : bonus
	${CC} ${CFLAGS} -shared ${B_OBJS} -o ${SONAME}

.PHONY	: all bonus clean fclean re re_bonus so
