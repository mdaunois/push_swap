/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:16:05 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/07 16:36:40 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	len++;
	while (i < len)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	return (0);
}
