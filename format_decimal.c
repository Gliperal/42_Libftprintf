/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:47:29 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/19 12:46:10 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*format_decimal(t_printable *p)
{
	char *str;
	char *tmp;
	long long n;

	if (p->modifier == MOD_HH)
		n = *((char *)p->data);
	else if (p->modifier == MOD_H)
		n = *((short *)p->data);
	else if (p->modifier == MOD_L)
		n = *((long *)p->data);
	else if (p->modifier == MOD_LL)
		n = *((long long *)p->data);
	else
		n = *((int *)p->data);
	str = ft_itoa_base_u(ft_abs(n), "0123456789");
	if (!str)
		return (NULL);
	if (p->precision != -1)
	{
		p->flags &= ~ZEROPAD;
		if (!pad_left(&str, p->precision))
			return (NULL);
	}
	tmp = pad_number(p, num_prefix(p->flags, n < 0), str);
	free(str);
	return (tmp);
}
