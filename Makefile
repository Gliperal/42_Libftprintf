CC=gcc
CFLAGS=-Wall -Wextra
CSRC=ft_printf.c \
	 printable.c \
	 arglist.c build_arglist.c inject_args.c \
	 read_format_string.c read_placeholder.c \
	 readers.c sizers.c dispatchers.c
OBJS=ft_printf.o \
	 printable.o \
	 arglist.o build_arglist.o inject_args.o \
	 read_format_string.o read_placeholder.o \
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
