/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:12:21 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/20 14:49:29 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_ra(t_pile *pile)
{
	ft_putstr("ra\n");
	*pile = ra(*pile);
}

void	do_sa(t_pile *pile)
{
	ft_putstr("sa\n");
	*pile = sa(*pile);
}

void	do_pa(t_pile *pile1, t_pile *pile2)
{
	ft_putstr("pa\n");
	pa(pile2, pile1);
}

void	do_rb(t_pile *pile)
{
	ft_putstr("rb\n");
	*pile = ra(*pile);
}

void	do_sb(t_pile *pile)
{
	ft_putstr("sb\n");
	*pile = sa(*pile);
}
