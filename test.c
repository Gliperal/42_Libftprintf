#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"


/* Basic argument test */

void basic()
{
	char *str = "42";
	ft_printf("|%c|%s|%p|%d|%i|%o|%u|%x|%X|%f|%%|\n", 'c', str, str, 42, 42, 42, 42, 42, 42, (double) 42);
	printf("|%c|%s|%p|%d|%i|%o|%u|%x|%X|%f|%%|\n", 'c', str, str, 42, 42, 42, 42, 42, 42, (double) 42);
}


/* Char tests */

void character()
{
}


/* String tests */

void string()
{
	// strings with a null terminator in the middle (use precision)
}


/* Pointer tests */

void pointer()
{
	// null pointer
	// test p in both the malloc block and the stack
}


/* Decimal tests */

void decimal()
{
	ft_printf("%d\n", 0);
	printf("%d\n", 0);
	ft_printf("%d\n", 1);
	printf("%d\n", 1);
	ft_printf("%d\n", 42);
	printf("%d\n", 42);
	ft_printf("%d\n", 9001);
	printf("%d\n", 9001);
	ft_printf("%d\n", INT_MAX);
	printf("%d\n", INT_MAX);
	ft_printf("%ld\n", (long) INT_MAX + 1);
	printf("%ld\n", (long) INT_MAX + 1);
	ft_printf("%ld\n", LONG_MAX);
	printf("%ld\n", LONG_MAX);
	ft_printf("%d\n", -1);
	printf("%d\n", -1);
	ft_printf("%d\n", -42);
	printf("%d\n", -42);
	ft_printf("%d\n", -9001);
	printf("%d\n", -9001);
	ft_printf("%d\n", INT_MIN);
	printf("%d\n", INT_MIN);
	ft_printf("%ld\n", (long) INT_MIN - 1);
	printf("%ld\n", (long) INT_MIN - 1);
	ft_printf("%ld\n", LONG_MIN);
	printf("%ld\n", LONG_MIN);

	ft_printf("%i\n", 0);
	printf("%i\n", 0);
	ft_printf("%i\n", 1);
	printf("%i\n", 1);
	ft_printf("%i\n", 42);
	printf("%i\n", 42);
	ft_printf("%i\n", 9001);
	printf("%i\n", 9001);
	ft_printf("%i\n", INT_MAX);
	printf("%i\n", INT_MAX);
	ft_printf("%li\n", (long) INT_MAX + 1);
	printf("%li\n", (long) INT_MAX + 1);
	ft_printf("%li\n", LONG_MAX);
	printf("%li\n", LONG_MAX);
	ft_printf("%i\n", -1);
	printf("%i\n", -1);
	ft_printf("%i\n", -42);
	printf("%i\n", -42);
	ft_printf("%i\n", -9001);
	printf("%i\n", -9001);
	ft_printf("%i\n", INT_MIN);
	printf("%i\n", INT_MIN);
	ft_printf("%li\n", (long) INT_MIN - 1);
	printf("%li\n", (long) INT_MIN - 1);
	ft_printf("%li\n", LONG_MIN);
	printf("%li\n", LONG_MIN);
}


/* Octal number tests */

void octal()
{
	ft_printf("%lo\n", LONG_MAX);
	printf("%lo\n", LONG_MAX);
	ft_printf("%lo\n", ((long) INT_MAX) + 1);
	printf("%lo\n", ((long) INT_MAX) + 1);
	ft_printf("%o\n", INT_MAX);
	printf("%o\n", INT_MAX);
	ft_printf("%o\n", 16434824);
	printf("%o\n", 16434824);
	ft_printf("%o\n", 34);
	printf("%o\n", 34);
	ft_printf("%o\n", 1);
	printf("%o\n", 1);
	ft_printf("%o\n", 0);
	printf("%o\n", 0);
	ft_printf("%o\n", -1);
	printf("%o\n", -1);
	ft_printf("%o\n", -30);
	printf("%o\n", -30);
	ft_printf("%o\n", -1665406182);
	printf("%o\n", -1665406182);
	ft_printf("%o\n", INT_MIN);
	printf("%o\n", INT_MIN);
	ft_printf("%lo\n", ((long) INT_MIN) - 1);
	printf("%lo\n", ((long) INT_MIN) - 1);
	ft_printf("%lo\n", LONG_MIN);
	printf("%lo\n", LONG_MIN);
}


