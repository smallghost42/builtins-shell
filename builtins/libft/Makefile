SRCS = ft_strnstr.c ft_strdup.c  ft_strjoin.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_isalnum.c ft_putendl_fd.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_striteri.c ft_putchar_fd.c ft_toupper.c ft_tolower.c ft_putnbr_fd.c ft_split.c ft_strlcpy.c ft_strchr.c ft_strmapi.c ft_strlcat.c  ft_strtrim.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strncmp.c ft_calloc.c ft_substr.c ft_itoa.c ft_putstr_fd.c ft_printf.c ft_is_error.c  ft_putnbr_hex.c ft_putnbr_unsigned.c ft_putnbr_positive_base.c ft_putptr.c ft_strcmp.c ft_is_blank.c ft_isspace.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_printf.c ft_retire_space.c ft_putnbr_decimal.c 

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

bonus:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.phony:		fclean clean all re
		
