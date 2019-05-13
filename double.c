#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_float
{
	char			type;
	char			sign;
	int				exponent;
	unsigned long	significand;
}				t_float;

t_float	*parse_double(double d)
{
	char *data;

	t_float *f = (t_float *)malloc(sizeof(t_float));
	if (!f)
		return (NULL);
	data = (char *)(void *)&d;
	f->type = 'd';
	f->sign = ((data[7] & 0x80) >> 7) ? -1 : 1;
	f->exponent = *((short *)(data + 6)) >> 4;
	f->exponent -= 1023;
	f->significand = *((long *)data) & 0xfffffffffffff;
	f->significand |= (long) 1 << 52;
	return (f);
}

t_float	*parse_longdouble(long double d)
{
	char *data;

	t_float *f = (t_float *)malloc(sizeof(t_float));
	if (!f)
		return (NULL);
	data = (char *)(void *)&d;
	f->type = 'l';
	f->sign = ((data[9] & 0x80) >> 7) ? -1 : 1;
	f->exponent = *((short *)(data + 8)) & 0x7fff;
	f->exponent -= 16383;
	f->significand = *(long *)data;
	return (f);
}

void	display(t_float *f)
{
	printf("type %c sign %d exponent %d significand %lu\n", f->type, f->sign, f->exponent, f->significand);
}

void	test(double n)
{
	t_float *f;
	f = parse_double((double) n);
	display(f);
	f = parse_longdouble((long double) n);
	display(f);
}

int main()
{
	test(3.14159265359);
	test((double) 1/3);
}
