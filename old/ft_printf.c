/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:41:09 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/05 20:06:59 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// Remote
#include <stdio.h>

// Move this to libft
void	ft_putnchar(char c, int n);

static t_format_f	format_function(char c)
{
	int			i;

	i = 0;
	while (g_format_chars[i] != 0)
	{
		if (g_format_chars[i] == c)
			return (g_format_funcs[i]);
		i++;
	}
	return (&ft_format_unknown);
}

/*
static int			extract_settings(char **format, t_settings *settings)
{
	while (flag)
	{
		if (**format == '0' && !settings->padding)
			settings->padding = ZEROPAD;
		if (**format == '-')
			settings->padding = RIGHTPAD;
		if (**format == '#')
			settings->alternate = TRUE;
		if (**format == ' ' && !settings->sign)
			settings->sign = SIGNPAD;
		if (**format == '+')
			settings->sign = SIGNFORCE;
		if (**format == '\'')
			settings->delimiters = TRUE;
	}
	settings->field_width = *num$();
	if (**format == '.')
	{
		*format = *format + 1;
		settings->precision = *num$();
		  always double-check $s
	}
	hl
	type (set pointer here)
	return 0
}
*/

static int			pad_and_print(va_list ap, char c, t_settings *settings)
{
	int			size;
	t_format_f	format;

	format = format_function(c);
	settings->first_pass = TRUE;
	size = (*format)(ap, settings);
	settings->first_pass = FALSE;
	if (size == NOPAD || size >= settings->field_width)
		return ((*format)(ap, settings));
	else if (settings->padding == RIGHTPAD)
	{
		(*format)(ap, settings);
		ft_putnchar(' ', settings->field_width - size);
		return (settings->field_width);
	}
	else
	{
		if (settings->padding == ZEROPAD)
			ft_putnchar('0', settings->field_width - size);
		else
			ft_putnchar(' ', settings->field_width - size);
		(*format)(ap, settings);
		return (settings->field_width);
	}
}

int					absolute_args(const char *format)
{
	int i;

	i = 0;
	while (1)
	{
		if (format[i] == 0)
			return (0);
		else if (format[i] == '%')
		{
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			if (format[i] == '$')
				return (1);
			else
				return (0);
		}
		i++;
	}
}

static int			printf_loop(const char **format, va_list ap, t_settings *settings)
{
	int		chars_written;
	int		i;
	char	c;

	chars_written = 0;
	while (1)
	{
		if (**format == '%')
		{
			*format = *format + 1;
	//		if (!extract_settings(format, settings))
	//			return (-1);
			c = **format;
			*format = *format + 1;
			chars_written += pad_and_print(ap, c, settings);
		}
		else
		{
			i = 0;
			while ((*format)[i] != 0 && (*format)[i] != '%')
				i++;
			write(1, *format, i);
			chars_written += i;
			*format = *format + i;
			if (**format == 0)
				return (chars_written);
		}
	}
}

int					ft_printf(const char *format, ...)
{
	va_list		ap;
	t_settings	*settings;
	const char	*str;

	settings = (t_settings *)malloc(sizeof(t_settings));
	if (settings == 0)
		return (-1);
	settings->absolute_args = absolute_args(format);
		settings->field_width = 0;
		settings->padding = 0;
	va_start(ap, format);
	str = format;
	return (printf_loop(&format, ap, settings));
}
