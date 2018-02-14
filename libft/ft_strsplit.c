/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:48:04 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/13 17:15:36 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*get_word(char const *str, int start, int end)
{
	char	*word;
	int		i;

	if (!(word = (char*)malloc(sizeof(char) * (1 + end - start))))
		return (0);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	total_length(char const *str, char c)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*word;
	int		start;
	int		end;
	int		id;

	if (!s || !(tab = (char**)malloc(sizeof(char*) * (total_length(s, c) + 1))))
		return (0);
	end = 0;
	start = 0;
	id = 0;
	while (s[end])
	{
		while (s[end] == c)
			start = ++end;
		while (s[end] != c && s[end] != '\0')
			end++;
		word = get_word(s, start, end);
		if (word[0] != '\0' && ft_isprint(word[0]))
			tab[id++] = word;
		start = end;
	}
	tab[id] = 0;
	return (tab);
}
