/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:47:29 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/11 14:48:14 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*format_decimal(t_printable *p)
{
	char *str;
	char *ostr;
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
	str = ft_itoa_base(n, "0123456789");
	if (!str)
		return (NULL);
	if (p->flags & ALTFORM)
	{
		ostr = ft_strsum("0", str);
		free(str);
		return (ostr);
	}
	return (str);
}
