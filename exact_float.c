/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exact_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:25:37 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/17 13:31:27 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exact_float.h"
#include "float.h"
// TODO Remove
#include <stdio.h>

static unsigned int		*clone_array(unsigned int *arr, int old_size, int new_size, int off)
{
	unsigned int *newarr;
	int i;

	if (new_size <= 0)
		return (NULL);
	newarr = malloc(new_size * sizeof(int));
	if (!newarr)
		return (NULL);
	i = 0;
	while (i < new_size)
	{
		if (i >= off && i < old_size + off)
			newarr[i] = arr[i - off];
		else
			newarr[i] = 0;
		i++;
	}
	return (newarr);
}

static t_exact_float	*tfloat_to_exact_float(t_float *f)
{
	t_exact_float *ef;
	int exp;
	int shift;
	unsigned int sig[3];

	exp = f->exponent;
	if (f->type == 'd')
		exp -= 52;
	else if (f->type == 'l')
		exp -= 63;
	shift = exp % 32;
	if (shift < 0)
		shift += 32;
	printf("exponent = %d, significand = %.16lx, shift = %d\n", exp, f->significand, shift);
	sig[0] = (unsigned int) (f->significand >> (64 - shift));
	sig[1] = (unsigned int) (f->significand >> (32 - shift));
	sig[2] = (unsigned int) (f->significand << shift);
	printf("new significand: %.8x, %.8x, %.8x\n", sig[0], sig[1], sig[2]);
	exp = (exp - shift) / 32;
	ef = (t_exact_float *)malloc(sizeof(t_exact_float));
	if (!ef)
		return (NULL);
	ef->integer.size = exp + 3;
	ef->fraction.size = 0 - exp;
	if (ef->integer.size < 0)
		ef->integer.size = 0;
	if (ef->fraction.size < 0)
		ef->fraction.size = 0;
	ef->integer.value = clone_array(sig, 3, ef->integer.size, 0);
	ef->fraction.value = clone_array(sig, 3, ef->fraction.size, ef->fraction.size - 3);
	return (ef);
}

t_exact_float	*double_to_exact_float(double d)
{
	t_float *f = parse_double(d);
	if (f)
		return (tfloat_to_exact_float(f));
	return (NULL);
}

t_exact_float	*longdouble_to_exact_float(long double d)
{
	t_float *f = parse_longdouble(d);
	if (f)
		return (tfloat_to_exact_float(f));
	return (NULL);
}
