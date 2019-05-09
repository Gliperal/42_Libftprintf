/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:48:06 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/09 12:22:14 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
// TODO Remove
#include <stdio.h>

t_list *new_printable()
{
	t_list *l;
	t_printable *p;

	p = (t_printable *)malloc(sizeof(t_printable));
	if (p == NULL)
		return (NULL);
	l = ft_lstnew(0, sizeof(t_printable *));
	if (l == NULL)
		return (NULL);
	p->flags = 0;
	p->field_width_arg = -1;
	p->field_width = 0;
	p->precision_arg = -1;
	p->precision = 0;
	p->type = 0;
	p->data_arg = -1;
	p->data = 0;
	l->content = p;
	return (l);
}

// TODO Remove
void put_printable(t_list *printable)
{
	printf("Printable\n");
	t_printable * p = (t_printable *)printable->content;
	if (p == 0)
		printf("\tNULL\n");
	else
	{
		printf("\tflags\t\t%d\n", p->flags);
		printf("\tfield width_arg\t%d\n", p->field_width_arg);
		printf("\tfield_width\t%d\n", p->field_width);
		printf("\tprecision_arg\t%d\n", p->precision_arg);
		printf("\tprecision\t%d\n", p->precision);
		printf("\tmodifier\t%d\n", p->modifier);
		printf("\ttype\t\t%c\n", p->type);
		printf("\tdata_arg\t%d\n", p->data_arg);
		printf("\tdata\t\t%p\n", p->data);
		if ((p->type == 'c') && p->data)
		{
			char *c = p->data;
			printf("\tdata\t\t%c\n", *c);
		}
	}
	printf("/Printable\n");
}
