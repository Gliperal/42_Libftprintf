/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:41:39 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/05 16:05:30 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define BOOL char
# define TRUE '\1'
# define FALSE '\0'

# define TERN char
# define ZEROPAD 1
# define RIGHTPAD 2
# define SIGNPAD 1
# define SIGNFORCE 2

# define NOPAD -1

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct			s_settings
{
	void				*data;
	BOOL				absolute_args;
	BOOL				first_pass;
	TERN				padding;
	BOOL				alternate;
	TERN				sign;
	BOOL				delimiters;
	int					field_width;
	int					precision;
}						t_settings;

int						ft_printf(const char *format, ...);
int						ft_format_char(va_list ap, t_settings *settings);
int						ft_format_unknown(va_list ap, t_settings *settings);
int						ft_format_percent(va_list ap, t_settings *settings);

typedef int				(*t_format_f)(va_list, t_settings *);

static const char		g_format_chars[] =
{
	'c',
	'C',
	'd',
	'e',
	'E',
	'f',
	'F',
	'g',
	'G',
	'i',
	'o',
	'p',
	's',
	'S',
	'u',
	'x',
	'X',
	'%',
	0
};
static const t_format_f	g_format_funcs[] =
{
	&ft_format_char,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_unknown,
	&ft_format_percent
};

#endif
