/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:52:30 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/17 15:57:56 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "float.h"

// TODO Is this okay?
#include "limits.h"

double	dmod(double d, unsigned long m)
{
	double mod;

	mod = m;
	while (mod < d / 4)
		mod *= 2;
	while (1)
	{
		if (d < m)
			return (d);
		if (d < mod)
			mod /= 2;
		else
			d -= mod;
	}
}

double	dpow(double d, unsigned int power)
{
	double b[32];
	int i;

	b[0] = d;
	i = 1;
	while (i < 32)
	{
		b[i] = b[i-1] * b[i-1];
		i++;
	}
	i = 31;
	double result = 1;
	while (i >= 0)
	{
		if (power & (1 << i))
			result *= b[i];
		i--;
	}
	return (result);
}

int		digits(double d)
{
	int digits = 1;
	while (d > 10)
	{
		digits++;
		d /= 10;
	}
	return (digits);
}

int		digit_at(double d, int pos)
{
	d /= dpow(10, pos);
	if (d > ULONG_MAX)
		return (int) dmod(d, 10);
	else
		return (unsigned long) d % 10;
}

char	*thing(double d)
{
	int digs = digits(d);
	char *str = (char *)malloc((digs + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[digs] = 0;
	int i = 0;
	while (i < digs)
	{
		str[i] = '0' + digit_at(d, digs - 1 - i);
		i++;
	}
	return (str);
}

void	print_number(t_big_integer *n)
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

void	print_fraction(t_big_fraction *n)
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

void	free_stuff(t_exact_float *f)
{
	free(f->integer.value);
	free(f->fraction.value);
	free(f->integer_str);
	free(f->fraction_str);
	free(f);
}

char	*format_double(t_printable *p)
{
	t_exact_float *f;
	char *str;

	if (p->modifier == MOD_LD)
		f = longdouble_to_exact_float(*(long double *)p->data);
	else
		f = double_to_exact_float(*(double *)p->data);
	if (f == NULL)
		return (NULL);
	if (p->type == 'f' || p->type == 'F')
		str = format_f(f, p->precision, p->flags);
	else
		str = NULL;
	free_stuff(f);
	return (str);
}
