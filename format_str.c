/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:28:43 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/11 15:45:20 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*format_str(t_printable *p)
{
	char *str;

	if (p->type == '\1')
		str = p->data;
	else
		str = *((char **)p->data);
	if (p->precision == -1)
		return (ft_strdup(str));
	else
		return (ft_strndup(str, p->precision));
}
