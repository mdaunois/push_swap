/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:19:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/19 15:50:24 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		put_in_b_bigger_pivot(t_pile *pile1, t_pile *pile2, int pivot, int i)
{
	int len;
	int j;

	len = pile1->size;
	j = 0;
	while (stop_loop(*pile1, pivot) == 0)
	{
		j++;
		if (pile1->tab[0] < pivot)
		{
			ft_putstr("pb\n");
			pa(pile1, pile2);
		}
		else
		{
			ft_putstr("ra\n");
			*pile1 = ra(*pile1);
			i++;
		}
	}
	return (i);
}

void	put_directly_in_good_pos(t_pile *pile1, t_pile *pile2, int pivot)
{
	ft_putstr("pa\n");
	pa(pile2, pile1);
	if (pile2->tab[0] < pivot)
	{
		ft_putstr("rr\n");
		*pile2 = ra(*pile2);
		*pile1 = ra(*pile1);
	}
	else
	{
		ft_putstr("ra\n");
		*pile1 = ra(*pile1);
	}
}

int		put_in_b_bigger_pivot_v2(t_pile *pile1, t_pile *pile2, int pivot, int i)
{
	int len;
	int j;
	int lowest;

	len = pile2->size;
	j = 0;
	while (stop_loop2(*pile2, pivot) == 0)
	{
		lowest = lowest_in_pile(*pile2);
		j++;
		if (pile2->tab[0] == lowest)
			put_directly_in_good_pos(pile1, pile2, pivot);
		else if (pile2->tab[0] > pivot)
		{
			ft_putstr("pa\n");
			pa(pile2, pile1);
		}
		else
		{
			ft_putstr("rb\n");
			*pile2 = ra(*pile2);
			i++;
		}
	}
	return (i);
}

int		put_in_a_bigger_pivot(t_pile *pile1, t_pile *pile2, int pivot, int i)
{
	int len;
	int j;

	len = pile2->size;
	j = 0;
	while (stop_loop2(*pile2, pivot) == 0)
	{
		j++;
		if (pile2->tab[0] > pivot)
		{
			ft_putstr("pa\n");
			pa(pile2, pile1);
		}
		else
		{
			ft_putstr("rb\n");
			*pile2 = ra(*pile2);
			i++;
		}
	}
	return (i);
}

int		put_in_a_bigger_pivot_v2(t_pile *pile1, t_pile *pile2, int pivot, int i)
{
	int len;
	int j;
	int lowest;

	lowest = lowest_in_pile(*pile1);
	len = pile1->size;
	j = 0;
	while (pile1->tab[0] != lowest)
	{
		j++;
		if (pile1->tab[0] < pivot)
		{
			ft_putstr("pb\n");
			pa(pile1, pile2);
		}
		else
		{
			ft_putstr("ra\n");
			*pile1 = ra(*pile1);
			i++;
		}
	}
	return (i);
}
