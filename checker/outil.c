/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:19:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/12 13:27:54 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	affiche_tab(t_pile pile)
{
	int i;

	i = 0;
	while (i < pile.size)
	{
		ft_putnbr(pile.tab[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}

int		edit_pivot(t_pile pile, int petit, int grand)
{
	int pivot;
	int i;
	int j;

	j = 0;
	while (grand != petit)
	{
		pivot = pile.tab[j];
		i = 0;
		if (pile.size_nosort % 2 == 0)
			petit = 0;
		else
			petit = 1;
		grand = 0;
		while (i < pile.size_nosort)
		{
			if (pivot > pile.tab[i])
				petit++;
			if (pivot <= pile.tab[i])
				grand++;
			i++;
		}
		j++;
	}
	return (pivot);
}

int		lowest_in_pile(t_pile pile)
{
	int lowest;
	int i;

	i = 0;
	lowest = pile.tab[i];
	while (i < pile.size)
	{
		if (pile.tab[i] < lowest)
			lowest = pile.tab[i];
		i++;
	}
	return (lowest);
}

int		bigger_in_pile(t_pile pile)
{
	int bigger;
	int i;

	i = 0;
	bigger = pile.tab[i];
	while (i < pile.size)
	{
		if (pile.tab[i] > bigger)
			bigger = pile.tab[i];
		i++;
	}
	return (bigger);
}
