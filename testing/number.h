/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:36:05 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/14 21:14:14 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_H
# define NUMBER_H

typedef struct	s_number
{
	int			*value;
	int			size;
}				t_number;

t_number	*new_number(unsigned int *value, int size_in_ints);
int	expand_to(t_number *n, int new_size);
int	left_shift(t_number *n, int amount);
void	add(t_number *n, t_number *increase);
t_number	*multiply(t_number *n1, t_number *n2);

#endif
