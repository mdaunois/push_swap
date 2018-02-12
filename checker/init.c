/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:19:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/12 13:25:33 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_str_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
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

int		init_pile(t_pile *pile1, t_pile *pile2, int argc, char *argv[])
{
	int		i;
	int		nb;
	char	*str_nb;

	i = 0;
	pile1->size = argc - 1;
	pile2->size = 0;
	pile1->size_nosort = argc - 1;
	pile2->size_nosort = 0;
	pile1->tab = (int*)malloc(sizeof(int) * argc);
	pile2->tab = (int*)malloc(sizeof(int) * argc);
	while (i < pile1->size)
	{
		nb = ft_atoi(argv[i + 1]);
		str_nb = ft_itoa(nb);
		if ((ft_str_isdigit((argv[i + 1])) == 1) &&
	(argv[i + 1][0] == str_nb[0]) && same_nb(pile1->tab, nb, i) == 1)
		{
			pile1->tab[i] = ft_atoi(str_nb);
		}
		else
			return (0);
		i++;
	}
	return (1);
}
