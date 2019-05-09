/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatchers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:33:11 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/09 12:47:36 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHERS_H
# define DISPATCHERS_H

# include "libftprintf.h"

ARGSIZE		size_of_type(char type, char modifier);
t_reader	reader_for_size(ARGSIZE size);
t_reader	reader_for_type(char type, char modifier);

#endif
