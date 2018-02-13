/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:19:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/12 13:34:09 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	quicksort4(t_pile pile1, t_pile pile2, int pivot_1)
{
	int pivot;
	int i;

	pivot = edit_pivot(pile2, 0, 1);
	i = 0;
	if (pile2.size == 2)
	{
		if (pile2.tab[0] < pile2.tab[1])
		{
			ft_putstr("sb\n");
			pile2 = sa(pile2);
		}
		tri_final(&pile1, &pile2);
		return ;
	}
	i = put_in_b_bigger_pivot_v2(&pile1, &pile2, pivot, i);
	pile2.size_nosort = pile2.size;
	quicksort4(pile1, pile2, pivot_1);
}

void	quicksort3(t_pile pile1, t_pile pile2, int len)
{
	int pivot;
	int i;
	int size;

	pivot = edit_pivot(pile1, 0, 1);
	i = put_in_a_bigger_pivot_v2(&pile1, &pile2, pivot, 0);
	size = i - 1;
	while (i > 0)
	{
		ft_putstr("rra\n");
		pile1 = rra(pile1);
		i--;
	}
	pile2.size_nosort = (pile2.size / 2) + 1;
	pile1.size_nosort = size;
	pivot = edit_pivot(pile1, 0, 1);
	i = put_in_a_bigger_pivot_v2(&pile1, &pile2, pivot, 0);
	while (i > 0)
	{
		ft_putstr("rra\n");
		pile1 = rra(pile1);
		i--;
	}
	quicksort4(pile1, pile2, pivot);
}

void	quicksort2(t_pile pile1, t_pile pile2, int pivot_1)
{
	int pivot;
	int i;

	pivot = edit_pivot(pile2, 0, 1);
	i = 0;
	if (pile2.size == 2)
	{
		if (pile2.tab[0] < pile2.tab[1])
		{
			ft_putstr("sb\n");
			pile2 = sa(pile2);
		}
		ft_putstr("pa\n");
		ft_putstr("pa\n");
		pa(&pile2, &pile1);
		pa(&pile2, &pile1);
		ft_putstr("ra\n");
		pile1 = ra(pile1);
		petit_fin(&pile1, &pile2, pivot_1);
		pile1.size_nosort = (pile1.size_nosort / 2);
		quicksort3(pile1, pile2, pile1.size_nosort);
		return ;
	}
	i = put_in_a_bigger_pivot(&pile1, &pile2, pivot, i);
	pile2.size_nosort = pile2.size;
	quicksort2(pile1, pile2, pivot_1);
}

void	quicksort(t_pile pile1, t_pile pile2, int len)
{
	int i;
	int pivot;

	pivot = edit_pivot(pile1, 0, 1);
	i = put_in_b_bigger_pivot(&pile1, &pile2, pivot, 0);
	pile2.size_nosort = pile2.size;
	quicksort2(pile1, pile2, pivot);
}
