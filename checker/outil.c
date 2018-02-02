/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:19:06 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/02 14:26:36 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    affiche_tab(t_pile pile)
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