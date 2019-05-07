/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:52:38 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/06 18:26:52 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTABLE_H
# define PRINTABLE_H

typedef struct	s_printable
{
	char		flags;
	int			field_width_arg;
	int			field_width;
	int			precision_arg;
	int			precision;
	char		modifier;
	char		type;
	int			data_arg;
	void		*data;
}				t_printable;

#endif
