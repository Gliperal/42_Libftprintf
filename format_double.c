/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:52:30 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/13 15:58:33 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "float.h"

char	*format_double(t_printable *p)
{
	t_float *d;

	if (p->modifier == MOD_LD)
		d = parse_longdouble(*(long double *)p->data);
	else
		d = parse_double(*(double *)p->data);
	if (d == NULL)
		return (NULL);
	printf("[type %c sign %d exp %d significand %lu]", d->type, d->sign, d->exponent, d->significand);
	return (NULL);
}
