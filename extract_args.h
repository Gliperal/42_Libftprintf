/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 08:27:34 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/08 19:36:31 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRACT_ARGS_H
# define EXTRACT_ARGS_H

# define ARGTYPE char
# define TYPE_CHAR 0
# define TYPE_SHORT 1
# define TYPE_INT 2
# define TYPE_LONG 3
# define TYPE_LONGLONG 4
# define TYPE_STR 5

typedef struct	s_argument
{
	ARGTYPE		type;
	void		*data;
}				t_argument;

typedef struct	s_arglist
{
	int			size;
	t_argument	**args;
}				t_arglist;

#endif
