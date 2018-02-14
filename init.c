/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:19:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/14 15:55:31 by mdaunois         ###   ########.fr       */
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

int		init_pile(t_pile *pile1, t_pile *pile2, int argc, char *argv[])
{
	int	i;

	i = 0;
	pile1->size = argc - 1;
	pile2->size = 0;
	pile1->size_nosort = argc - 1;
	pile2->size_nosort = 0;
	pile1->tab = (int*)malloc(sizeof(int) * argc);
	pile2->tab = (int*)malloc(sizeof(int) * argc);
	while (i < pile1->size)
	{
		if ((ft_str_isdigit((argv[i + 1])) == 1) &&
	in_integer(argv[i + 1]) == 1 && same_nb(pile1->tab,
	ft_atoi(argv[i + 1]), i) == 1)
			pile1->tab[i] = ft_atoi(argv[i + 1]);
		else
			return (0);
		i++;
	}
	return (1);
}

void	free_tab(t_pile *pile1, t_pile *pile2)
{
	int i;

	i = 0;
	while (i < pile1->size)
	{
		pile1->tab[i] = 0;
		pile2->tab[i] = 0;
		i++;
	}
	free(pile1->tab);
	pile1->tab = NULL;
	free(pile2->tab);
	pile2->tab = NULL;
}
