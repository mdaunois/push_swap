/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:09:40 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/05 14:05:15 by mdaunois         ###   ########.fr       */
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

int		edit_pivot(t_pile pile)
{
	int pivot;
	int i;

	i = 0;
	while (i < pile.size)
	{
		pivot = (pivot + pile.tab[i]) / 2;
		i++;
	}
	return pivot;
}

int		isFini(t_pile pile, int pivot)
{
	int i;

	i = 0;
	while (i < pile.size)
	{
		if (pile.tab[i] < pivot)
			return (0);
	}
	return (1);
}
void	quickSort(t_pile pile1, t_pile pile2)
{
	int pivot;
	int i;

	pivot = pile1.tab[pile1.size - 1];
/*	ft_putstr("meileur pivot = ");
	ft_putnbr(edit_pivot(pile1));
	ft_putstr("\n");
	ft_putstr("mon pivot = ");
	ft_putnbr(pivot);
	ft_putstr("\n");
	sleep(1);*/
//	ft_putstr("pile A =");
//	affiche_tab(pile1);
//	pivot = edit_pivot(pile1);
	i = 0;
	if (pile1.tab[i] == pivot)
	{
		petite_pile(pile1, pile2);
		return;
	}
/*	ft_putstr("pivot = ");
	ft_putnbr(pivot);
	ft_putstr("\n");
*/	while (pile1.tab[i] != pivot)
	{
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
	/*	ft_putstr("pile A =");
		affiche_tab(pile1);
		ft_putstr("pile B =");
		affiche_tab(pile2);
*///		sleep(1);
	}
//	ft_putstr("------------------------------");
	//	if(gauche < droite)
	//		echanger(tableau, gauche, droite);
	//	else break;
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
//	if (pile1.size < 12)
		petite_pile(pile1, pile2);
//	else
//		quickSort(pile1, pile2);
/*		ft_putstr("pile A =");
		affiche_tab(pile1);
		ft_putstr("pile B =");
		affiche_tab(pile2);
*/		return (0);

}
