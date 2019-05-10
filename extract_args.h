/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 08:27:34 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/09 19:10:20 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRACT_ARGS_H
# define EXTRACT_ARGS_H

#include "libftprintf.h"

# define ARGSIZE char
# define SIZE_CHAR 1
# define SIZE_SHORT 2
# define SIZE_INT 3
# define SIZE_LONG 4
# define SIZE_LONGLONG 5
# define SIZE_STR 6

# define MOD_H 1
# define MOD_HH 2
# define MOD_L 3
# define MOD_LL 4

typedef struct	s_argument
{
	ARGSIZE		type;
	void		*data;
}				t_argument;

typedef struct	s_arglist
{
	int			size;
	t_argument	**args;
	int			index;
}				t_arglist;

#endif
