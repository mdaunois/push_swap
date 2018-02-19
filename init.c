/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:19:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/19 14:35:10 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_str_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		same_nb(int *tab, int nb, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		in_integer(char *argv)
{
	int		nb;
	char	*str_nbr;
	int		i;

	i = 0;
	nb = ft_atoi(argv);
	str_nbr = ft_itoa(nb);
	while ((argv[i] == '0' || argv[i] == '+') && argv[i + 1])
	{
		i++;
	}
	if (argv[i] == str_nbr[0])
	{
		ft_strdel(&str_nbr);
		return (1);
	}
	ft_strdel(&str_nbr);
	return (0);
}

char	char_in_str(char *str, char *find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (find[j])
		{
			if (str[i] == find[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		init_pile(t_pile *pile1, t_pile *pile2, int argc, char *argv[])
{
	int	i;
	int j;

	i = 0;
	j = 1;
	if ((argv[1][0] == '-') && char_in_str(argv[1], "cvon"))
		j = 2;
	pile1->size = argc - j;
	pile2->size = 0;
	pile1->size_nosort = argc - j;
	pile2->size_nosort = 0;
	pile1->tab = (int*)malloc(sizeof(int) * argc - j);
	pile2->tab = (int*)malloc(sizeof(int) * argc - j);
	while (i < pile1->size)
	{
		if ((ft_str_isdigit((argv[i + j])) == 1) &&
	in_integer(argv[i + j]) == 1 && same_nb(pile1->tab,
	ft_atoi(argv[i + j]), i) == 1)
			pile1->tab[i] = ft_atoi(argv[i + j]);
		else
			return (0);
		i++;
	}
	return (1);
}
