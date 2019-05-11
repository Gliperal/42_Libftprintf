/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:28:58 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/11 12:44:17 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
// TODO Remove
#include "testing.h"

// TODO put -Werror back in the makefile

// TODO need to find a good place for this function
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

int	write_printable(t_list *printable)
{
	t_printable	*p;
	t_formatter	formatter;
	char		*str;
	int			len;

	p = (t_printable *)printable->content;
	if (p && p->data)
	{
		formatter = formatter_for_type(p->type);
		if (formatter)
		{
			str = (*formatter)(p);
			if (str)
			{
				len = ft_strlen(str);
				write(1, str, len);
				free(str);
				return (len);
			}
		}
	}
	return (0);
}

int	write_printables(t_list *printables)
{
	int chars_written;

	chars_written = 0;
	while(printables)
	{
		chars_written += write_printable(printables);
		printables = printables->next;
	}
	return (chars_written);
}

int	ft_printf(const char *format, ...)
{
	printf("\nft_printf %s\n", format);
	t_list *printables = read_format_string(format);

	int pa = positional_args(printables);
	if (pa == -1)
		return (-1);
	t_arglist *arglist = build_arglist(printables, pa);
	if (arglist == NULL)
		return (-1);

	va_list ap;
	va_start(ap, format);
	if (!withdraw_args(arglist, ap))
	{
		free_printables(&printables);
		free_arglist(&arglist);
		return (-1);
	}

//	put_arglist(arglist);

	inject_args(printables, arglist, pa);
//	ft_lstiter(printables, &put_printable);
	write_printables(printables);

	free_printables(&printables);
	free_arglist(&arglist);

	va_end(ap);

	return (-1);
}
