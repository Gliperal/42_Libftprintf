CC=gcc
CFLAGS=-Wall -Wextra
CSRC=ft_printf.c \
	 printable.c \
	 read_format_string.c read_placeholder.c \
	 arglist.c \
	 readers.c sizers.c dispatchers.c
OBJS=ft_printf.o \
	 printable.o \
	 read_format_string.o read_placeholder.o \
	 arglist.o \
	 readers.o sizers.o dispatchers.o
GCH=libftprintf.gch
AR=ar rcs
RM=rm -rf
NAME=libftprintf.a

$(NAME):
	$(CC) $(CFLAGS) -c $(CSRC) -I libft
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(GCH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

libft/libft.a:
	make -C libft re
	make -C libft clean

test: re libft/libft.a
	$(CC) main.c -I libft -L. -lftprintf -Llibft -lft -o test
