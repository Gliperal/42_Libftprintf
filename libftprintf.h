/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:49:05 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/06 18:59:41 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdlib.h>

#include "libft.h"
#include "printable.h"

# define BOOL char
# define ARG 1
# define NOT_ARG 0

# define ALTFORM 0x01
# define ZEROPAD 0x02
# define RIGHTPAD 0x04
# define SIGNSPACE 0x08
# define SIGNFORCE 0x10
# define DELIMITERS 0x20

t_list *new_printable();
t_list	*read_format_string(const char *format);
int	read_placeholder(const char **format, t_list *printables);

void put_printable(t_list *printable);

#endif
