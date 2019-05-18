/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_exact_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:48:33 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/18 12:35:49 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "exact_float.h"

int		format_padding(char **str, t_exact_float *n, t_printable *p)
{
	char *tmp;

	if (p->flags & ZEROPAD)
	{
		tmp = pad_printable(p, num_prefix(p->flags, n->sign == -1), *str);
		free(*str);
		*str = tmp;
		return (tmp != NULL);
	}
	else
	{
		tmp = ft_strsum(num_prefix(p->flags, n->sign == -1), *str);
		if (!tmp)
			return (0);
		free(*str);
		*str = pad_printable(p, "", tmp);
		free(tmp);
		return (1);
	}
}

char	*format_special(t_exact_float *n, char flags)
{
	if (n->type == 'i')
	{
		if (n->sign == 1)
			return (ft_strdup("inf"));
		else
			return (ft_strdup("-inf"));
	}
	else if (n->type == 'n')
		return (ft_strdup("NaN"));
	return (NULL);
}

char	*format_e(t_exact_float *n, t_printable *p)
{
	return ft_strdup("E");
}

char	*format_f(t_exact_float *n, t_printable *p)
{
	char *str;
	char *tmp;

	if (p->precision == -1)
		p->precision = 6;
	if (!(n->integer_str))
		n->integer_str = integer_to_string(&(n->integer));
	if (!(n->integer_str))
		return (NULL);
	if (!(n->fraction_str))
		n->fraction_str = fraction_to_string(&(n->fraction), p->precision);
	if (!(n->fraction_str))
		return (NULL);
	if (p->precision || (p->flags & ALTFORM))
	{
		str = ft_strsum(n->integer_str, ".");
		tmp = ft_strsum(str, n->fraction_str);
	}
	else
	{
		str = NULL;
		tmp = ft_strdup(n->integer_str);
	}
	free(str);
	format_padding(&tmp, n, p);
	return (tmp);
}

char	*format_g(t_exact_float *n, t_printable *p)
{
	if (p->precision == -1)
		p->precision = 6;
	if (p->precision == 0)
		p->precision = 1;
	n->integer_str = integer_to_string(&(n->integer));
	if (!(n->integer_str))
		return (NULL);
	if ((int) ft_strlen(n->integer_str) > p->precision)
		return (format_e(n, p));
	n->fraction_str = fraction_to_string(&(n->fraction), p->precision + 1);
	if (!(n->fraction_str))
		return (NULL);
	if (ft_strequ(n->integer_str, "0") && ft_strnequ(n->fraction_str, "0000", 4))
		return (format_e(n, p));
	return (format_f(n, p));
}
