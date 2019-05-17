/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:36:05 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/16 19:09:24 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTION_H
# define FRACTION_H

typedef struct	s_fraction
{
	int			*value;
	int			size;
}				t_fraction;

t_fraction	*new_fraction(unsigned int *value, int size_in_ints);
int		is_zero_f(t_fraction *n);
unsigned int	multiply_f(t_fraction *n, unsigned int multiplicand);
char	*to_string_f(t_fraction *n, int precision);

#endif
