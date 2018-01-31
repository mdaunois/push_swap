/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:20:07 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/25 16:18:09 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "checker.h"

int *sa(int *tab1)
{
    int temp;
    int i;
    
    i = 0;
    temp = tab1[0];
    while (tab1[i + 1])
    {
        tab1[i] = tab1[i + 1];
        i++;
    }
    tab1[i] = temp;
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

void affiche_tab(int *tab1)
{
    int i;
    
    i = 0;
    while (tab1[i])
    {
        printf("%d  ", tab1[i]);
        i++;
    }
}

int		main(int argc, char *argv[])
{
    int *tab1;
    int *tab2;
    int i;
    int order;
    char *content;

    i = 0;
    content = "toto";
    if (argc == 0)
    {
        return (0);
    }
    tab1 = (int*)malloc(sizeof(tab1) * argc);
    while (i + 1< argc)
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
            tab1 = sa(tab1);
        }
        if (!ft_strcmp(content, "ra"))
        {
            tab1 = ra(tab1);
        }
        affiche_tab(tab1);
       // printf("%s\n", content);
    }
    return (0);
}
