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
	ft_printf("%c\n", 'A');
	printf("%c\n", 'A');
	ft_printf("%c\n", 'z');
	printf("%c\n", 'z');
	ft_printf("%c\n", '!');
	printf("%c\n", '!');
	ft_printf("%c%c%c%c%c%c", ' ', '4', '\13', '~', '2', '\n');
	printf("%c%c%c%c%c%c", ' ', '4', '\13', '~', '2', '\n');
}


/* String tests */

void string()
{
	char *str = "Hello world.";
	ft_printf("%s\n", str);
	printf("%s\n", str);
	char *str2 = "Hello world.\0Goodbye world.";
	ft_printf("%.27s\n", str2);
	printf("%.27s\n", str2);
	char *empty = "";
	ft_printf("Empty str%sing\n", empty);
	printf("Empty str%sing\n", empty);
}


/* Pointer tests */

void pointer()
{
	void *null = NULL;
	ft_printf("%p\n", null);
	printf("%p\n", null);
	void *stack = "";
	void *heap = malloc(1);
	ft_printf("%p\n", stack);
	printf("%p\n", stack);
	ft_printf("%p\n", heap);
	printf("%p\n", heap);
	free(heap);
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


/* Double precision floating point tests */

double	make_double(long data)
{
	double result;
	ft_memcpy(&result, &data, sizeof(double));
	return (result);
}

long double	make_longdouble(unsigned long data1, unsigned long data2)
{
	unsigned long data[2];
	data[0] = data2;
	data[1] = data1;
	long double result;
	ft_memcpy(&result, data, sizeof(long double));
	return (result);
}

void floats()
{
	ft_printf("%f\n", 42.42);
	printf("%f\n", 42.42);

	double double_max = make_double(0x7fefffffffffffff);
	ft_printf("%f\n", double_max);
	printf("%f\n", double_max);
	double double_min = make_double(0x0010000000000000);
	ft_printf("%.1050F\n", double_min);
	printf("%.1050F\n", double_min);
	double positive_zero = make_double(0x0000000000000000);
	ft_printf("%f\n", positive_zero);
	printf("%f\n", positive_zero);
	double negative_zero = make_double(0x8000000000000000);
	ft_printf("%F\n", negative_zero);
	printf("%F\n", negative_zero);
	double subnormal_min = make_double(0x8000000000000001);
	ft_printf("%.1100f\n", subnormal_min);
	printf("%.1100f\n", subnormal_min);
	double subnormal_max = make_double(0x0001111111111111);
	ft_printf("%.1100F\n", subnormal_max);
	printf("%.1100F\n", subnormal_max);
	double positive_inf = make_double(0x7ff0000000000000);
	ft_printf("%f\n", positive_inf);
	printf("%f\n", positive_inf);
	double negative_inf = make_double(0xfff0000000000000);
	ft_printf("%F\n", negative_inf);
	printf("%F\n", negative_inf);
	double nan = make_double(0xffffffffffffffff);
	ft_printf("%f\n", nan);
	printf("%f\n", nan);

	long double longdouble_max = make_longdouble(0x0000000000007ffe, 0xffffffffffffffff);
	ft_printf("%Lf\n", longdouble_max);
	printf("%Lf\n", longdouble_max);
	long double longdouble_min = make_longdouble(0x0000000000000001, 0x8000000000000001);
	ft_printf("%.17000LF\n", longdouble_min);
	printf("%.17000LF\n", longdouble_min);
	long double pseudodenormal_min = make_longdouble(0x0000000000000000, 0x8000000000000001);
	ft_printf("%.17000Lf\n", pseudodenormal_min);
	printf("%.17000Lf\n", pseudodenormal_min);
	long double denormal_min = make_longdouble(0x0000000000008000, 0x0000000000000001);
	ft_printf("%.17000LF\n", denormal_min);
	printf("%.17000LF\n", denormal_min);
	long double positive_longzero = make_longdouble(0x0000000000000000, 0x0000000000000000);
	ft_printf("%Lf\n", positive_longzero);
	printf("%Lf\n", positive_longzero);
	long double negative_longzero = make_longdouble(0x0000000000008000, 0x0000000000000000);
	ft_printf("%LF\n", negative_longzero);
	printf("%LF\n", negative_longzero);
}
	
void floats_part2()
{
	long double pos_pseudo_inf = make_longdouble(0x0000000000007fff, 0x0000000000000000);
	ft_printf("%LF\n", pos_pseudo_inf);
	printf("%LF\n", pos_pseudo_inf);
	long double neg_pseudo_inf = make_longdouble(0x000000000000ffff, 0x0000000000000000);
	ft_printf("%Lf\n", neg_pseudo_inf);
	printf("%Lf\n", neg_pseudo_inf);
	long double pos_long_inf = make_longdouble(0x0000000000007fff, 0x8000000000000000);
	ft_printf("%LF\n", pos_long_inf);
	printf("%LF\n", pos_long_inf);
	long double neg_long_inf = make_longdouble(0x000000000000ffff, 0x8000000000000000);
	ft_printf("%Lf\n", neg_long_inf);
	printf("%Lf\n", neg_long_inf);

	long double longnan1 = make_longdouble(0x0000000000007fff, 0x0000000000000001);
	ft_printf("%Lf\n", longnan1);
	printf("%Lf\n", longnan1);
	long double longnan2 = make_longdouble(0x0000000000007fff, 0x4000000000000000);
	ft_printf("%LF\n", longnan2);
	printf("%LF\n", longnan2);
	long double longnan3 = make_longdouble(0x0000000000007fff, 0x7fffffffffffffff);
	ft_printf("%Lf\n", longnan3);
	printf("%Lf\n", longnan3);
	long double longnan4 = make_longdouble(0x0000000000007fff, 0x8000000000000001);
	ft_printf("%LF\n", longnan4);
	printf("%LF\n", longnan4);
	long double longnan5 = make_longdouble(0x0000000000007fff, 0xc000000000000000);
	ft_printf("%Lf\n", longnan5);
	printf("%Lf\n", longnan5);
	long double longnan6 = make_longdouble(0x0000000000007fff, 0xc000000000000001);
	ft_printf("%LF\n", longnan6);
	printf("%LF\n", longnan6);

	ft_printf("%F\n", .42);
	printf("%F\n", .42);
	ft_printf("%f\n", 41.9999999);
	printf("%f\n", 41.9999999);
	ft_printf("%.F\n", 99.99);
	printf("%.F\n", 99.99);
	ft_printf("%.1f\n", 0.05);
	printf("%.1f\n", 0.05);
}


/* Format string tests */

void format_string()
{
	ft_printf("[%d]\n", 42);
	printf("[%d]\n", 42);
	ft_printf("[%+d]\n", 42);
	printf("[%+d]\n", 42);
	ft_printf("[%10d]\n", 42);
	printf("[%10d]\n", 42);
	ft_printf("[%-10d]\n", 42);
	printf("[%-10d]\n", 42);
	ft_printf("[%.10d]\n", 42);
	printf("[%.10d]\n", 42);
	ft_printf("[% .10d]\n", 42);
	printf("[% .10d]\n", 42);
	ft_printf("[%10.4d]\n", 42);
	printf("[%10.4d]\n", 42);
	ft_printf("[%-10.4d]\n", 42);
	printf("[%-10.4d]\n", 42);

	ft_printf("[%ld]\n", 4242424242);
	printf("[%ld]\n", 4242424242);
	ft_printf("[% ld]\n", 4242424242);
	printf("[% ld]\n", 4242424242);
	ft_printf("[%19ld]\n", 4242424242);
	printf("[%19ld]\n", 4242424242);
	ft_printf("[%020ld]\n", 4242424242);
	printf("[%020ld]\n", 4242424242);
	ft_printf("[%.19ld]\n", 4242424242);
	printf("[%.19ld]\n", 4242424242);
	ft_printf("[%-.20ld]\n", 4242424242);
	printf("[%-.20ld]\n", 4242424242);
	ft_printf("[%20.4ld]\n", 4242424242);
	printf("[%20.4ld]\n", 4242424242);
	ft_printf("[%+20.10ld]\n", 4242424242);
	printf("[%+20.10ld]\n", 4242424242);

	// Throw some special characters in the string that aren't part of a format argument
	// plus at the end of a number
	// Some tests with no newline at the end
}


/* Char format tests */

void char_f()
{
	ft_printf("[%10c]\n", 'c');
	printf("[%10c]\n", 'c');
	ft_printf("[%-10c]\n", 'c');
	printf("[%-10c]\n", 'c');
}


/* String format tests */

void string_f()
{
	char *str = "abc def ghi jkl mno pqr stu";
	ft_printf("[%10.11s]\n", str);
	printf("[%10.11s]\n", str);
	ft_printf("[%-10.7s]\n", str);
	printf("[%-10.7s]\n", str);
}


/* Pointer format tests */

void pointer_f()
{
	char *ptr = "";
	ft_printf("[%20p]\n", ptr);
	printf("[%20p]\n", ptr);
/*	ft_printf("[%# -10p]\n", ptr);
	printf("[%# -10p]\n", ptr);
	ft_printf("[%0+5.5p]\n", ptr);
	printf("[%0+5.5p]\n", ptr);*/
}


/* Decimal tests */

void decimal_f()
{
	ft_printf("%+d\n", 42);
	printf("%+d\n", 42);
	ft_printf("%+d\n", -42);
	printf("%+d\n", -42);
	ft_printf("%+d\n", 0);
	printf("%+d\n", 0);
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
	ft_printf("[%#10x]\n", 42);
	printf("[%#10x]\n", 42);
	ft_printf("[%0#10x]\n", 42);
	printf("[%0#10x]\n", 42);
	ft_printf("[%0#10.6x]\n", 42);
	printf("[%0#10.6x]\n", 42);
}


/* Double precision floating point format tests */

void floats_f()
{
	ft_printf("[%10f]\n", .42);
	printf("[%10f]\n", .42);
	ft_printf("[%10.F]\n", 42.0);
	printf("[%10.F]\n", 42.0);
	ft_printf("[%#10.f]\n", 42.0);
	printf("[%#10.f]\n", 42.0);
	ft_printf("[%+20F]\n", 42.42);
	printf("[%+20F]\n", 42.42);
	ft_printf("[%+20f]\n", -42.42);
	printf("[%+20f]\n", -42.42);
	ft_printf("[%+20F]\n", 0.0);
	printf("[%+20F]\n", 0.0);
	ft_printf("[% 20f]\n", 42.42);
	printf("[% 20f]\n", 42.42);
	ft_printf("[% 20F]\n", -42.42);
	printf("[% 20F]\n", -42.42);
	ft_printf("[% 20f]\n", 0.0);
	printf("[% 20f]\n", 0.0);
	ft_printf("[%-20F]\n", 42.42);
	printf("[%-20F]\n", 42.42);
	ft_printf("[%-20f]\n", 42.42);
	printf("[%-20f]\n", 42.42);
	ft_printf("[%+020F]\n", 42.42);
	printf("[%+020F]\n", 42.42);
	ft_printf("[%020f]\n", 42.42);
	printf("[%020f]\n", 42.42);

	ft_printf("%Lf\n", (long double) 42.42);
	printf("%Lf\n", (long double) 42.42);

	// test field width on special cases
}


/* Flag tests */

void flags()
{
	// Flags overriding flags
	ft_printf("[%#-+'#-+'10.2f]\n", (double) 4242);
	printf("[%#-+'#-+'10.2f]\n", (double) 4242);
	ft_printf("[%'+-#'+-#10.2f]\n", (double) 4242);
	printf("[%'+-#'+-#10.2f]\n", (double) 4242);
	ft_printf("[%.0f]\n", 42.1234567);
	printf("[%.0f]\n", 42.1234567);
	ft_printf("[%f]\n", 42.1234567);
	printf("[%f]\n", 42.1234567);
	ft_printf("[%.04f]\n", 42.1234567);
	printf("[%.04f]\n", 42.1234567);
	// negative arg field width overriding flags
	ft_printf("[%# %]\n");
	printf("[%# %]\n");
	ft_printf("[%+.10%]\n");
	printf("[%+.10%]\n");
	ft_printf("[%10%]\n");
	printf("[%10%]\n");
	ft_printf("[%-10%]\n");
	printf("[%-10%]\n");
	ft_printf("[%010%]\n");
	printf("[%010%]\n");
}


/* Flag specific tests */

void flags2()
{
	/* the default printf doesn't seem to be able to use appostrophe correctly */
	ft_printf("%'d\n", 42424242);
	printf("%'d\n", 42424242);
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
	ft_printf("[%10f]\n", 42.42);
	printf("[%10f]\n", 42.42);
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

	ft_printf("%#.f\n", 42.0);
	printf("%#.f\n", 42.0);
	ft_printf("%#.1F\n", 42.0);
	printf("%#.1F\n", 42.0);
	ft_printf("%#.3f\n", 42.0);
	printf("%#.3f\n", 42.0);
	ft_printf("%#.8F\n", 42.0);
	printf("%#.8F\n", 42.0);
}


/* Accessed arg tests */

void aa()
{
	ft_printf("[%1$d,%2$d]\n", 4, 2);
	printf("[%1$d,%2$d]\n", 4, 2);
	ft_printf("[%2$d,%1$d]\n", 2, 4);
	printf("[%2$d,%1$d]\n", 2, 4);
	ft_printf("[%1$c,%1$c]\n", 'a');
	printf("[%1$c,%1$c]\n", 'a');
	ft_printf("%1$.*2$s%3$.*4$f\n", "Hello world", 6, 42.42, 0);
	printf("%1$.*2$s%3$.*4$f\n", "Hello world", 6, 42.42, 0);
	ft_printf("[%1$*2$i,%3$*2$i]\n", 4, 10, 2);
	printf("[%1$*2$i,%3$*2$i]\n", 4, 10, 2);
	ft_printf("[%02$-*01$i,%03$-*01$i]\n", 10, 4, 2);
	printf("[%02$-*01$i,%03$-*01$i]\n", 10, 4, 2);
	// Are zeros allowed to start positional arguments?
}


/* Extended floats tests */

void more_floats()
{
	ft_printf("%E\n", 4.2);
	printf("%E\n", 4.2);
	ft_printf("%e\n", 4200.0);
	printf("%e\n", 4200.0);
	ft_printf("%E\n", 0.0042);
	printf("%E\n", 0.0042);
	ft_printf("%e\n", 42.0);
	printf("%e\n", 42.0);
	ft_printf("%E\n", .42);
	printf("%E\n", .42);
	ft_printf("%.46e\n", .17);
	printf("%.46e\n", .17);
	ft_printf("%.42e\n", .18);
	printf("%.42e\n", .18);

	double double_max = make_double(0x7fefffffffffffff);
	ft_printf("%E\n", double_max);
	printf("%E\n", double_max);
	double double_min = make_double(0x0010000000000000);
	ft_printf("%.e\n", double_min);
	printf("%.e\n", double_min);
	double negative_zero = make_double(0x8000000000000000);
	ft_printf("%e\n", negative_zero);
	printf("%e\n", negative_zero);
	double positive_inf = make_double(0x7ff0000000000000);
	ft_printf("%e\n", positive_inf);
	printf("%e\n", positive_inf);

	long double longdouble_max = make_longdouble(0x0000000000007ffe, 0xffffffffffffffff);
	ft_printf("%LE\n", longdouble_max);
	printf("%LE\n", longdouble_max);
	long double denormal_min = make_longdouble(0x0000000000008000, 0x0000000000000001);
	ft_printf("%Le\n", denormal_min);
	printf("%Le\n", denormal_min);
	long double negative_longzero = make_longdouble(0x0000000000008000, 0x0000000000000000);
	ft_printf("%Le\n", negative_longzero);
	printf("%Le\n", negative_longzero);
	long double neg_long_inf = make_longdouble(0x000000000000ffff, 0x8000000000000000);
	ft_printf("%LE\n", neg_long_inf);
	printf("%LE\n", neg_long_inf);
	long double longnan1 = make_longdouble(0x0000000000007fff, 0x0000000000000001);
	ft_printf("%LE\n", longnan1);
	printf("%LE\n", longnan1);

	ft_printf("%.e\n", 99.99);
	printf("%.e\n", 99.99);
/*
	ft_printf("%g\n", 424242.0);
	printf("%g\n", 424242.0);
	ft_printf("%g\n", 4424242.0);
	printf("%g\n", 4424242.0);
	ft_printf("%g\n", 0.0);
	printf("%g\n", 0.0);
	ft_printf("%g\n", 0.00042);
	printf("%g\n", 0.00042);
	ft_printf("%g\n", 0.000042);
	printf("%g\n", 0.000042);
	ft_printf("%g\n", double_max);
	printf("%g\n", double_max);
	ft_printf("%Lg\n", denormal_min);
	printf("%Lg\n", denormal_min);
	ft_printf("%Lg\n", negative_longzero);
	printf("%Lg\n", negative_longzero);
	ft_printf("%Lg\n", neg_long_inf);
	printf("%Lg\n", neg_long_inf);
	ft_printf("%.0g\n", 42.0);
	printf("%.0g\n", 42.0);
	ft_printf("%.0g\n", 4.0);
	printf("%.0g\n", 4.0);
	*/
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
	/*  8 */	&floats,
	/*  9 */	&floats_part2,
	/* 10 */	&format_string,
	/* 11 */	&char_f,
	/* 12 */	&string_f,
	/* 13 */	&pointer_f,
	/* 14 */	&decimal_f,
	/* 15 */	&octal_f,
	/* 16 */	&unsigned_f,
	/* 17 */	&hexadecimal_f,
	/* 18 */	&floats_f,
	/* 19 */	&flags,
	/* 20 */	&flags2,
	/* 21 */	&field_width,
	/* 22 */	&precision,
	/* 23 */	&aa,
	/* 24 */	&more_floats
};

int main()
{
	char b[1];
	int tests[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, -1};

	for (int i = 0; tests[i] != -1; i++)
	{
		int test_id = tests[i];
		t_group test_group = g_test_groups[test_id];
		(*test_group)();
		printf("Waiting for input...\n");
		read(0, b, 1);
		printf("\n");
	}
}
