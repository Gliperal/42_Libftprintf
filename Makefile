CC=gcc
CFLAGS=-Wall -Wextra
CSRC=ft_printf.c \
	 printable.c \
	 arglist.c build_arglist.c inject_args.c \
	 read_format_string.c read_placeholder.c \
	 readers.c sizers.c dispatchers.c \
	 format_char.c format_str.c format_percent.c format_hexadecimal.c format_pointer.c format_octal.c format_unsigned_decimal.c format_decimal.c \
	 pad_printable.c \
	 testing.c
OBJS=ft_printf.o \
	 printable.o \
	 arglist.o build_arglist.o inject_args.o \
	 read_format_string.o read_placeholder.o \
	 readers.o sizers.o dispatchers.o \
	 format_char.o format_str.o format_percent.o format_hexadecimal.o format_pointer.o format_octal.o format_unsigned_decimal.o format_decimal.o \
	 pad_printable.o \
	 testing.o
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
	$(CC) test.c -I libft -L. -lftprintf -Llibft -lft -o test
	$(RM) $(OBJS)

tclean: fclean
	make -C libft fclean
	$(RM) test
