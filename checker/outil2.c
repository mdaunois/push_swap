/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:28:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/12 13:29:01 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check(t_pile pile1, t_pile pile2)
{
	int i;

	i = 0;
	if (pile2.size == 0)
	{
		while (i < pile1.size - 1)
		{
			if (pile1.tab[i] > pile1.tab[i + 1])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int		le_plus_petit(t_pile pile1, int lowest)
{
	int i;
	int plus_petit;

	i = 1;
	plus_petit = pile1.tab[0];
	if (pile1.size == 1)
		return (plus_petit);
	while (i < pile1.size && pile1.tab[i] > lowest)
	{
		if (pile1.tab[i] < plus_petit)
		{
			plus_petit = pile1.tab[i];
		}
		i++;
	}
	return (plus_petit);
}

int		au_debut(t_pile pile, int lowest)
{
	int i;

	i = 0;
	while (i < (pile.size / 2))
	{
		if (pile.tab[i] == lowest)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		stop_loop(t_pile pile, int pivot)
{
	int i;

	i = 0;
	while (i < pile.size)
	{
		if (pile.tab[i] < pivot)
			return (0);
		i++;
	}
	return (1);
}

int		stop_loop2(t_pile pile, int pivot)
{
	int i;

	i = 0;
	if (pile.size <= 2)
		return (1);
	while (i < pile.size)
	{
		if (pile.tab[i] > pivot)
			return (0);
		i++;
	}
	return (1);
}
