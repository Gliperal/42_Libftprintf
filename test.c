#include <stdio.h>
#include "libftprintf.h"

int main()
{
//	ft_printf("hello%2$+.*1$cworld%3$+.*1$c\n", 8, 'a', 'b');
//	ft_printf("hello%+.*cworld%+.10c\n", 4, 'a', 'b');

	/* Basic argument test */

	char *str = "42";
	ft_printf("|%c|%s|%p|%d|%i|%o|%u|%x|%X|%f|%%|\n", 'c', str, str, 42, 42, 42, 42, 42, 42, 42);

	/* Format string tests */

	/*
	ft_printf("[%d]\n", 42);
	ft_printf("[%+d]\n", 42);
	ft_printf("[%10d]\n", 42);
	ft_printf("[%-10d]\n", 42);
	ft_printf("[%.10d]\n", 42);
	ft_printf("[% .10d]\n", 42);
	ft_printf("[%10.4d]\n", 42);
	ft_printf("[%-10.4d]\n", 42);

	ft_printf("[%ld]\n", 4242424242);
	ft_printf("[% ld]\n", 4242424242);
	ft_printf("[%9ld]\n", 4242424242);
	ft_printf("[%010ld]\n", 4242424242);
	ft_printf("[%.9ld]\n", 4242424242);
	ft_printf("[%-.10ld]\n", 4242424242);
	ft_printf("[%10.4ld]\n", 4242424242);
	ft_printf("[%+20.10ld]\n", 4242424242);
	*/

	// Flags overriding flags
	// More than one of the same flag
	// negative arg field width overriding flags
	// Are zeros allowed to start positional arguments or non-positional precision?
	// Throw some special characters in the string that aren't part of a format argument
	// I'm just not gonna worry about fied width / precision above INT_MAX - 1 (2147483646)
	// Specific flag tests
	// default precision for floats = 6
	// plus at the end of a number
	// field width / flags / precision on %
	// strings with a null terminator in the middle (use precision)
	// test p in both the malloc block and the stack

	/* Flag tests */
	/* the default printf doesn't seem to be able to use appostrophe correctly */

//	printf("[%#-+'#-+'10.2f]\n", (double) 4242);
//	printf("[%.0f]\n", 42.1234567);
//	printf("[%f]\n", 42.1234567);

	/* Accessed arg tests */

//	printf("[%1$d,%2$d]\n", 4, 2);
//	printf("[%2$d,%1$d]\n", 2, 4);
//	printf("[%1$c,%1$c]\n", 'a');
	// Accessed field width and precision

//	printf("[%18446744073709551615d]\n", 1);
//	printf("[%9750000000000000000d]\n", 1);

	while(1) {}

}
