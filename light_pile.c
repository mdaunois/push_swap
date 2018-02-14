/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:19:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/14 15:56:23 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_pile(t_pile pile)
{
	int i;

	i = 0;
	while (i < pile.size - 1)
	{
		if (pile.tab[i] > pile.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	do_pb(t_pile *pile1, t_pile *pile2)
{
	ft_putstr("pb\n");
	pa(pile1, pile2);
}

void	petite_pile(t_pile pile1, t_pile pile2)
{
	while (check(pile1, pile2) == 0)
	{
		if (pile1.tab[0] > pile1.tab[pile1.size - 1])
			do_ra(&pile1);
		else if (pile1.size > 1 && pile1.tab[0] > pile1.tab[1])
			do_sa(&pile1);
		else if (pile2.size > 1 && pile2.tab[0] < pile2.tab[pile2.size - 1])
			do_rb(&pile2);
		else if (pile2.size > 1 && pile2.tab[0] < pile2.tab[1])
			do_sb(&pile2);
		else if (check_pile(pile1) == 1 && pile2.tab[0] < pile1.tab[0])
			do_pa(&pile1, &pile2);
		else if ((pile1.tab[0] < pile1.tab[1]) && (pile2.size == 0 ||
	pile1.tab[0] > pile2.tab[0]))
			do_pb(&pile1, &pile2);
		else if (pile1.tab[0] > pile1.tab[pile1.size - 1])
			do_ra(&pile1);
		else if (pile1.size > 1)
			do_pb(&pile1, &pile2);
	}
}