/* Unsigned decimal tests */

void unsigned_decimal()
{
	ft_printf("%lu\n", LONG_MAX);
	printf("%lu\n", LONG_MAX);
	ft_printf("%lu\n", ((long) INT_MAX) + 1);
	printf("%lu\n", ((long) INT_MAX) + 1);
	ft_printf("%u\n", INT_MAX);
	printf("%u\n", INT_MAX);
	ft_printf("%u\n", 1234567890);
	printf("%u\n", 1234567890);
	ft_printf("%u\n", 42);
	printf("%u\n", 42);
	ft_printf("%u\n", 1);
	printf("%u\n", 1);
	ft_printf("%u\n", 0);
	printf("%u\n", 0);
	ft_printf("%u\n", -1);
	printf("%u\n", -1);
	ft_printf("%u\n", -52543054);
	printf("%u\n", -52543054);
	ft_printf("%u\n", INT_MIN);
	printf("%u\n", INT_MIN);
	ft_printf("%lu\n", ((long) INT_MIN) - 1);
	printf("%lu\n", ((long) INT_MIN) - 1);
	ft_printf("%lu\n", LONG_MIN);
	printf("%lu\n", LONG_MIN);
}


/* Hexadecimal tests */

void hexadecimal()
{
	ft_printf("%x\n", 0);
	printf("%x\n", 0);
	ft_printf("%x\n", 1);
	printf("%x\n", 1);
	ft_printf("%x\n", 66);
	printf("%x\n", 66);
	ft_printf("%x\n", 43981);
	printf("%x\n", 43981);
	ft_printf("%x\n", INT_MAX);
	printf("%x\n", INT_MAX);
	ft_printf("%lx\n", (long) INT_MAX + 1);
	printf("%lx\n", (long) INT_MAX + 1);
	ft_printf("%lx\n", LONG_MAX);
	printf("%lx\n", LONG_MAX);
	ft_printf("%lx\n", ULONG_MAX);
	printf("%lx\n", ULONG_MAX);
	ft_printf("%x\n", -1);
	printf("%x\n", -1);
	ft_printf("%x\n", -230538686);
	printf("%x\n", -230538686);
	ft_printf("%x\n", INT_MIN);
	printf("%x\n", INT_MIN);
	ft_printf("%lx\n", LONG_MIN);
	printf("%lx\n", LONG_MIN);
}


/* Format string tests */

void format_string()
{
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

	// Throw some special characters in the string that aren't part of a format argument
	// plus at the end of a number
	// Some tests with no newline at the end
}


/* Char format tests */

void char_f()
{
}


/* String format tests */

void string_f()
{
}


/* Pointer format tests */

void pointer_f()
{
}


/* Decimal tests */

void decimal_f()
{
	ft_printf("#%d\n", 42);
	printf("#%d\n", 42);
	ft_printf("+%d\n", 42);
	printf("+%d\n", 42);
	ft_printf("+%d\n", -42);
	printf("+%d\n", -42);
	ft_printf("+%d\n", 0);
	printf("+%d\n", 0);
	ft_printf(" %d\n", 42);
	printf(" %d\n", 42);
	ft_printf("% d\n", -42);
	printf("% d\n", -42);
	ft_printf("% d\n", 0);
	printf("% d\n", 0);
}


/* Octal format tests */

void octal_f()
{
	ft_printf("%#o\n", 342391);
	printf("%#o\n", 342391);
	ft_printf("%#o\n", 0);
	printf("%#o\n", 0);
	ft_printf("%lu\n", ULONG_MAX);
	printf("%lu\n", ULONG_MAX);
	ft_printf("%hho\n", (char) -94);
	printf("%hho\n", (char) -94);
	ft_printf("%ho\n", (short) -42);
	printf("%ho\n", (short) -42);
}


/* Unsigned decimal format tests */

void unsigned_f()
{
	ft_printf("%hhu\n", (char) -114);
	printf("%hhu\n", (char) -114);
	ft_printf("%hu\n", (short) -42);
	printf("%hu\n", (short) -42);
	ft_printf("%lu\n", (long) -42);
	printf("%lu\n", (long) -42);
}


/* Hexadecimal format tests */

void hexadecimal_f()
{
}


/* Flag tests */

