# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 00:14:33 by rdias-ba          #+#    #+#              #
#    Updated: 2023/05/19 16:59:02 by rdias-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isdigit.c\
		ft_memset.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_isprint.c\
		ft_putchar_fd.c\
		ft_strlcat.c\
		ft_substr.c\
		ft_atoi.c\
		ft_atoll.c\
		ft_itoa.c\
		ft_putendl_fd.c\
		ft_strlcpy.c\
		ft_tolower.c\
		ft_bzero.c\
		ft_putnbr_fd.c\
		ft_strlen.c\
		ft_toupper.c\
		ft_calloc.c\
		ft_memchr.c\
		ft_putstr_fd.c\
		ft_strmapi.c\
		ft_isalnum.c\
		ft_memcmp.c\
		ft_split.c\
		ft_strncmp.c\
		ft_isalpha.c\
		ft_memcpy.c\
		ft_strchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_isascii.c\
		ft_memmove.c\
		ft_strdup.c\
		ft_strrchr.c\
		ft_striteri.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstclear.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstlast.c\
		ft_lstmap.c\
		ft_putchr.c\
		ft_putstr.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_args_next.c\
		ft_args.c\
		ft_printf.c\
		get_next_line.c\

INCLUDES = includes/
SRCS_DIR = srcs/
SRCS_PRE = $(addprefix $(SRCS_DIR), $(SRCS))

CC = gcc
RM = rm -rf
INC = -I $(INCLUDES)
CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS_PRE:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

%.o: %.c 
	${CC} ${CFLAGS} $(INC) -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all
