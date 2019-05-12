/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:14:07 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/12 13:47:21 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*format_char(t_printable *p)
{
	char *str;
	char *tmp;

	str = ft_strndup(p->data, 1);
	if (!str)
		return (NULL);
	tmp = pad_printable(p, "", str);
	free(str);
	return (tmp);
}
