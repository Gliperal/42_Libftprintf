/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:47:29 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/12 12:01:48 by nwhitlow         ###   ########.fr       */
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
	if (p->flags & ALTFORM)
	{
		tmp = ft_strsum("0", str);
		free(str);
		str = tmp;
	}
	tmp = pad_printable(p, num_prefix(p->flags, n < 0), str);
	free(str);
	return (tmp);
}