void flags()
{
	// Flags overriding flags
	ft_printf("[%#-+'#-+'10.2f]\n", (double) 4242);
	ft_printf("[%.0f]\n", 42.1234567);
	ft_printf("[%f]\n", 42.1234567);
	// More than one of the same flag
	// negative arg field width overriding flags
	// Are zeros allowed to start positional arguments or non-positional precision?
	// field width / flags / precision on %
}


/* Flag specific tests */

void flags2()
{
	/* the default printf doesn't seem to be able to use appostrophe correctly */
	// ft_printf("%'d\n", 42424242);
	// printf("%'d\n", 42424242);
}


/* Field width tests */

void field_width()
{
	char *ptr = "";
	ft_printf("[%10c]\n", 'c');
	printf("[%10c]\n", 'c');
	ft_printf("[%10s]\n", "hi there");
	printf("[%10s]\n", "hi there");
	ft_printf("[%20p]\n", ptr);
	printf("[%20p]\n", ptr);
	ft_printf("[%10d]\n", 42);
	printf("[%10d]\n", 42);
	ft_printf("[%10i]\n", 42);
	printf("[%10i]\n", 42);
	ft_printf("[%10o]\n", 34);
	printf("[%10o]\n", 34);
	ft_printf("[%10u]\n", 42);
	printf("[%10u]\n", 42);
	ft_printf("[%10x]\n", 66);
	printf("[%10x]\n", 66);
	ft_printf("[%10X]\n", 66);
	printf("[%10X]\n", 66);
//	ft_printf("[%10f]\n", 42.42);
//	printf("[%10f]\n", 42.42);
	ft_printf("[%10%]\n");
	printf("[%10%]\n");

	ft_printf("[%010d]\n", -42);
	printf("[%010d]\n", -42);
	ft_printf("[%0+10d]\n", -42);
	printf("[%0+10d]\n", -42);
	ft_printf("[%0+10d]\n", 42);
	printf("[%0+10d]\n", 42);
	ft_printf("[%0 10d]\n", 42);
	printf("[%0 10d]\n", 42);
	ft_printf("[%010.4d]\n", 42);
	printf("[%010.4d]\n", 42);
	ft_printf("[%010.4u]\n", 42);
	printf("[%010.4u]\n", 42);
	ft_printf("[%010.0u]\n", 42);
	printf("[%010.0u]\n", 42);
	ft_printf("[%10s]\n", "abcd");
	printf("[%10s]\n", "abcd");

	ft_printf("[%-10d]\n", -42);
	printf("[%-10d]\n", -42);
	ft_printf("[%-+10d]\n", -42);
	printf("[%-+10d]\n", -42);
	ft_printf("[%-+10d]\n", 42);
	printf("[%-+10d]\n", 42);
	ft_printf("[%- 10d]\n", 42);
	printf("[%- 10d]\n", 42);
	ft_printf("[%-10.4d]\n", 42);
	printf("[%-10.4d]\n", 42);
	ft_printf("[%-10.4u]\n", 42);
	printf("[%-10.4u]\n", 42);
	ft_printf("[%-10s]\n", "abcd");
	printf("[%-10s]\n", "abcd");

	ft_printf("[%02d]\n", -42);
	printf("[%02d]\n", -42);
	ft_printf("[%0+2d]\n", -42);
	printf("[%0+2d]\n", -42);
	ft_printf("[%0+2d]\n", 42);
	printf("[%0+2d]\n", 42);
	ft_printf("[%0 2d]\n", 42);
	printf("[%0 2d]\n", 42);
	ft_printf("[%03.4d]\n", 42);
	printf("[%03.4d]\n", 42);
	ft_printf("[%03.4u]\n", 42);
	printf("[%03.4u]\n", 42);
	ft_printf("[%3s]\n", "abcd");
	printf("[%3s]\n", "abcd");

	/* I'm just not gonna worry about fied width / precision above INT_MAX - 1 (2147483646) */
	//printf("[%18446744073709551615d]\n", 1);
	//printf("[%9750000000000000000d]\n", 1);
}


/* Precision tests */

