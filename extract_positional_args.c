/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_positional_args.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:56:44 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/08 20:54:55 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// TODO Remove
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "extract_args.h"

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

// TODO Use a dispatcher for the type to type conversion
static int			set_arg_type2(t_arglist *arglist, int index, char type, char modifier)
{
	if (modifier)
		return (set_arg_type(arglist, index, modifier - 1));
	else if (type == 's')
		return (set_arg_type(arglist, index, SIZE_STR));
	else if (type == 'c')
		return (set_arg_type(arglist, index, SIZE_CHAR));
	else
		return (set_arg_type(arglist, index, SIZE_INT));
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
				if (!set_arg_type2(arglist, p->data_arg, p->type, p->modifier))
					return (NULL);
		}
		printables = printables->next;
	}
	return (arglist);
}

int		extract_positional_args(t_list *printables, va_list ap)
{
	t_arglist *arglist;

	arglist = get_arg_types(printables); // make a list of arg types
	if (arglist == NULL)
		return (-1);
	printf("Arglist(%d)\n", arglist->size);
	for (int i = 0; i < arglist->size; i++)
	{
		t_argument *arg = arglist->args[i];
		if (arg == NULL)
			printf("\t(NULL)\n");
		else
			printf("\ttype %d, data %p\n", arg->type, arg->data);
	}
	printf("/Arglist\n");
//	withdraw_args(); // use those arg types to get them out of the va_list
//	inject_args(); // iterate through the printable list and update with the appropriate args
	return (-1);
}
