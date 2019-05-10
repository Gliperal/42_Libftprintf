/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:21:20 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/10 11:37:59 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGLIST_H
# define ARGLIST_H

# include "libftprintf.h"

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

t_arglist	*build_arglist(t_list *printables, int positional);
void	free_arglist(t_arglist **arglist);

#endif
