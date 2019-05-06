/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:31:28 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/04 18:37:00 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_str(va_list ap, t_settings *settings)
{
	char *str;

	if (settings->size_only)
		return (1);
	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}
