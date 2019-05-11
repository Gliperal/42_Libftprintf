/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizers.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:33:05 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/11 12:18:10 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZERS_H
# define SIZERS_H

# include "argsize.h"

ARGSIZE	size_char(char modifier);
ARGSIZE	size_int(char modifier);
ARGSIZE	size_float(char modifier);
ARGSIZE	size_ptr(char modifier);

#endif
