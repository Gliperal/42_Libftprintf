/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_printable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:55:30 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/12 12:48:22 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pad_left(char **str, size_t width)
{
	size_t	len;
	char	*newstr;

	len = ft_strlen(*str);
	if (len < width)
	{
		newstr = malloc(width * sizeof(char));
		if (!newstr)
			return (0);
		ft_memset(newstr, '0', width);
		ft_strcpy(newstr + width - len, *str);
		free(*str);
		*str = newstr;
	}
	return (1);
}

char	*num_prefix(char flags, int negative)
{
	if (negative)
		return "-";
	else if (flags & SIGNSPACE)
		return " ";
	else if (flags & SIGNFORCE)
		return "+";
	else
		return "";
}

char	*pad_printable(t_printable *p, const char *prefix, const char *str)
{
	int		desired_width;
	char	*result;

	if (!p || !prefix || !str)
		return (NULL);
	desired_width = ft_strlen(prefix) + ft_strlen(str);
	if (p->field_width > desired_width)
	{
		result = ft_strnew(p->field_width + 1);
		if (!result)
			return (NULL);
		if (p->flags & ZEROPAD)
			ft_memset(result, '0', p->field_width);
		else
			ft_memset(result, ' ', p->field_width);
		result[p->field_width] = 0;
		ft_memcpy(result, prefix, ft_strlen(prefix));
		if (p->flags & RIGHTPAD)
			ft_memcpy(result + ft_strlen(prefix), str, ft_strlen(str));
		else
			ft_memcpy(result + p->field_width - ft_strlen(str), str, ft_strlen(str));
		return (result);
	}
	else
		return (ft_strsum(prefix, str));
}
