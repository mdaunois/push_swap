/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:19:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/19 14:22:24 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	affiche_tab(t_pile pile, int c)
{
	int i;

	i = 0;
	ft_putstr("\033[3");
	ft_putchar(c);
	ft_putchar('m');
	while (i < pile.size)
	{
		ft_putnbr(pile.tab[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\033[37m");
	ft_putstr("\n");
}

void	print_pile(t_pile pile1, t_pile pile2, int c)
{
	ft_putstr("Stack A =");
	affiche_tab(pile1, c);
	ft_putstr("Stack B =");
	affiche_tab(pile2, c - 2);
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
