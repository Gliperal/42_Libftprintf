/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:56:44 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/08 16:27:21 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// TODO Remove
#include <stdio.h>
#include <stdarg.h>
#include "extract_args.h"

static int	access_args(t_list *printables)
{
	t_printable *p;
	int aa;

	aa = -1;
	while (printables)
	{
		p = (t_printable *)printables->content;
		if (p != 0)
		{
			if (p->field_width_arg > 0 || p->precision_arg > 0 || p->data_arg > 0)
			{
				if (aa == 0)
					return (-1);
				else
					aa = 1;
			}
			if (p->field_width_arg == 0 || p->precision_arg == 0 || p->data_arg == 0)
			{
				if (aa == 1)
					return (-1);
				else
					aa = 0;
			}
		}
		printables = printables->next;
	}
	return (aa);
}
/*
static t_arglist	*get_arg_types(t_list *printables)
{
	t_arglist *arglist;
	t_printable *p;

	arglist = (t_arglist *)malloc(sizeof(t_arglist));
	if (arglist == NULL)
		return (NULL);
	while (printables)
	{
		p = (t_printable *)printables->content;
		if (p->field_width_arg != -1)
			set_arg_type(arglist, p->field_width_arg, TYPE_INT);
		if (p->precision_arg != -1)
			set_arg_type(arglist, p->precision_arg, TYPE_INT);
		set_arg_type2(arglist, p->data_arg, p->type, p->modifiers);
		printables = printables->next;
	}
	return (arglist);
}
*/
int		extract_args(t_list *printables, va_list *ap)
{
	int aa;

	aa = access_args(printables);
	if (aa == -1)
		return (-1);
/*	else if (aa == 1)
	{
		get_arg_types(); // make a list of arg types
		withdraw_args(); // use those arg types to get them out of the va_list
		inject_args(); // iterate through the printable list and update with the appropriate args
	}
	else
		retrieve_arg_data(); // get them out of the va_list in order
*/
	return (-1);
}
