#include <stdio.h>
#include <limits.h>

#include "number.h"
#include "fraction.h"

void	print_number(t_number *n)
{
	if (!n || !(n->value))
	{
		printf("(NULL)\n");
		return ;
	}
	for (int i = n->size - 1; i >= 0; i--)
		printf("%.8x", n->value[i]);
	printf("\n");
}

void	print_fraction(t_fraction *n)
{
	if (!n || !(n->value))
	{
		printf("(NULL)\n");
		return ;
	}
	for (int i = 0; i < n->size; i++)
		printf("%.8x", n->value[i]);
	printf("\n");
}

void number()
{
	unsigned int a[] = {0x87654321, 0x3578a2fd};
	unsigned int b[] = {0xd2345678, 0xa205c837};

	t_number *na = new_number(a, 2);
	t_number *nb = new_number(b, 2);

	print_number(na);
	print_number(nb);
	add(na, nb);
	print_number(na);
	left_shift(na, 5);
	print_number(na);

//	unsigned int c[] = {1, 2, 3};
//	unsigned int d[] = {4, 5, 7};
//	unsigned int c[] = {0xffffffff, 0xffffffff, 0xffffffff};
//	unsigned int d[] = {0xffffffff, 0xffffffff, 0xffffffff};
//	unsigned int c[] = {0xeeeeeeee, 0xffffffff, 0xffffffff};
//	unsigned int d[] = {0xdddddddd, 0xffffffff, 0xffffffff};
	unsigned int c[] = {0x11111111, 0x11111111, 0x11111111};
	unsigned int d[] = {0x11111111, 0x11111111, 0x11111111};

	t_number *nc = new_number(c, 3);
	t_number *nd = new_number(d, 3);
	print_number(nc);
	print_number(nd);

	t_number *ne = multiply(nc, nd);
	print_number(ne);

//	unsigned int f[] = {0xffffffff, 0xffffffff};
//	unsigned int f[] = {0x7fffffff, 0xffffffff};
//	t_number *nf = new_number(f, 2);
	unsigned int f[] = {0x0000001, 0x0000000, 0x0000000, 0x0000000, 0x0000000, 0x0000000, 0x0000000, 0x0000000, 0x00000000};
	t_number *nf = new_number(f, 9);
	print_number(nf);
	printf("%s\n", to_string(nf));
}

void fraction()
{
	unsigned int a[] = {0x87654321, 0x3578a2fd};
	t_fraction *na = new_fraction(a, 2);
	print_fraction(na);
	multiply_f(na, 16);
	print_fraction(na);

	unsigned int b[] = {0x00000000, 0x00555555, 0x55550000};
	t_fraction *nb = new_fraction(b, 3);
	printf("%s\n", to_string_f(nb, 90));
}

int main()
{
	number();
	printf("\n");
	fraction();
}
