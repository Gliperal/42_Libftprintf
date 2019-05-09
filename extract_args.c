/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:56:44 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/09 11:42:28 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
// TODO Remove
#include <stdio.h>

static int	positional_args(t_list *printables)
{
	t_printable	*p;
	int			arg_style;
	int			tmp;

	tmp = -1;
	arg_style = -1;
	while (printables)
	{
		p = (t_printable *)printables->content;
		if (p != 0)
		{
			if (p->field_width_arg > 0 || p->precision_arg > 0
					|| p->data_arg > 0)
				tmp = 1;
			if (p->field_width_arg == 0 || p->precision_arg == 0
					|| p->data_arg == 0)
				tmp = 0;
		}
		if (arg_style == -1)
			arg_style = tmp;
		else if (arg_style != tmp)
			return (-1);
		printables = printables->next;
	}
	return (arg_style);
}

static ARGSIZE	size_of_type(char type, char modifier)
{
	int i;
	t_sizer sizer;

	i = 0;
	while (g_type_formatters[i].type != 0)
	{
		if (g_type_formatters[i].type == type)
		{
			sizer = g_type_formatters[i].sizer;
			if (sizer == NULL)
				return (0);
			return ((*sizer)(modifier));
		}
		i++;
	}
	return (0);
}

static t_reader	reader_for_type(char type, char modifier)
{
	ARGSIZE	size;
	int		i;

	size = size_of_type(type, modifier);
	if (size == 0)
		return (NULL);
	i = 0;
	while (g_type_readers[i].size != 0)
	{
		if (g_type_readers[i].size == size)
			return (g_type_readers[i].reader);
		i++;
	}
	return (NULL);
}

static int	retrieve_arg_data(t_list *printables, va_list ap)
{
	t_printable	*p;
	t_reader	reader;

	while (printables)
	{
		p = (t_printable *)printables->content;
		if (p != 0)
		{
			if (p->field_width_arg == 0)
				p->field_width = va_arg(ap, int);
			if (p->precision_arg == 0)
				p->precision = va_arg(ap, int);
			if (p->data_arg == 0)
			{
				reader = reader_for_type(p->type, p->modifier);
				if (reader == NULL)
					return (-1);
				p->data = (*reader)(ap);
			}
		}
		printables = printables->next;
	}
	return (0);
}

int			extract_args(t_list *printables, va_list ap)
{
	int	pa;

	pa = positional_args(printables);
	if (pa == -1)
		return (-1);
	else if (pa == 1)
		return (extract_positional_args(printables, ap));
	else if (pa == 0)
		return (retrieve_arg_data(printables, ap));
	return (-1);
}
