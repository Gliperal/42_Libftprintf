#include "libftprintf.h"
#include <stdarg.h>
void		extract_args(t_list *printables, va_list *ap);

int	main()
{
	t_list *printables;

	printables = read_format_string("hello%2$+.*1$dworld%3$+.*1$c\n");
	ft_lstiter(printables, &put_printable);
	extract_args(printables, 0);
/*	printables = read_format_string("hello%+.*dworld%+.10c\n");
	ft_lstiter(printables, &put_printable);
	extract_args(printables, 0);
	printables = read_format_string("hello%+.40dworld%+.*1$c\n");
	ft_lstiter(printables, &put_printable);
	extract_args(printables, 0);*/
}
