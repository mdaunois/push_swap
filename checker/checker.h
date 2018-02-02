#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"

typedef struct	s_pile
{
	int *tab;
	int size;
}				t_pile;

t_pile    ra(t_pile pile);
t_pile    rra(t_pile pile);
t_pile    sa(t_pile pile);
void    pa(t_pile *pile1, t_pile *pile2);
int        init_pile(t_pile *pile1,t_pile *pile2, int argc, char *argv[]);
void    affiche_tab(t_pile pile);
#endif
