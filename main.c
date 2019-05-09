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

	test("hello%2$+.*1$cworld%3$+.*1$c\n", 8, 'a', 'b');
//	test("hello%+.*cworld%+.10c\n", 4, 'a', 'b');

	return (0);
}
