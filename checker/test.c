/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:20:07 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/01 17:55:11 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "checker.h"

int *sa(int *tab1, int len)
{
	int temp;
	int i;

	i = 0;
	temp = tab1[0];
	while (i < len - 1)
	{
		tab1[i] = tab1[i + 1];
		i++;
	}
	tab1[--i] = temp;
	return (tab1);
}

int *ra(int *tab1)
{
	int temp;

	temp = tab1[0];
	tab1[0] = tab1[1];
	tab1[1] = temp;
	return (tab1);
}

void affiche_tab(int *tab1, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		ft_putnbr(tab1[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}

int		main(int argc, char *argv[])
{
	int *tab1;
	int *tab2;
	int i;
	int order;
	char *content;
	int len;

	len = argc;
	i = 0;
	content = "toto";
	if (argc == 0)
	{
		return (0);
	}
	tab1 = (int*)malloc(sizeof(tab1) * argc);
	tab2 = (int*)malloc(sizeof(tab1) * argc);
	while (i + 1 < argc)
	{
		tab1[i] = atoi(argv[i + 1]);
		printf("%d\n", tab1[i]);
		i++;
	}
	while (ft_strcmp(content, "stop"))
	{
		order = get_next_line(0, &content);
		if (!ft_strcmp(content, "sa"))
		{
			printf("sa\n");
			tab1 = sa(tab1, len);
		}
		if (!ft_strcmp(content, "sb"))
		{
			printf("sb\n");
		//	tab2 = sa(tab2, len);
		}
		if (!ft_strcmp(content, "ra"))
		{
			printf("ra\n");
			tab1 = ra(tab1);
		}
		if (!ft_strcmp(content, "rb"))
		{
			printf("rb\n");
		//	tab2 = ra(tab2);
		}
		affiche_tab(tab1, len);
	}
	return (0);
}
