/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:05:51 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/10 16:12:47 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*format_pointer(t_printable *p)
{
	p->flags |= ALTFORM;
	p->type = 'x';
	return (format_hexadecimal(p));
}
