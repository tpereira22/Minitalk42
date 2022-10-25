# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 15:44:16 by timartin          #+#    #+#              #
#    Updated: 2022/02/21 20:06:46 by timartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_strlen.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strlcpy.c \
					ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
					ft_strchr.c ft_strrchr.c ft_memcmp.c ft_strnstr.c ft_strlcat.c \
					ft_strncmp.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_itoa.c \
					ft_strtrim.c ft_strmapi.c ft_striteri.c ft_split.c

SRCSB			=	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c

OBJS			= $(SRCS:.c=.o)

OBJSB			= $(SRCSB:.c=.o)

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(OBJSB)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(OBJSB)
				ar rcs $(NAME) $(OBJS) $(OBJSB)

.PHONY:			all clean fclean re bonus