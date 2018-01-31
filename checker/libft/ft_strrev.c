/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:47:23 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/09 12:35:23 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		idx_from_last;
	int		i;
	char	temp;

	len = 0;
	while (str[len])
		len++;
	idx_from_last = len - 1;
	i = 0;
	while (str[idx_from_last] && idx_from_last > i)
	{
		temp = str[i];
		str[i] = str[idx_from_last];
		str[idx_from_last] = temp;
		idx_from_last--;
		i++;
	}
	return (str);
}
