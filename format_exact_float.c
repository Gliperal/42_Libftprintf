/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_exact_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:48:33 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/17 19:25:45 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "exact_float.h"

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

char	*format_e(t_exact_float *n, int precision, char flags)
{
	return ft_strdup("E");
}

char	*format_f(t_exact_float *n, int precision, char flags)
{
	char *str;
	char *tmp;

	if (!(n->integer_str))
		n->integer_str = integer_to_string(&(n->integer));
	if (!(n->integer_str))
		return (NULL);
	if (!(n->fraction_str))
		n->fraction_str = fraction_to_string(&(n->fraction), precision);
	if (!(n->fraction_str))
		return (NULL);
	tmp = ft_strsum(n->integer_str, ".");
	str = ft_strsum(tmp, n->fraction_str);
	free(tmp);
	return (str);
}

char	*format_g(t_exact_float *n, int precision, char flags)
{
	n->integer_str = integer_to_string(&(n->integer));
	if (!(n->integer_str))
		return (NULL);
	if ((int) ft_strlen(n->integer_str) > precision)
		return (format_e(n, precision, flags));
	n->fraction_str = fraction_to_string(&(n->fraction), precision + 1);
	if (!(n->fraction_str))
		return (NULL);
	if (ft_strequ(n->integer_str, "0") && ft_strnequ(n->fraction_str, "0000", 4))
		return (format_e(n, precision, flags));
	return (format_f(n, precision, flags));
}
