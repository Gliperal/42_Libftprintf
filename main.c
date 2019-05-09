#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

void test(char *str, ...)
{
	t_list *printables = read_format_string(str);
	va_list ap;
	va_start(ap, str);
	extract_args(printables, ap);
	ft_lstiter(printables, &put_printable);
	va_end(ap);
}

int	main()
{
	t_list *printables;

/*	printables = read_format_string("hello%2$+.*1$dworld%3$+.*1$c\n");
	ft_lstiter(printables, &put_printable);
	extract_args(printables, 0);*/
	test("hello%+.4dworld%+.10c\n");

	return (0);



	// all the cases from the other tests
	// strings with a null terminator in the middle (use precision)
}
