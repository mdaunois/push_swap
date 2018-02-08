/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:09:40 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/08 15:45:05 by mdaunois         ###   ########.fr       */
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

void	print_pile(t_pile pile1, t_pile pile2)
{
	ft_putstr("pile A =");
	affiche_tab(pile1);
	ft_putstr("pile B =");
	affiche_tab(pile2);
	//sleep(1);
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
		print_pile(pile1, pile2);
/*				ft_putstr("pile A =");
				affiche_tab(pile1);
				ft_putstr("pile B =");
				affiche_tab(pile2);
*/						//sleep(1);
	}
}

int le_plus_petit(t_pile pile1, int lowest)
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
void	petit_fin(t_pile *pile1, t_pile *pile2, int pivot)
{
	int lowest;
	int plus_petit;
	int len;
	int i;

	i = 0;
	len = pile1->size / 2;
	lowest = pile1->tab[0];
	ft_putstr("ra\n");
	*pile1 = ra(*pile1);
	while (pile1->tab[0] <= pivot)
	{
		if (pile2->size == 0)
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
		else
		{	
			if (le_plus_petit(*pile2, lowest) < le_plus_petit(*pile1, lowest))
			{
				if (au_debut(*pile2, le_plus_petit(*pile2, lowest)) == 1)
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
				ft_putstr("ra\n");
				*pile1 = ra(*pile1);
			}
			else if(pile1->tab[0] == le_plus_petit(*pile1, lowest))
			{
				ft_putstr("ra\n");
				*pile1 = ra(*pile1);	
			}
			else
			{
				ft_putstr("pb\n");
				pa(pile1, pile2);
			}	
		}
		i++;
//		print_pile(*pile1, *pile2);
/*		ft_putstr("pile A =");
		affiche_tab(pile1);
		ft_putstr("pile B =");
		affiche_tab(pile2);
		usleep(20000);
*/	}
	while (pile2->size != 0)
	{
				while (pile2->tab[0] != le_plus_petit(*pile2, lowest))
				{
					ft_putstr("rb\n");
					*pile2 = ra(*pile2);
				}
				ft_putstr("pa\n");
				pa(pile2, pile1);
				ft_putstr("ra\n");
				*pile1 = ra(*pile1);
		
	}
//		print_pile(*pile1, *pile2);
/*		ft_putstr("pile A =");
		affiche_tab(pile1);
		ft_putstr("pile B =");
		affiche_tab(pile2);
		usleep(20000);
*/}

void tri_final(t_pile *pile1, t_pile *pile2)
{
	int lowest;
	int i;

	i = 0;
	lowest = pile1->tab[i];
	while (i < pile1->size)
	{
		if (pile1->tab[i] < lowest)
			lowest = pile1->tab[i];
		i++;	
	}
	while (pile1->tab[0] != lowest)
	{
		if (pile2->size == 0)
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
		else
		{	
			if (le_plus_petit(*pile2, lowest) < le_plus_petit(*pile1, lowest))
			{
				if (au_debut(*pile2, le_plus_petit(*pile2, lowest)) == 1)
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
				ft_putstr("ra\n");
				*pile1 = ra(*pile1);
			}
			else if(pile1->tab[0] == le_plus_petit(*pile1, lowest))
			{
				ft_putstr("ra\n");
				*pile1 = ra(*pile1);	
			}
			else
			{
				ft_putstr("pb\n");
				pa(pile1, pile2);
			}	
		}
		i++;
//		print_pile(*pile1, *pile2);
/*		ft_putstr("pile A =");
		affiche_tab(*pile1);
		ft_putstr("pile B =");
		affiche_tab(*pile2);
*///		usleep(200000);
	}
	while (pile2->size != 0)
	{
				while (pile2->tab[0] != le_plus_petit(*pile2, lowest))
				{
					ft_putstr("rb\n");
					*pile2 = ra(*pile2);
				}
				ft_putstr("pa\n");
				pa(pile2, pile1);
				ft_putstr("ra\n");
				*pile1 = ra(*pile1);
		
	}
//		print_pile(*pile1, *pile2);
/*		ft_putstr("pile A =");
		affiche_tab(*pile1);
		ft_putstr("pile B =");
		affiche_tab(*pile2);
*///		usleep(20000);
}

