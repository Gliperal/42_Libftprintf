/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 19:11:55 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/10 19:32:26 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*format_octal(t_printable *p)
{
	char *str;
	char *ostr;
	long long n;

	// TODO ALTFORM adds a 0 to the front
	if (p->modifier == MOD_L)
		n = *((long *)p->data);
	else if (p->modifier == MOD_LL)
		n = *((long long *)p->data);
	else
		n = *((int *)p->data);
	str = ft_itoa_base(n, "01234567");
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
