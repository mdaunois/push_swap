/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:56:38 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/13 16:34:06 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

	if (!s || !f)
		return (NULL);
	if (!(s2 = ft_strnew(ft_strlen(s))))
		return (0);
	i = 0;
	while (s[i])
	{
		s2[i] = f(s[i]);
		i++;
	}
	return (s2);
}
