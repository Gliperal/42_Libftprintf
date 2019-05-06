/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:32:49 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/04/30 13:49:26 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		max;
	int		len;
	char	*hay;

	max = ft_strlen(haystack) - ft_strlen(needle);
	len = ft_strlen(needle);
	i = 0;
	while (i <= max)
	{
		if (ft_strncmp(haystack + i, needle, len) == 0)
		{
			hay = (char *)(haystack + i);
			return (hay);
		}
		i++;
	}
	return (0);
}
