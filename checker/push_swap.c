/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:09:40 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/05 16:18:37 by mdaunois         ###   ########.fr       */
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

void	petite_pile(t_pile pile1, t_pile pile2)
{
	while (check(pile1, pile2) == 0)
	{
		if (pile1.tab[0] > pile1.tab[pile1.size - 1])
		{
			ft_putstr("ra\n");
			pile1 = ra(pile1);
		}
		else if (pile1.size > 1 && pile1.tab[0] > pile1.tab[1])
		{
			ft_putstr("sa\n");
			pile1 = sa(pile1);
		}
		else if (pile2.size > 1 && pile2.tab[0] < pile2.tab[pile2.size - 1])
		{
			ft_putstr("rb\n");
			pile2 = ra(pile2);
		}
		else if (pile2.size > 1 && pile2.tab[0] < pile2.tab[1])
		{
			ft_putstr("sb\n");
			pile2 = sa(pile2);
		}
		else if (check_pile(pile1) == 1 && pile2.tab[0] < pile1.tab[0])
		{
			ft_putstr("pa\n");
			pa(&pile2, &pile1);	
		}
		else if ((pile1.tab[0] < pile1.tab[1]) && (pile2.size == 0 || pile1.tab[0] >pile2.tab[0]))
		{
			ft_putstr("pb\n");
			pa(&pile1, &pile2);
		}
		else if (pile1.tab[0] > pile1.tab[pile1.size - 1])
		{
			ft_putstr("ra\n");
			pile1 = ra(pile1);
		}
		else if (pile1.size > 1)
		{
			ft_putstr("pb\n");
			pa(&pile1, &pile2);
		}
		/*		ft_putstr("pile A =");
				affiche_tab(pile1);
				ft_putstr("pile B =");
				affiche_tab(pile2);
				*/		//sleep(1);
	}
}

int		edit_pivot(t_pile pile, int petit, int grand)
{
	int pivot;
	int i;
	int j;

	j = 0;
	pivot = pile.tab[j];
	while (grand != petit)
	{
		pivot = pile.tab[j];
		i = 0;
		if (pile.size % 2 == 0)
			petit = 0;
		else
			petit = 1;
		grand = 0;
		while (i < pile.size)
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

void	quickSort(t_pile pile1, t_pile pile2)
{
	int pivot;
	int i;
	int j = 0;
	int len;

	len = pile1.size;
	pivot = pile1.tab[pile1.size - 1];
	pivot = edit_pivot(pile1, 0, 1);
	i = 0;
	if (check_pile(pile1) == 1)
	{
		petite_pile(pile1, pile2);
		return;
	}
//	printf("pivot = %d\n", pivot);
	while (j < len)
	{
		j++;
		if (pile1.tab[i] < pivot)
		{
			ft_putstr("pb\n");
			pa(&pile1, &pile2);	
		}
		else
		{
		ft_putstr("ra\n");
		pile1 = ra(pile1);
		}
/*		ft_putstr("pile A =");
		affiche_tab(pile1);
		ft_putstr("pile B =");
		affiche_tab(pile2);
*/	//	sleep(1);
	}
//	ft_putstr("------------------------------\n");
//	quickSort(pile2, pile1);
	quickSort(pile1, pile2);
}


int		main(int argc, char *argv[])
{
	t_pile	pile1;
	t_pile	pile2;
	int i;

	i = 0;
	if (argc == 0)
		return (0);
	if (init_pile(&pile1, &pile2, argc, argv) != 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (pile1.size < 12)
		petite_pile(pile1, pile2);
	else
		quickSort(pile1, pile2);
/*		ft_putstr("pile A =");
		affiche_tab(pile1);
		ft_putstr("pile B =");
		affiche_tab(pile2);
*/		return (0);

}
