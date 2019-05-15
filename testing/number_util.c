/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:37:30 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/14 21:33:19 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "number.h"
// TODO Remove
#include <stdio.h>

void	print_number2(t_number *n)
{
	if (!n || !(n->value))
	{
		printf("(NULL)\n");
		return ;
	}
	for (int i = n->size - 1; i >= 0; i--)
		printf("%.8x", n->value[i]);
	printf("\n");
}

t_number	*new_number(unsigned int *value, int size_in_ints)
{
	t_number *n;

	n = (t_number *)malloc(sizeof(t_number));
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

t_number	*new_zero(int size_in_ints)
{
	t_number *n;

	n = (t_number *)malloc(sizeof(t_number));
	if (!n)
		return (NULL);
	n->value = malloc(size_in_ints * sizeof(int));
	if (!(n->value))
	{
		free(n);
		return (NULL);
	}
	ft_bzero(n->value, size_in_ints * sizeof(int));
	n->size = size_in_ints;
	return (n);
}

int	expand_to(t_number *n, int new_size)
{
	int *tmp;

	if (!n)
		return (0);
	if (new_size <= n->size)
		return (1);
	tmp = n->value;
	n->value = malloc(new_size * sizeof(int));
	if (!(n->value))
	{
		n->value = tmp;
		return (0);
	}
	ft_bzero(n->value, new_size * sizeof(int));
	ft_memcpy(n->value, tmp, n->size * sizeof(int));
	free(tmp);
	n->size = new_size;
	return (1);
}

int	left_shift(t_number *n, int amount)
{
	int new_size;
	int *tmp;

	if (!n || amount < 0)
		return (0);
	if (amount == 0)
		return (1);
	new_size = n->size + amount;
	tmp = n->value;
	n->value = malloc(new_size * sizeof(int));
	if (!(n->value))
	{
		n->value = tmp;
		return (0);
	}
	ft_bzero(n->value, new_size * sizeof(int));
	ft_memcpy(n->value + amount, tmp, n->size * sizeof(int));
	free(tmp);
	n->size = new_size;
	return (1);
}

void	add(t_number *n, t_number *increase)
{
	int i;
	unsigned int foo[2];
	unsigned long sum;
	unsigned int carry;

	if (!n || !increase)
		return ;
	if (increase->size > n->size)
		if (!expand_to(n, increase->size + 1))
			return ;
	i = 0;
	carry = 0;
	while (i < n->size)
	{
		foo[0] = n->value[i];
		foo[1] = (i < increase->size) ? increase->value[i] : 0;
		sum = (unsigned long) foo[0] + (unsigned long) foo[1] + carry;
		carry = (sum & 0xffffffff00000000) >> 32;
		n->value[i] = (int) sum;
		i++;
	}
	if (carry)
		if (expand_to(n, n->size + 1))
			n->value[n->size - 1] = 1;
}

static t_number	*multiply_one(unsigned int multiplicand, t_number *n)
{
	t_number *result;
	int i;
	unsigned int foo;
	unsigned long product;
	unsigned int carry;

	result = new_zero(n->size + 1);
	i = 0;
	carry = 0;
	while (i < n->size)
	{
		foo = n->value[i];
		product = ((unsigned long) foo * (unsigned long) multiplicand) + carry;
		carry = (product & 0xffffffff00000000) >> 32;
		result->value[i] = (int) product;
		i++;
	}
	result->value[i] = carry;
	return (result);
}

t_number	*multiply(t_number *n1, t_number *n2)
{
	t_number *result;
	int i;

	if (!n1 || !n2)
		return (NULL);
	result = new_zero(n1->size + n2->size);
	i = 0;
	while (i < n1->size)
	{
		t_number *subproduct = multiply_one(n1->value[i], n2);
		left_shift(subproduct, i);
		add(result, subproduct);
		i++;
	}
	return (result);
}
