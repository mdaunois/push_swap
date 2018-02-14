/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:09:40 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/14 16:26:12 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_pile(t_pile pile1, t_pile pile2)
{
	ft_putstr("pile A =");
	affiche_tab(pile1);
	ft_putstr("pile B =");
	affiche_tab(pile2);
}

void	petit_fin(t_pile *pile1, t_pile *pile2, int pivot)
{
	int lowest;
	int i;

	i = 0;
	lowest = lowest_in_pile(*pile1);
	while (pile1->tab[0] <= pivot)
	{
		sort_pile_a(pile1, pile2, lowest);
	}
	while (pile2->size != 0)
	{
		empty_pile_b(pile1, pile2, lowest);
	}
}

void	tri_final(t_pile *pile1, t_pile *pile2)
{
	int lowest;
	int i;

	i = 0;
	lowest = lowest_in_pile(*pile1);
	while (pile1->tab[0] != lowest)
	{
		sort_pile_a(pile1, pile2, lowest);
	}
	while (pile2->size != 0)
	{
		empty_pile_b(pile1, pile2, lowest);
	}
}

int		main(int argc, char *argv[])
{
	t_pile	pile1;
	t_pile	pile2;
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	if (init_pile(&pile1, &pile2, argc, argv) != 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (pile1.size < 12)
		petite_pile(pile1, pile2);
	else
		quicksort(&pile1, &pile2);
	free(pile1.tab);
	pile1.tab = NULL;
	free(pile2.tab);
	pile2.tab = NULL;
	return (0);
}
