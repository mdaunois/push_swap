/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:12:21 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/14 15:56:45 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_pile	ra(t_pile pile)
{
	int temp;
	int i;

	i = 0;
	temp = pile.tab[0];
	while (i < pile.size)
	{
		pile.tab[i] = pile.tab[i + 1];
		i++;
	}
	pile.tab[--i] = temp;
	return (pile);
}

t_pile	rra(t_pile pile)
{
	int temp;
	int i;

	i = pile.size - 1;
	temp = pile.tab[i];
	while (i > 0)
	{
		pile.tab[i] = pile.tab[i - 1];
		i--;
	}
	pile.tab[0] = temp;
	return (pile);
}

t_pile	sa(t_pile pile)
{
	int temp;

	temp = pile.tab[0];
	pile.tab[0] = pile.tab[1];
	pile.tab[1] = temp;
	return (pile);
}

void	pa(t_pile *pile1, t_pile *pile2)
{
	pile2->size++;
	*pile2 = rra(*pile2);
	pile2->tab[0] = pile1->tab[0];
	*pile1 = ra(*pile1);
	pile1->size--;
}