void precision()
{
	ft_printf("%s\n", "Hello world.");
	printf("%s\n", "Hello world.");
	ft_printf("%.s\n", "Hello world.");
	printf("%.s\n", "Hello world.");
	ft_printf("%.0s\n", "Hello world.");
	printf("%.0s\n", "Hello world.");
	ft_printf("%.4s\n", "Hello world.");
	printf("%.4s\n", "Hello world.");

	ft_printf("%.0d\n", 42);
	printf("%.0d\n", 42);
	ft_printf("%.1d\n", 42);
	printf("%.1d\n", 42);
	ft_printf("%.2d\n", 42);
	printf("%.2d\n", 42);
	ft_printf("%.3d\n", 42);
	printf("%.3d\n", 42);
	ft_printf("%.10d\n", 42);
	printf("%.10d\n", 42);

	ft_printf("%.0d\n", -42);
	printf("%.0d\n", -42);
	ft_printf("%.1d\n", -42);
	printf("%.1d\n", -42);
	ft_printf("%.2d\n", -42);
	printf("%.2d\n", -42);
	ft_printf("%.3d\n", -42);
	printf("%.3d\n", -42);
	ft_printf("%.10d\n", -42);
	printf("%.10d\n", -42);

	ft_printf("%.0i\n", 42);
	printf("%.0i\n", 42);
	ft_printf("%.2i\n", 42);
	printf("%.2i\n", 42);
	ft_printf("%.4i\n", 42);
	printf("%.4i\n", 42);

	ft_printf("%.0o\n", 34);
	printf("%.0o\n", 34);
	ft_printf("%.2o\n", 34);
	printf("%.2o\n", 34);
	ft_printf("%.4o\n", 34);
	printf("%.4o\n", 34);
	ft_printf("%#.4o\n", 34);
	printf("%#.4o\n", 34);
	ft_printf("%#.3o\n", 34);
	printf("%#.3o\n", 34);
	ft_printf("%#.2o\n", 34);
	printf("%#.2o\n", 34);

	ft_printf("%.0u\n", 42);
	printf("%.0u\n", 42);
	ft_printf("%.2u\n", 42);
	printf("%.2u\n", 42);
	ft_printf("%.4u\n", 42);
	printf("%.4u\n", 42);

	ft_printf("%.0x\n", 66);
	printf("%.0x\n", 66);
	ft_printf("%.2x\n", 66);
	printf("%.2x\n", 66);
	ft_printf("%.4x\n", 66);
	printf("%.4x\n", 66);

	ft_printf("%.0X\n", 66);
	printf("%.0X\n", 66);
	ft_printf("%.2X\n", 66);
	printf("%.2X\n", 66);
	ft_printf("%.4X\n", 66);
	printf("%.4X\n", 66);

	ft_printf("%#.1x\n", 66);
	printf("%#.1x\n", 66);
	ft_printf("%#.2X\n", 66);
	printf("%#.2X\n", 66);
	ft_printf("%#.3x\n", 66);
	printf("%#.3x\n", 66);
	ft_printf("%#.8X\n", 66);
	printf("%#.8X\n", 66);

	// default precision for floats = 6
}


/* Accessed arg tests */

void aa()
{
	printf("[%1$d,%2$d]\n", 4, 2);
	printf("[%2$d,%1$d]\n", 2, 4);
	printf("[%1$c,%1$c]\n", 'a');
	// Accessed field width and precision
}


typedef void	(*t_group)(void);

static const t_group g_test_groups[] =
{
	/*  0 */	&basic,
	/*  1 */	&character,
	/*  2 */	&string,
	/*  3 */	&pointer,
	/*  4 */	&decimal,
	/*  5 */	&octal,
	/*  6 */	&unsigned_decimal,
	/*  7 */	&hexadecimal,
	/*  8 */	&format_string,
	/*  9 */	&char_f,
	/* 10 */	&string_f,
	/* 11 */	&pointer_f,
	/* 12 */	&decimal_f,
	/* 13 */	&octal_f,
	/* 14 */	&unsigned_f,
	/* 15 */	&hexadecimal_f,
	/* 16 */	&flags,
	/* 17 */	&flags2,
	/* 18 */	&field_width,
	/* 19 */	&precision,
	/* 20 */	&aa
};

int main()
{
	int tests[] = {18, 19, -1};

	for (int i = 0; tests[i] != -1; i++)
	{
		int test_id = tests[i];
		t_group test_group = g_test_groups[test_id];
		(*test_group)();
	}

	/* Leaks test */
	while(1) {}
}
