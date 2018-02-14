/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:19:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/14 11:48:51 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	put_lowest_at_end(t_pile *pile1, t_pile *pile2, int lowest)
{
	if (le_plus_petit(*pile1, lowest) == pile1->tab[0])
	{
		if (pile2->tab[0] > pile2->tab[1])
		{
			ft_putstr("rr\n");
			*pile1 = ra(*pile1);
			*pile2 = ra(*pile2);
		}
		else
		{
			ft_putstr("ra\n");
			*pile1 = ra(*pile1);
		}
	}
	else
	{
		ft_putstr("pb\n");
		pa(pile1, pile2);
	}
}

void	do_ra_or_rr(t_pile *pile1, t_pile *pile2, int lowest)
{
	if (au_debut(*pile2, le_plus_petit(*pile2, lowest)) == 1
			&& pile2->tab[0] != le_plus_petit(*pile2, lowest))
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

void	if_plus_petit_in_b(t_pile *pile1, t_pile *pile2, int lowest)
{
	if (pile2->tab[1] == le_plus_petit(*pile2, lowest))
	{
		ft_putstr("sb\n");
		*pile2 = sa(*pile2);
	}
	else if (au_debut(*pile2, le_plus_petit(*pile2, lowest)) == 1)
	{
		while (pile2->tab[0] != le_plus_petit(*pile2, lowest))
		{
			ft_putstr("rb\n");
			*pile2 = ra(*pile2);
		}
	}
	else
	{
		while (pile2->tab[0] != le_plus_petit(*pile2, lowest))
		{
			ft_putstr("rrb\n");
			*pile2 = rra(*pile2);
		}
	}
	ft_putstr("pa\n");
	pa(pile2, pile1);
	do_ra_or_rr(pile1, pile2, lowest);
}

void	empty_pile_b(t_pile *pile1, t_pile *pile2, int lowest)
{
	if (pile2->tab[1] == le_plus_petit(*pile2, lowest))
	{
		ft_putstr("sb\n");
		*pile2 = sa(*pile2);
	}
	else if (au_debut(*pile2, le_plus_petit(*pile2, lowest)) == 1)
	{
		while (pile2->tab[0] != le_plus_petit(*pile2, lowest))
		{
			ft_putstr("rb\n");
			*pile2 = ra(*pile2);
		}
	}
	else
	{
		while (pile2->tab[0] != le_plus_petit(*pile2, lowest))
		{
			ft_putstr("rrb\n");
			*pile2 = rra(*pile2);
		}
	}
	ft_putstr("pa\n");
	pa(pile2, pile1);
	do_ra_or_rr(pile1, pile2, lowest);
}

void	sort_pile_a(t_pile *pile1, t_pile *pile2, int lowest)
{
	if (pile2->size == 0)
		put_lowest_at_end(pile1, pile2, lowest);
	else
	{
		if (le_plus_petit(*pile2, lowest) < le_plus_petit(*pile1, lowest))
			if_plus_petit_in_b(pile1, pile2, lowest);
		else if (pile1->tab[0] == le_plus_petit(*pile1, lowest))
			do_ra_or_rr(pile1, pile2, lowest);
		else if (pile1->tab[1] == le_plus_petit(*pile1, lowest))
		{
			ft_putstr("sa\n");
			*pile1 = sa(*pile1);
		}
		else
		{
			ft_putstr("pb\n");
			pa(pile1, pile2);
		}
	}
}
