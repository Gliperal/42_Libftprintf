/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:59:53 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/04 18:52:57 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_char(va_list ap, t_settings *settings)
{
	int c;

	if (settings->first_pass)
	{
		c = va_arg(ap, int);
		settings->data = &c;
		return (1);
	}
	else
	{
		write(1, settings->data, 1);
		return (1);
	}
}