int		edit_pivot(t_pile pile, int petit, int grand)
{
	int pivot;
	int i;
	int j;

	j = 0;
	while (grand != petit)
	{
		pivot = pile.tab[j];
		i = 0;
		if (pile.size_nosort % 2 == 0)
			petit = 0;
		else
			petit = 1;
		grand = 0;
		while (i < pile.size_nosort)
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

void	quickSort4(t_pile pile1, t_pile pile2, int pivot_1)
{
	int pivot;
	int i;
	int j = 0;
	int len;

	len = pile1.size;
	pivot = edit_pivot(pile1, 0, 1);
	i = 0;
	if (pile1.size == 2)
	{
		if (pile1.tab[0] < pile1.tab[1])
		{
			ft_putstr("sa\n");
			pile1 = sa(pile1);
		}
		tri_final(&pile2, &pile1);
//		print_pile(pile1, pile2);
/*		ft_putstr("pile A =");
		affiche_tab(pile2);
		ft_putstr("pile B =");
		affiche_tab(pile1);
*/		return;
	}
	while (j < len)
	{
		j++;
		if (pile1.tab[i] > pivot)
		{
			ft_putstr("pb\n");
			pa(&pile1, &pile2);	
		}
		else
		{
		ft_putstr("ra\n");
		pile1 = ra(pile1);
		}
//		print_pile(pile1, pile2);
/*		ft_putstr("pile A =");
		affiche_tab(pile2);
		ft_putstr("pile B =");
		affiche_tab(pile1);
		usleep(10000);
*/	}
	pile1.size_nosort = pile1.size;
	quickSort4(pile1, pile2, pivot_1);
}
void	quickSort3(t_pile pile1, t_pile pile2, int len)
{
	int pivot;
	int i;
	int j = 0;

	pivot = edit_pivot(pile1, 0, 1);
	i = 0;
	if (check_pile(pile1) == 1)
	{

		sleep(5);
		petite_pile(pile1, pile2);
		return;
	}
	while (j < len)
	{
		j++;
		if (pile1.tab[0] < pivot)
		{
			ft_putstr("pb\n");
			pa(&pile1, &pile2);	
		}
		else
		{
			ft_putstr("ra\n");
			pile1 = ra(pile1);
			i++;
		}
//		print_pile(pile1, pile2);
/*		ft_putstr("pile A =");
		affiche_tab(pile1);
		ft_putstr("pile B =");
		affiche_tab(pile2);
		usleep(10000);
*/	}
	while (i > 0)
	{
		ft_putstr("rra\n");
		pile1 = rra(pile1);
//		print_pile(pile1, pile2);
/*		ft_putstr("pile A =");
		affiche_tab(pile1);
		ft_putstr("pile B =");
		affiche_tab(pile2);
*///		usleep(10000);
			i--;	
	}
	pile2.size_nosort = (pile2.size/2) + 1;
	quickSort4(pile2, pile1, pivot);
}
void	quickSort2(t_pile pile1, t_pile pile2, int pivot_1)
{
	int pivot;
	int i;
	int j = 0;
	int len;

	len = pile1.size;
	pivot = edit_pivot(pile1, 0, 1);
	i = 0;
	if (pile1.size == 2)
	{
		if (pile1.tab[0] < pile1.tab[1])
		{
			ft_putstr("sa\n");
			pile1 = sa(pile1);
		}
		ft_putstr("pa\n");
		ft_putstr("pa\n");
		pa(&pile1, &pile2);	
		pa(&pile1, &pile2);	
//		print_pile(pile2, pile1);
/*		ft_putstr("pile A =");
		affiche_tab(pile2);
		ft_putstr("pile B =");
		affiche_tab(pile1);
*/		petit_fin(&pile2, &pile1, pivot_1);
		pile2.size_nosort = (pile2.size / 2) + 1;
		quickSort3(pile2, pile1, pile2.size_nosort);
		return;
	}
	while (j < len)
	{
		j++;
		if (pile1.tab[i] > pivot)
		{
			ft_putstr("pb\n");
			pa(&pile1, &pile2);	
		}
		else
		{
			ft_putstr("ra\n");
			pile1 = ra(pile1);
		}
//		print_pile(pile2, pile1);
/*		ft_putstr("pile A =");
		affiche_tab(pile2);
		ft_putstr("pile B =");
		affiche_tab(pile1);
		usleep(10000);
*/	}
	pile1.size_nosort = pile1.size;
	quickSort2(pile1, pile2, pivot_1);
}

void	quickSort(t_pile pile1, t_pile pile2, int len)
{
	int pivot;
	int i;
	int j = 0;
	pivot = edit_pivot(pile1, 0, 1);
	i = 0;
	if (check_pile(pile1) == 1)
	{

		sleep(5);
		petite_pile(pile1, pile2);
		return;
	}
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
//		print_pile(pile1, pile2);
/*		ft_putstr("pile A =");
		affiche_tab(pile1);
		ft_putstr("pile B =");
		affiche_tab(pile2);
		usleep(10000);
*/	}
	pile2.size_nosort = pile2.size;
	quickSort2(pile2, pile1, pivot);
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
		quickSort(pile1, pile2, pile1.size);
		ft_putstr("pile A =");
		affiche_tab(pile1);
		ft_putstr("pile B =");
		affiche_tab(pile2);
		return (0);

}
