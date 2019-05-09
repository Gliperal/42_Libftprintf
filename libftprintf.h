/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:49:05 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/08 21:38:38 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdlib.h>
#include <stdarg.h>

#include "libft.h"
#include "printable.h"
#include "extract_args.h"
#include "readers.h"

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
typedef char	*(*t_formatter)(void *);

typedef struct	s_type_reader
{
	ARGSIZE		size;
	t_reader	reader;
}				t_type_reader;

typedef struct	s_type_formatter
{
	char		type;
	ARGSIZE		size;
	t_formatter	formatter;
}				t_type_formatter;

static const t_type_reader g_type_readers[] =
{
	(t_type_reader) {SIZE_CHAR, &read_char},
	(t_type_reader) {SIZE_SHORT, &read_short},
	(t_type_reader) {SIZE_INT, &read_int},
	(t_type_reader) {SIZE_LONG, &read_long},
	(t_type_reader) {SIZE_LONGLONG, &read_longlong},
	(t_type_reader) {SIZE_STR, &read_str},
	(t_type_reader) {0, 0}
};

static const t_type_formatter g_type_formatters[] =
{
	(t_type_formatter) {'c', SIZE_CHAR, 0},
	(t_type_formatter) {'C', SIZE_CHAR, 0},
	(t_type_formatter) {'d', SIZE_INT, 0},
	(t_type_formatter) {'e', SIZE_LONG, 0},
	(t_type_formatter) {'E', SIZE_LONG, 0},
	(t_type_formatter) {'f', SIZE_LONG, 0},
	(t_type_formatter) {'F', SIZE_LONG, 0},
	(t_type_formatter) {'g', SIZE_LONG, 0},
	(t_type_formatter) {'G', SIZE_LONG, 0},
	(t_type_formatter) {'i', SIZE_INT, 0},
	(t_type_formatter) {'o', SIZE_INT, 0},
	/*
	(t_type_formatter) {'p', SIZE_, 0},
	*/
	(t_type_formatter) {'s', SIZE_STR, 0},
	(t_type_formatter) {'S', SIZE_STR, 0},
	(t_type_formatter) {'u', SIZE_INT, 0},
	(t_type_formatter) {'x', SIZE_INT, 0},
	(t_type_formatter) {'X', SIZE_INT, 0},
	(t_type_formatter) {'%', -1, 0},
	(t_type_formatter) {0, 0, 0}
};

t_list *new_printable();
t_list	*read_format_string(const char *format);
int	read_placeholder(const char **format, t_list *printables);
int		extract_args(t_list *printables, va_list ap);
int		extract_positional_args(t_list *printables, va_list ap);

void put_printable(t_list *printable);

#endif
