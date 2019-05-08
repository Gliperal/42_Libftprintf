CC=gcc
CFLAGS=-Wall -Wextra
CSRC=ft_printf.c printable.c read_format_string.c read_placeholder.c extract_args.c
OBJS=ft_printf.o printable.o read_format_string.o read_placeholder.o extract_args.o
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

test: re
	$(CC) main.c -I libft -L. -lftprintf -Llibft -lft -o test
