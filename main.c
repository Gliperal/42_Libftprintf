#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

// TODO Yanked these functions from extract_args.c ... need to find a good place for it
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

static int	withdraw_args(t_arglist *arglist, va_list ap)
{
	int			i;
	t_argument	*arg;
	t_reader	reader;

	i = 0;
	while (i < arglist->size)
	{
		arg = arglist->args[i];
		reader = reader_for_size(arg->type);
		if (reader == NULL)
			return (0);
		arg->data = (*reader)(ap);
		i++;
	}
	return (1);
}

static void	parse_args(t_printable *p, t_arglist *arglist)
{
	t_argument	*arg;

	if (p->field_width_arg == 0)
	{
		arg = arglist->args[arglist->index];
		p->field_width = *((int *)arg->data);
		arglist->index++;
	}
	if (p->precision_arg == 0)
	{
		arg = arglist->args[arglist->index];
		p->precision = *((int *)arg->data);
		arglist->index++;
	}
	if (p->data_arg == 0)
	{
		arg = arglist->args[arglist->index];
		p->data = arg->data;
		arglist->index++;
	}
}

static void	parse_args_positional(t_printable *p, t_arglist *arglist)
{
	t_argument	*arg;

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

static void	inject_args(t_list *printables, t_arglist *arglist, int positional)
{
	t_printable	*p;

	while (printables)
	{
		p = (t_printable *)printables->content;
		if (p)
		{
			if (positional)
				parse_args_positional(p, arglist);
			else
			{
				arglist->index = 0;
				parse_args(p, arglist);
			}
		}
		printables = printables->next;
	}
}






int test(char *str, ...)
{
	t_list *printables = read_format_string(str);

	int pa = positional_args(printables);
	if (pa == -1)
		return (-1);
	t_arglist *arglist = build_arglist(printables, pa);
	if (arglist == NULL)
		return (-1);

	va_list ap;
	va_start(ap, str);
	if (!withdraw_args(arglist, ap))
		return (-1);

	printf("Arglist\n");
	for (int i = 0; i < arglist->size; i++)
	{
		t_argument *arg = arglist->args[i];
		printf("\ttype %d data %p\n", arg->type, arg->data);
	}
	printf("/Arglist\n");

	inject_args(printables, arglist, pa);
	ft_lstiter(printables, &put_printable);
	free_printables(&printables);
	free_arglist(&arglist);

	va_end(ap);

	return (-1);
}

int	main()
{
	t_list *printables;

	test("hello%2$+.*1$cworld%3$+.*1$c\n", 8, 'a', 'b');
//	test("hello%+.*cworld%+.10c\n", 4, 'a', 'b');

	while(1) {}

	return (0);
}
