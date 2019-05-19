/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_e_exact_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:48:33 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/19 15:08:12 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "exact_float.h"

static void	format_e_exp(int exp, char *str)
{
	int i = 1000;

	if (exp < 0)
	{
		exp = 0 - exp;
		*str = '-';
	}
	else
		*str = '+';
	str++;
	while (i > 10 && exp / i == 0)
		i /= 10;
	while (i)
	{
		*str = '0' + (exp / i) % 10;
		str++;
		i /= 10;
	}
}

static char	*format_e_zero(t_exact_float *n, t_printable *p)
{
	char *str;
	char *result;

	result = ft_strnew(p->precision + 7);
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '.';
	ft_memset(result + 2, '0', p->precision);
	ft_memcpy(result + p->precision + 2, "e+00", 4);
	str = pad_number(p, num_prefix(p->flags, n->sign == -1), result);
	free(result);
	return (str);
}

char	*format_e(t_exact_float *n, t_printable *p)
{
	char *result;
	char *str;
	char *tmp;
	int exp;

	if (p->precision == -1)
		p->precision = 6;
	if (is_zero(n))
		return (format_e_zero(n, p));
	if (!(n->integer_str))
		n->integer_str = integer_to_string(&(n->integer));
	if (!(n->integer_str))
		return (NULL);
	if (!(n->fraction_str))
	{
		if (ft_strequ(n->integer_str, "0"))
			n->fraction_str = fraction_to_string2(&(n->fraction), p->precision + 1);
		else
			n->fraction_str = fraction_to_string(&(n->fraction), p->precision);
	}
	if (!(n->fraction_str))
		return (NULL);
	str = ft_strsum(n->integer_str, n->fraction_str);
	if (!str)
		return (NULL);
	exp = ft_strlen(n->integer_str) - 1;
	/* for round up */
	tmp = fraction_to_string(&(n->fraction), 1);
	if (*tmp >= '4')
		str[ft_strlen(str) - 1]++;
	free(tmp);
	exp += round_up_check(&str);
	tmp = str;
	while (*tmp == '0')
	{
		tmp++;
		exp--;
	}
	result = ft_strnew(p->precision + 10);
	result[0] = *tmp;
	if (p->precision || (p->flags & ALTFORM))
	{
		result[1] = '.';
		ft_strncpy(result + 2, tmp + 1, p->precision);
		result[p->precision + 2] = 'e';
		format_e_exp(exp, result + p->precision + 3);
	}
	else
	{
		result[p->precision + 1] = 'e';
		format_e_exp(exp, result + p->precision + 2);
	}
	free(str);
	str = pad_number(p, num_prefix(p->flags, n->sign == -1), result);
	free(result);
	return (str);
}
