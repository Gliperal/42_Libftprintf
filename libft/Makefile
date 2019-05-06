CC=gcc
CFLAGS=-Wall -Wextra -Werror
CSRC=*.c
OBJS=*.o
AR=ar rcs
RM=rm -rf
NAME=libft.a

$(NAME):
	$(CC) $(CFLAGS) -c $(CSRC)
	$(AR) libft.a $(OBJS)

all: $(NAME)

clean:
	$(RM) *.o
	$(RM) *.gch

fclean: clean 
	$(RM) libft.a

re: fclean all
