/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:49:19 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/11 12:17:51 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READERS_H
# define READERS_H

void	*read_char(va_list ap);
void	*read_short(va_list ap);
void	*read_int(va_list ap);
void	*read_long(va_list ap);
void	*read_longlong(va_list ap);
void	*read_ptr(va_list ap);

#endif
