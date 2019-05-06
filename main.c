#include "libftprintf.h"

int	main()
{
	t_list *printables = read_format_string("hello%2$+.*1$dworld%3$+.*1$u\n");
	ft_lstiter(printables, &put_printable);
}
