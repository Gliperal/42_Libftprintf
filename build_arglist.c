/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_arglist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:56:44 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/10 12:30:23 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	parse_args_positional(t_arglist *arglist, t_printable *p)
{
	ARGSIZE size;

	if (p->field_width_arg != -1)
		if (!set_arg_type(arglist, p->field_width_arg, SIZE_INT))
			return (0);
	if (p->precision_arg != -1)
		if (!set_arg_type(arglist, p->precision_arg, SIZE_INT))
			return (0);
	if (p->data_arg != -1)
	{
		size = size_of_type(p->type, p->modifier);
		if (!set_arg_type(arglist, p->data_arg, size))
			return (0);
	}
	return (1);
}

static int	parse_args(t_arglist *arglist, t_printable *p)
{
	ARGSIZE size;

	if (p->field_width_arg == 0)
		if (!set_arg_type(arglist, arglist->size + 1, SIZE_INT))
			return (0);
	if (p->precision_arg == 0)
		if (!set_arg_type(arglist, arglist->size + 1, SIZE_INT))
			return (0);
	if (p->data_arg == 0)
	{
		size = size_of_type(p->type, p->modifier);
		if (!set_arg_type(arglist, arglist->size + 1, size))
			return (0);
	}
	return (1);
}

t_arglist	*build_arglist(t_list *printables, int positional)
{
	t_arglist	*arglist;
	t_printable	*p;

	arglist = new_arglist();
	if (arglist == NULL)
		return (NULL);
	while (printables)
	{
		p = (t_printable *)printables->content;
		if (p)
		{
			if (positional)
			{
				if (!parse_args_positional(arglist, p))
					return (NULL);
			}
			else if (!parse_args(arglist, p))
				return (NULL);
		}
		printables = printables->next;
	}
	return (arglist);
}
