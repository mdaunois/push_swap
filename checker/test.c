/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:20:07 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/02 11:51:24 by mdaunois         ###   ########.fr       */
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

void	affiche_tab(t_pile pile)
{
	int i;

	i = 0;
	while (i < pile.size)
	{
		ft_putnbr(pile.tab[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}

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

int		main(int argc, char *argv[])
{
	t_pile pile1;
	t_pile pile2;
	int i;
	int order;
	char *content;

	pile1.size = argc - 1;
	pile2.size = 0;
	i = 0;
	content = "toto";
	if (argc == 0)
	{
		return (0);
	}
	pile1.tab = (int*)malloc(sizeof(int) * argc);
	pile2.tab = (int*)malloc(sizeof(int) * argc);
	while (i < pile1.size)
	{
		pile1.tab[i] = atoi(argv[i + 1]);
		printf("%d ", pile1.tab[i]);
		i++;
	}
	printf("\n");
	while (ft_strcmp(content, "stop"))
	{
		order = get_next_line(0, &content);
		if (!ft_strcmp(content, "sa"))
			pile1 = sa(pile1);
		if (!ft_strcmp(content, "sb"))
			pile2 = sa(pile2);
		if (!ft_strcmp(content, "ss"))
		{
			pile1 = sa(pile1);
			pile2 = sa(pile2);
		}
		if (!ft_strcmp(content, "ra"))
			pile1 = ra(pile1);
		if (!ft_strcmp(content, "rb"))
			pile2 = ra(pile2);
		if (!ft_strcmp(content, "rr"))
		{
			pile1 = ra(pile1);
			pile2 = ra(pile2);
		}
		if (!ft_strcmp(content, "rra"))
			pile1 = rra(pile1);
		if (!ft_strcmp(content, "rrb"))
			pile2 = rra(pile2);
		if (!ft_strcmp(content, "rrr"))
		{
			pile1 = rra(pile1);
			pile2 = rra(pile2);
		}
		if (!ft_strcmp(content, "pa"))
			pa(&pile2, &pile1);
		if (!ft_strcmp(content, "pb"))
			pa(&pile1, &pile2);
		ft_strdel(&content);
/*		ft_putstr("pile A = ");
		affiche_tab(pile1);
		ft_putstr("pile B = ");
		affiche_tab(pile2);
*/	}
	if (check(pile1, pile2) == 1)
		ft_putstr("OK");
	else
		ft_putstr("KO");
	free(pile1.tab);
	while (1);
	return (0);
}
