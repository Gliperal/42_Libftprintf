#include <stdio.h>

#include "exact_float.h"

int main()
{
//	double d = (double) 4 / 3;
//	t_exact_float *f = double_to_exact_float(d);
	long double d = (long double) 4 / 3;
	t_exact_float *f = longdouble_to_exact_float(d);
	for(int i = 0; i < f->integer.size; i++)
		printf("%.8x ", f->integer.value[i]);
	printf(".");
	for(int i = 0; i < f->fraction.size; i++)
		printf(" %.8x", f->fraction.value[i]);
	printf("\n");
}
