/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exact_float_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:37:30 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/16 20:33:56 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exact_float.h"

t_big_integer	*new_integer(unsigned int *value, int size_in_ints)
{
	t_big_integer *n;

	n = (t_big_integer *)malloc(sizeof(t_big_integer));
	if (!n)
		return (NULL);
	n->value = malloc(size_in_ints * sizeof(int));
	if (!(n->value))
	{
		free(n);
		return (NULL);
	}
	n->size = size_in_ints;
	for(int i = 0; i < size_in_ints; i++)
		n->value[i] = value[size_in_ints - 1 - i];
	return (n);
}

static int		is_zero(t_big_integer *n)
{
	int i;

	i = 0;
	while (i < n->size)
	{
		if (n->value[i])
			return (0);
		i++;
	}
	return (1);
}

static unsigned int	divide(t_big_integer *n, unsigned int divisor)
{
	int i;
	unsigned int dividend;
	unsigned int quotient;
	unsigned long remainder;

	remainder = 0;
	i = n->size - 1;
	while (i >= 0)
	{
		dividend = n->value[i];
		quotient = ((unsigned long) dividend + (remainder << 32)) / divisor;
		remainder = n->value[i] - quotient * divisor;
		n->value[i] = quotient;
		i--;
	}
	return (remainder);
}

char	*integer_to_string(t_big_integer *n)
{
	char *str;
	int length;
	int i;

	if (!n)
		return (NULL);
	if (is_zero(n))
		return (ft_strdup("0"));
	length = 10 * n->size;
	str = ft_strnew(length);
	if (!str)
		return (NULL);
	i = length;
	while (i > 0 && !is_zero(n))
	{
		i--;
		str[i] = '0' + divide(n, 10);
	}
	ft_memmove(str, str + i, length - i);
	str[length - i] = 0;
	return (str);
}
