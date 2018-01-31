/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:34:19 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/13 13:54:59 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	while (i < n)
	{
		if (src2[i] != (unsigned char)c)
			dst2[i] = src2[i];
		else
		{
			dst2[i] = src2[i];
			return (&dst[i + 1]);
		}
		i++;
	}
	return (0);
}
