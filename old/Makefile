CC=gcc
CFLAGS=-Wall -Wextra -Werror
CSRC=ft_printf.c ft_format_char.c ft_format_unknown.c ft_format_percent.c \
	ft_putnchar.c
	# Move this to libft
OBJS=ft_printf.o ft_format_char.o ft_format_unknown.o ft_format_percent.o \
	ft_putnchar.o
	# Move this to libft
GCH=libftprintf.gch
AR=ar rcs
RM=rm -rf
NAME=libftprintf.a

$(NAME):
	$(CC) $(CFLAGS) -c $(CSRC)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(GCH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: re
	$(CC) test.c -L. -lftprintf -o test
