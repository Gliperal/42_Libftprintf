/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_exact_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:48:33 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/18 20:37:15 by nwhitlow         ###   ########.fr       */
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

int	is_zero(t_exact_float *n)
{
	int	i;

	if (n->integer.size <= 0 && n->fraction.size <= 0)
		return (1);
	i = 0;
	while (i < n->integer.size)
	{
		if (n->integer.value[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < n->fraction.size)
	{
		if (n->fraction.value[i])
			return (0);
		i++;
	}
	return (1);
}

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

char	*format_e_zero(t_exact_float *n, t_printable *p)
{
	char *result;

	result = ft_strnew(p->precision + 7);
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '.';
	ft_memset(result + 2, '0', p->precision);
	ft_memcpy(result + p->precision + 2, "e+00", 4);
	format_padding(&result, n, p);
	return (result);
}

int	round_up_check(char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*str)[i] && (*str)[i] <= '9')
		i++;
	if ((*str)[i] <= '9')
		return (0);
	while (i >= 0)
	{
		if ((*str)[i] >= '9')
			(*str)[i] = '0';
		else if ((*str)[i] != '.')
		{
			(*str)[i] = (*str)[i] + 1;
			return (0);
		}
		i--;
	}
	tmp = *str;
	*str = ft_strnew(ft_strlen(*str) + 1);
	(*str)[0] = '1';
	ft_strcpy((*str) + 1, tmp);
	free(tmp);
	return (1);
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
	{
		str[ft_strlen(str) - 1]++;
		free(tmp);
	}
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
	format_padding(&result, n, p);
	return (result);
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
	/* for round up */
	if (p->precision == 0)
	{
		tmp = fraction_to_string(&(n->fraction), 1);
		if (*tmp >= '4')
			n->integer_str[ft_strlen(n->integer_str) - 1]++;
		free(tmp);
	}
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
	round_up_check(&tmp);
	format_padding(&tmp, n, p);
	return (tmp);
}

/*
static t_exact_float	*clone(t_exact_float *n)
{
	t_exact_float *n2;

	n2 = malloc(sizeof(t_exact_float));
	if (!n2)
		return (NULL);
	ft_memcpy(n2, n, sizeof(t_exact_float));
	if (n->integer_str)
		n2->integer_str = ft_strdup(n->integer_str);
	if (n->fraction_str)
		n2->fraction_str = ft_strdup(n->fraction_str);
	n2->integer.value = malloc(n->integer.size * sizeof(int));
	n2->fraction.value = malloc(n->fraction.size * sizeof(int));
	if (!n2->integer.value || !n2->fraction.value)
		return (NULL);
	ft_memcpy(n2->integer.value, n->integer.value, n->integer.size * sizeof(int));
	ft_memcpy(n2->fraction.value, n->fraction.value, n->fraction.size * sizeof(int));
	return (n2);
}
*/

char	*format_g(t_exact_float *n, t_printable *p)
{
/*	t_exact_float *n2;

	n2 = clone(n);
	if (!n2)
		return (NULL);
	if (p->precision == -1)
		p->precision = 6;
	if (p->precision == 0)
		p->precision = 1;
	n2->integer_str = integer_to_string(&(n2->integer));
	if (!(n2->integer_str))
		return (NULL);
	if ((int)ft_strlen(n2->integer_str) > p->precision)
		return (format_e(n, p));
	if (!is_zero(n2) && ft_strequ(n2->integer_str, "0"))
		n->fraction_str = fraction_to_string2(&(n2->fraction), p->precision + 1);
	else
		n->fraction_str = fraction_to_string(&(n2->fraction), p->precision + 1);
	if (!(n2->fraction_str))
		return (NULL);
	if (ft_strequ(n2->integer_str, "0") && ft_strnequ(n2->fraction_str, "0000", 4))
	{
		free_exact_float(n2);
		return (format_e(n, p));
	}
	free_exact_float(n2);
	return (format_f(n, p));*/
	return (NULL);
}
