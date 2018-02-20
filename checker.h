/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:41:15 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/20 15:20:15 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/includes/libft.h"

typedef struct	s_pile
{
	int *tab;
	int size;
	int size_nosort;
}				t_pile;

t_pile			ra(t_pile pile);
t_pile			rra(t_pile pile);
t_pile			sa(t_pile pile);
void			pa(t_pile *pile1, t_pile *pile2);
int				init_pile(t_pile *pile1, t_pile *pile2, int argc, char *argv[]);
void			affiche_tab(t_pile pile, int c);
void			quicksort(t_pile *pile1, t_pile *pile2);
void			quicksort2(t_pile *pile1, t_pile *pile2, int pivot_1);
void			quicksort3(t_pile *pile1, t_pile *pile2);
void			quicksort4(t_pile *pile1, t_pile *pile2, int pivot_1);
int				put_in_a_bigger_pivot_v2
(t_pile *pile1, t_pile *pile2, int pivot, int i);
int				put_in_a_bigger_pivot
(t_pile *pile1, t_pile *pile2, int pivot, int i);
int				put_in_b_bigger_pivot_v2
(t_pile *pile1, t_pile *pile2, int pivot, int i);
int				put_in_b_bigger_pivot
(t_pile *pile1, t_pile *pile2, int pivot, int i);
int				lowest_in_pile(t_pile pile);
int				bigger_in_pile(t_pile pile);
int				au_debut(t_pile pile, int lowest);
int				le_plus_petit(t_pile pile1, int lowest);
void			sort_pile_a(t_pile *pile1, t_pile *pile2, int lowest);
void			empty_pile_b(t_pile *pile1, t_pile *pile2, int lowest);
int				edit_pivot(t_pile pile, int petit, int grand);
int				stop_loop(t_pile pile, int pivot);
int				stop_loop2(t_pile pile, int pivot);
void			petite_pile(t_pile pile1, t_pile pile2);
int				check(t_pile pile1, t_pile pile2);
void			print_pile(t_pile pile1, t_pile pile2, int c);
void			petit_fin(t_pile *pile1, t_pile *pile2, int pivot);
void			tri_final(t_pile *pile1, t_pile *pile2);
void			free_tab(t_pile *pile1, t_pile *pile2);
void			do_ra(t_pile *pile);
void			do_rb(t_pile *pile);
void			do_sa(t_pile *pile);
void			do_sb(t_pile *pile);
void			do_pa(t_pile *pile1, t_pile *pile2);
int				do_op(char **content, t_pile *pile1,
t_pile *pile2, char *option);
int				ft_str_isdigit(char *str);

#endif
