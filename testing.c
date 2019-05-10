// TODO Remove this entire file.

#include "libftprintf.h"

void	put_printable(t_list *printable)
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
		if (p->data)
		{
			t_formatter formatter = formatter_for_type(p->type);
			if (formatter != NULL)
			{
				char *str = (*formatter)(p);
				printf("\tformatted data\t%s\n", str);
				free(str);
			}
		}
	}
	printf("/Printable\n");
}

void	put_arglist(t_arglist *arglist)
{
	printf("Arglist\n");
	for (int i = 0; i < arglist->size; i++)
	{
		t_argument *arg = arglist->args[i];
		printf("\ttype %d data %p\n", arg->type, arg->data);
	}
	printf("/Arglist\n");
}
