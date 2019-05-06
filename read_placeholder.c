/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_placeholder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:42:18 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/06 16:33:44 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pop_number(const char **format)
{
	long num;

	num = 0;
	while (**format >= '0' && **format <= '9')
	{
		if (num < 2147483648)
		{
			num *= 10;
			num += **format - '0';
		}
		*format = *format + 1;
	}
	if (num > 2147483648)
		return (0);
	return (num);
}

static int	pop_arg_number(const char **format)
{
	long num;
	const char *str;

	num = 0;
	str = *format;
	while (*str >= '0' && *str <= '9')
	{
		if (num < 2147483648)
		{
			num *= 10;
			num += *str - '0';
		}
		str++;
	}
	if (*str != '$')
		return (0);
	*format = str + 1;
	if (num > 2147483648)
		return (0);
	return (num);
}

# define ALTFORM 0x01
# define ZEROPAD 0x02
# define RIGHTPAD 0x04
# define SIGNSPACE 0x08
# define SIGNFORCE 0x10
# define DELIMITERS 0x20

static int	pop_flags(const char **format)
{
	int flags;

	flags = 0;
	while (1)
	{
		if (**format == '#')
			flags |= ALTFORM;
		else if ((**format == '0') && !(flags & RIGHTPAD))
			flags |= ZEROPAD;
		else if (**format == '-')
			flags = (flags | RIGHTPAD) & !ZEROPAD;
		else if ((**format == ' ') && !(flags & SIGNFORCE))
			flags |= SIGNSPACE;
		else if (**format == '+')
			flags = (flags | SIGNFORCE) & !SIGNSPACE;
		else if (**format == '\'')
			flags |= DELIMITERS;
		else
			return (flags);
		*format = *format + 1;
	}
}

static void	pop_all_the_rest(const char **format, t_printable *p)
{
	if (**format == '*')
	{
		*format = *format + 1;
		p->field_width_arg = pop_arg_number(format);
	}
	else
		p->field_width = pop_number(format);
	if (**format == '.')
	{
		*format = *format + 1;
		if (**format == '*')
		{
			*format = *format + 1;
			p->precision_arg = pop_arg_number(format);
		}
		else
			p->precision = pop_number(format);
	}
	// TODO p->modifier = pop_modifier(format);
	while ((**format == 'h') || (**format == 'l'))
		*format = *format + 1;
}

int		read_placeholder(const char **format, t_list *printables)
{
	t_list *elem;
	t_printable *p;

	elem = new_printable();
	if (elem == NULL)
		return (-1);
	p = (t_printable *)elem->content;
	*format = *format + 1;
	p->data_arg = pop_arg_number(format);
	p->flags = pop_flags(format);
	pop_all_the_rest(format, p);
	p->type = **format;
	*format = *format + 1;
	ft_lstappend(printables, elem);
	return (0);
}
