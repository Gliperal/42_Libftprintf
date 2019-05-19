/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exact_float_fraction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:42:39 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/18 19:59:56 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exact_float.h"
#include "libft.h"

t_big_fraction		*new_fraction(unsigned int *value, int size_in_ints)
{
	t_big_fraction	*n;
	int				i;

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
	i = 0;
	while (i < size_in_ints)
	{
		n->value[i] = value[i];
		i++;
	}
	return (n);
}

static int			is_zero(t_big_fraction *n)
{
	int	i;

	i = 0;
	if (n->size <= 0)
		return (1);
	while (i < n->size)
	{
		if (n->value[i])
			return (0);
		i++;
	}
	return (1);
}

static unsigned int	multiply(t_big_fraction *n, unsigned int multiplicand)
{
	int				i;
	unsigned int	foo;
	unsigned long	product;
	unsigned int	carry;

	if (is_zero(n))
		return (0);
	i = n->size - 1;
	carry = 0;
	while (i >= 0)
	{
		foo = n->value[i];
		product = ((unsigned long)foo * (unsigned long)multiplicand) + carry;
		carry = (product & 0xffffffff00000000) >> 32;
		n->value[i] = (int)product;
		i--;
	}
	return (carry);
}

char				*fraction_to_string(t_big_fraction *n, int precision)
{
	char	*str;
	int		i;

	if (!n)
		return (NULL);
	str = ft_strnew(precision);
	if (!str)
		return (NULL);
	i = 0;
	while (i < precision)
	{
		str[i] = '0' + multiply(n, 10);
		i++;
	}
	// TODO fix the round up
	if (multiply(n, 10) > 4)
		str[i - 1] = str[i - 1] + 1;
	return (str);
}

/*
** I would give this a more descriptive name if not for norm, but it basically
** ignores leading zeros when counting the precision.
*/

char				*fraction_to_string2(t_big_fraction *n, int precision)
{
	char			*str;
	int				leading_zeros;
	unsigned int	digit;
	int				i;

	if (!n)
		return (NULL);
	leading_zeros = 0;
	digit = multiply(n, 10);
	while (!digit)
	{
		digit = multiply(n, 10);
		leading_zeros++;
	}
	str = ft_strnew(leading_zeros + precision);
	if (!str)
		return (NULL);
	ft_memset(str, '0', leading_zeros + precision);
	str[leading_zeros] = '0' + digit;
	i = 1;
	while (i < precision)
	{
		str[leading_zeros + i] = '0' + multiply(n, 10);
		i++;
	}
	// TODO fix the round up
	if (multiply(n, 10) > 4)
		str[leading_zeros + i - 1] = str[leading_zeros + i - 1] + 1;
	return (str);
}
