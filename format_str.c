/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:28:43 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/10 14:31:04 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*format_str(t_printable *p)
{
	if (p->precision == 0)
		return (ft_strdup(p->data));
	else
		return (ft_strndup(p->data, p->precision));
}
