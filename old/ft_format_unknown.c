/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unknown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 13:15:35 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/04 18:50:10 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_unknown(va_list ap, t_settings *settings)
{
	ap = 0;

	if (settings->first_pass)
		return (-1);
	else
		return (0);
}
