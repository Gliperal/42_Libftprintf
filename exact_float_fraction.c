/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exact_float_fraction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:42:39 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/16 20:35:54 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exact_flaot.h"

t_big_fraction	*new_fraction(unsigned int *value, int size_in_ints)
{
	t_big_fraction *n;

	n = (t_big_fraction *)malloc(sizeof(t_big_fraction));
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
		n->value[i] = value[i];
	return (n);
}

static unsigned int	multiply(t_big_fraction *n, unsigned int multiplicand)
{
	int i;
	unsigned int foo;
	unsigned long product;
	unsigned int carry;

	i = n->size - 1;
	carry = 0;
	while (i >= 0)
	{
		foo = n->value[i];
		product = ((unsigned long) foo * (unsigned long) multiplicand) + carry;
		carry = (product & 0xffffffff00000000) >> 32;
		n->value[i] = (int) product;
		i--;
	}
	return (carry);
}

char	*fraction_to_string(t_big_fraction *n, int precision)
{
	char *str;
	int i;

	if (!n)
		return (NULL);
	if (is_zero_f(n))
		return (ft_strdup("0"));
	str = ft_strnew(precision);
	if (!str)
		return (NULL);
	i = 0;
	while (i < precision)
	{
		str[i] = '0' + multiply_f(n, 10);
		i++;
	}
	return (str);
}
