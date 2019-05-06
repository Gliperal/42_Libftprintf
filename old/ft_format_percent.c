/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:02:37 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/05 16:06:28 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_percent(va_list ap, t_settings *settings)
{
	ap = 0;

	if (settings->first_pass)
		return (-1);
	else
	{
		write(1, "%", 1);
		return (1);
	}
}
