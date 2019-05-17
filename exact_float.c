/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exact_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:25:37 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/17 13:50:52 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exact_float.h"
#include "float.h"

typedef unsigned int	t_ui;

static unsigned int		*clone_array(t_ui *arr, int size, int resize, int off)
{
	unsigned int	*newarr;
	int				i;

	if (resize <= 0)
		return (NULL);
	newarr = malloc(resize * sizeof(int));
	if (!newarr)
		return (NULL);
	i = 0;
	while (i < resize)
	{
		if (i >= off && i < size + off)
			newarr[i] = arr[i - off];
		else
			newarr[i] = 0;
		i++;
	}
	return (newarr);
}

static t_exact_float	*tfloat_to_exact_float(t_float *f)
{
	t_exact_float	*ef;
	int				exp;
	int				shift;
	unsigned int	sig[3];
	int				offset;

	exp = f->exponent;
	shift = (exp >= 0) ? exp % 32 : (exp % 32) + 32;
	sig[0] = (unsigned int)(f->significand >> (64 - shift));
	sig[1] = (unsigned int)(f->significand >> (32 - shift));
	sig[2] = (unsigned int)(f->significand << shift);
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
	offset = ef->fraction.size - 3;
	ef->fraction.value = clone_array(sig, 3, ef->fraction.size, offset);
	return (ef);
}

t_exact_float			*double_to_exact_float(double d)
{
	t_float *f;

	f = parse_double(d);
	if (f)
	{
		f->exponent -= 52;
		return (tfloat_to_exact_float(f));
	}
	return (NULL);
}

t_exact_float			*longdouble_to_exact_float(long double d)
{
	t_float *f;

	f = parse_longdouble(d);
	if (f)
	{
		f->exponent -= 63;
		return (tfloat_to_exact_float(f));
	}
	return (NULL);
}
