/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:41:09 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/13 18:01:46 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (ft_strnew(0));
	i = 0;
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (end >= 0 && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	if ((end - start) < 0)
		return (ft_strnew(0));
	if (!(str = ft_strnew(end - start + 1)))
		return (0);
	while (start <= end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
