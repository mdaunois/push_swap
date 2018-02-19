/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:20:07 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/19 16:10:07 by mdaunois         ###   ########.fr       */
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

void	end_op(t_pile pile1, t_pile pile2, char *option, int i)
{
	if (check(pile1, pile2) == 1)
	{
		if (ft_strchr(option, 'n'))
		{
			ft_putstr("le nombres d'operation est :");
			ft_putnbr(i);
			ft_putchar('\n');
		}
		if (ft_strchr(option, 'v'))
			print_pile(pile1, pile2, '2');
		ft_putstr("OK\n");
	}
	else
	{
		if (ft_strchr(option, 'v'))
			print_pile(pile1, pile2, '1');
		ft_putstr("KO\n");
	}
}

int		main(int argc, char *argv[])
{
	t_pile	pile1;
	t_pile	pile2;
	int		order;
	int		i;
	char	*content;

	i = 0;
	content = 0;
	if (argc == 1)
		return (0);
	if (init_pile(&pile1, &pile2, argc, argv) != 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while ((order = get_next_line(0, &content)) > 0 && ++i)
	{
		if (do_op(&content, &pile1, &pile2, argv[1]) == 0)
			return (0);
		if (ft_strchr(argv[1], 'c'))
			print_pile(pile1, pile2, '6');
	}
	end_op(pile1, pile2, argv[1], i);
	free_tab(&pile1, &pile2);
	return (0);
}
