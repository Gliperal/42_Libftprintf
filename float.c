/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:55:08 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/17 16:00:04 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "float.h"

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

void	del_float(t_float **f)
{
	free(*f);
	*f = NULL;
}
