# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 16:17:58 by xmatute-          #+#    #+#              #
#    Updated: 2023/04/07 18:28:48 by jperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#.SILENT:

SRC =	ft_isalpha.c ft_toupper.c \
		ft_isdigit.c ft_tolower.c \
		ft_isalnum.c ft_strchr.c  \
		ft_isascii.c ft_strrchr.c \
		ft_isprint.c ft_strncmp.c \
		ft_strlen.c  ft_memchr.c  \
		ft_memset.c  ft_memcmp.c  \
		ft_bzero.c   ft_strnstr.c \
		ft_memcpy.c  ft_atoi.c    \
		ft_memmove.c              \
		ft_strlcpy.c              \
		ft_strlcat.c              \
		 ft_calloc.c ft_strdup.c \
		ft_substr.c     \
		ft_strjoin.c    \
		ft_strtrim.c    \
		ft_itoa.c       \
		ft_strmapi.c    \
		ft_striteri.c   \
		ft_putchar_fd.c \
		ft_putstr_fd.c  \
		ft_putendl_fd.c \
		ft_putnbr_fd.c  \

		
# ft_.c

OBJS = $(SRC:%.c=%.o)

BONUS =	ft_lstnew_bonus.c         \
		ft_lstadd_front_bonus.c   \
		ft_lstsize_bonus.c        \
		ft_lstlast_bonus.c        \
		ft_lstadd_back_bonus.c    \
		ft_lstdelone_bonus.c      \
		ft_lstclear_bonus.c       \
		ft_lstiter_bonus.c        \
		ft_lstmap_bonus.c

		
BONUS_OBJS = $(BONUS:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

.c.o: $(SRC)
	gcc $(FLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
