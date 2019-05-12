/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 19:11:55 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/12 13:58:08 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*format_octal(t_printable *p)
{
	char *str;
	char *ostr;
	unsigned long long n;

	if (p->modifier == MOD_HH)
		n = *((unsigned char *)p->data);
	else if (p->modifier == MOD_H)
		n = *((unsigned short *)p->data);
	else if (p->modifier == MOD_L)
		n = *((unsigned long *)p->data);
	else if (p->modifier == MOD_LL)
		n = *((unsigned long long *)p->data);
	else
		n = *((unsigned int *)p->data);
	str = ft_itoa_base_u(n, "01234567");
	if (!str)
		return (NULL);
	if (p->flags & ALTFORM)
	{
		ostr = ft_strsum("0", str);
		free(str);
		str = ostr;
	}
	if (p->precision != -1)
		if (!pad_left(&str, p->precision))
			return (NULL);
	ostr = pad_printable(p, num_prefix(p->flags, 0), str);
	free(str);
	return (ostr);
}
