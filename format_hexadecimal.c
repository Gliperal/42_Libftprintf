/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:01:39 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/10 16:43:50 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	byte_size(ARGSIZE size)
{
	if (size == SIZE_CHAR)
		return (sizeof(char));
	if (size == SIZE_SHORT)
		return (sizeof(short));
	if (size == SIZE_INT)
		return (sizeof(int));
	if (size == SIZE_LONG)
		return (sizeof(long));
	if (size == SIZE_LONGLONG)
		return (sizeof(long long));
	return (0);
}

static char	hex_to_char(unsigned char c, int uppercase)
{
	if (c < 10)
		return (c + '0');
	else
		return (c - 10 + (uppercase ? 'A' : 'a'));
}

char	*value_to_hex(char *ptr, int size, int uppercase)
{
	int				i;
	char			*hex;
	unsigned char	c;

	hex = ft_strnew(size * 2 + 1);
	if (hex == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		c = ptr[i];
		hex[2 * i] = hex_to_char(c % 16, uppercase);
		hex[2 * i + 1] = hex_to_char(c / 16, uppercase);
		i++;
	}
	i = 2 * size - 1;
	while (hex[i] == '0')
		i--;
	hex[i + 1] = 0;
	ft_strrev(hex);
	return (hex);
}

char	*format_hexadecimal(t_printable *p)
{
	char	*mem;
	int		size;
	int		uppercase;

	mem = p->data;
	size = 2 * byte_size(size_of_type(p->type, p->modifier));
	uppercase = (p->type == 'X');
	return (value_to_hex(mem, size, uppercase));
}
