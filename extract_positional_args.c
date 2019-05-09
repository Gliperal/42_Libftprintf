/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_positional_args.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:56:44 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/09 13:04:32 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// TODO Remove
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

// Two potential memory leaks due to not freeing the argument array
static int			set_arg_type(t_arglist *arglist, int index, ARGSIZE type)
{
	t_argument **tmp;
	t_argument *arg;

	if (arglist == NULL || index < 1)
		return (0);
	if (index > arglist->size)
	{
		tmp = arglist->args;
		arglist->args = (t_argument **)malloc(index * sizeof(t_argument *));
		if (arglist->args == NULL)
			return (0);
		ft_memcpy(arglist->args, tmp, arglist->size * sizeof(t_argument *));
		if (tmp)
			free(tmp);
		arglist->size = index;
	}
	if (arglist->args[index - 1] == NULL)
	{
		arglist->args[index - 1] = (t_argument *)malloc(sizeof(t_argument));
		if (arglist->args[index - 1] == NULL)
			return (0);
	}
	arg = arglist->args[index - 1];
	arg->type = type;
	arg->data = NULL;
	return (1);
}

static t_arglist	*new_arglist()
{
	t_arglist *arglist;

	arglist = (t_arglist *)malloc(sizeof(t_arglist));
	if (arglist == NULL)
		return (NULL);
	arglist->args = 0;
	arglist->size = 0;
	return (arglist);
}

static t_arglist	*get_arg_types(t_list *printables)
{
	t_arglist *arglist;
	t_printable *p;

	arglist = new_arglist();
	if (arglist == NULL)
		return (NULL);
	while (printables)
	{
		p = (t_printable *)printables->content;
		if (p)
		{
			if (p->field_width_arg != -1)
				if (!set_arg_type(arglist, p->field_width_arg, SIZE_INT))
					return (NULL);
			if (p->precision_arg != -1)
				if (!set_arg_type(arglist, p->precision_arg, SIZE_INT))
					return (NULL);
			if (p->data_arg != -1)
				if (!set_arg_type(arglist, p->data_arg, size_of_type(p->type, p->modifier)))
					return (NULL);
		}
		printables = printables->next;
	}
	return (arglist);
}

int		withdraw_args(t_arglist *arglist, va_list ap)
{
	int i;

	i = 0;
	while (i < arglist->size)
	{
		t_argument *arg = arglist->args[i];
		t_reader reader = reader_for_size(arg->type);
		if (reader == NULL)
			return (0);
		arg->data = (*reader)(ap);
		i++;
	}
	return (1);
}

void	inject_args(t_list *printables, t_arglist *arglist)
{
	t_printable	*p;
	t_argument	*arg;

	while (printables)
	{
		p = (t_printable *)printables->content;
		if (p)
		{
			if (p->field_width_arg != -1)
			{
				arg = arglist->args[p->field_width_arg - 1];
				p->field_width = *((int *)arg->data);
			}
			if (p->precision_arg != -1)
			{
				arg = arglist->args[p->precision_arg - 1];
				p->precision = *((int *)arg->data);
			}
			if (p->data_arg != -1)
			{
				arg = arglist->args[p->data_arg - 1];
				p->data = arg->data;
			}
		}
		printables = printables->next;
	}
}

int		extract_positional_args(t_list *printables, va_list ap)
{
	t_arglist *arglist;

	arglist = get_arg_types(printables);
	if (arglist == NULL)
		return (-1);
	if (!withdraw_args(arglist, ap))
		return (-1);
	inject_args(printables, arglist);
	return (-1);
}
