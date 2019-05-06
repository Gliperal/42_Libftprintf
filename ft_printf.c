/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:28:58 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/06 12:42:18 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*read_format_string(const char *format);

int	ft_printf(const char *format, ...)
{
	t_list *printables;

	printables = read_format_string(format);
	return (0);
}
