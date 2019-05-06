/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:10:36 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/05 16:13:45 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_hex(va_list ap, t_settings *settings)
{
	ap = 0;

	if (settings->first_pass)
		return (-1);
	else
		return (0);
}
