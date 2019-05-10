/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:49:05 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/09 18:56:20 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdlib.h>
#include <stdarg.h>

#include "libft.h"
#include "printable.h"
#include "extract_args.h"
#include "arglist.h"
#include "readers.h"
#include "sizers.h"

# define BOOL char
# define ARG 1
# define NOT_ARG 0

# define ALTFORM 0x01
# define ZEROPAD 0x02
# define RIGHTPAD 0x04
# define SIGNSPACE 0x08
# define SIGNFORCE 0x10
# define DELIMITERS 0x20

typedef void	*(*t_reader)(va_list);
typedef ARGSIZE	(*t_sizer)(char modifier);
typedef char	*(*t_formatter)(void *);

#include "dispatchers.h"

typedef struct	s_type_reader
{
	ARGSIZE		size;
	t_reader	reader;
}				t_type_reader;

typedef struct	s_type_formatter
{
	char		type;
	t_sizer		sizer;
	t_formatter	formatter;
}				t_type_formatter;

static const t_type_reader g_type_readers[] =
{
	(t_type_reader) {SIZE_CHAR, &read_char},
	(t_type_reader) {SIZE_SHORT, &read_short},
	(t_type_reader) {SIZE_INT, &read_int},
	(t_type_reader) {SIZE_LONG, &read_long},
	(t_type_reader) {SIZE_LONGLONG, &read_longlong},
	(t_type_reader) {0, 0}
};

static const t_type_formatter g_type_formatters[] =
{
	(t_type_formatter) {'c', &size_char, 0},
//	(t_type_formatter) {'C', 0, 0},
	(t_type_formatter) {'d', &size_int, 0},
	(t_type_formatter) {'e', &size_float, 0},
	(t_type_formatter) {'E', &size_float, 0},
	(t_type_formatter) {'f', &size_float, 0},
	(t_type_formatter) {'F', &size_float, 0},
	(t_type_formatter) {'g', &size_float, 0},
	(t_type_formatter) {'G', &size_float, 0},
	(t_type_formatter) {'i', &size_int, 0},
	(t_type_formatter) {'o', &size_int, 0},
	(t_type_formatter) {'p', &size_int, 0},
	(t_type_formatter) {'s', &size_float, 0},
//	(t_type_formatter) {'S', &size_float, 0},
	(t_type_formatter) {'u', &size_int, 0},
	(t_type_formatter) {'x', &size_int, 0},
	(t_type_formatter) {'X', &size_int, 0},
	(t_type_formatter) {'%', NULL, 0},
	(t_type_formatter) {0, 0, 0}
};

t_list *new_printable();
t_list	*read_format_string(const char *format);
int	read_placeholder(const char **format, t_list *printables);
int		extract_args(t_list *printables, va_list ap);
int		extract_positional_args(t_list *printables, va_list ap);

void put_printable(t_list *printable);

#endif
