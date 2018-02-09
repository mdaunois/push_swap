/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:20:07 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/09 11:59:51 by mdaunois         ###   ########.fr       */
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

int		main(int argc, char *argv[])
{
	t_pile	pile1;
	t_pile	pile2;
	int		order;
	char	*content;

	content = "";
	if (argc == 0)
	{
		return (0);
	}
	if (init_pile(&pile1, &pile2, argc, argv) != 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while ((order = get_next_line(0, &content)) > 0)
	{
		if (!ft_strcmp(content, "sa"))
			pile1 = sa(pile1);
		else if (!ft_strcmp(content, "sb"))
			pile2 = sa(pile2);
		else if (!ft_strcmp(content, "ss"))
		{
			pile1 = sa(pile1);
			pile2 = sa(pile2);
		}
		else if (!ft_strcmp(content, "ra"))
			pile1 = ra(pile1);
		else if (!ft_strcmp(content, "rb"))
			pile2 = ra(pile2);
		else if (!ft_strcmp(content, "rr"))
		{
			pile1 = ra(pile1);
			pile2 = ra(pile2);
		}
		else if (!ft_strcmp(content, "rra"))
			pile1 = rra(pile1);
		else if (!ft_strcmp(content, "rrb"))
			pile2 = rra(pile2);
		else if (!ft_strcmp(content, "rrr"))
		{
			pile1 = rra(pile1);
			pile2 = rra(pile2);
		}
		else if (!ft_strcmp(content, "pa"))
			pa(&pile2, &pile1);
		else if (!ft_strcmp(content, "pb"))
			pa(&pile1, &pile2);
		/*	else
			{
			ft_putstr_fd("Error\n", 2);
			return (0);
			}*/
		ft_putstr("pile A = ");
		affiche_tab(pile1);
		ft_putstr("pile B = ");
		affiche_tab(pile2);
	}
	if (check(pile1, pile2) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free(pile1.tab);
	//	while (1);
	return (0);
}
