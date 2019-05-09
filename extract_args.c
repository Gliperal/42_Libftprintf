/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:56:44 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/08 19:43:19 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	positional_args(t_list *printables)
{
	t_printable *p;
	int arg_style;
	int tmp;

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

static int	retrieve_arg_data()
{
	// Get the non-positional args out of va_list in order
	return (-1);
}

int		extract_args(t_list *printables, va_list *ap)
{
	int pa;

	pa = positional_args(printables);
	if (pa == -1)
		return (-1);
	else if (pa == 1)
		return (extract_positional_args(printables, ap));
	else if (pa == 0)
		return (retrieve_arg_data());
	return (-1);
}
