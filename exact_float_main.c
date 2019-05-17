#include <stdio.h>

#include "exact_float.h"
#include "libft.h"

void test(double d, int precision)
{
	t_exact_float *f = longdouble_to_exact_float(d);
/*	for(int i = 0; i < f->integer.size; i++)
		printf("%.8x ", f->integer.value[i]);
	printf(".");
	for(int i = 0; i < f->fraction.size; i++)
		printf(" %.8x", f->fraction.value[i]);
	printf("\n");*/
	printf("%s.%s\n", integer_to_string(&(f->integer)), fraction_to_string(&(f->fraction), precision));
}

void testl(long double d, int precision)
{
	t_exact_float *f = longdouble_to_exact_float(d);
	printf("%s.%s\n", integer_to_string(&(f->integer)), fraction_to_string(&(f->fraction), precision));
}

int main()
{
	double d = (double) 9.9999815;
	test(d, 6);
	printf("%.6f\n", d);




	double double_max;
	long data = 0x7fefffffffffffff;
	ft_memcpy(&double_max, &data, sizeof(double));
	test(double_max, 6);
	printf("%f\n", double_max);
}
