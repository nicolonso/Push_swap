#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <limits.h> //To define MIN and MAX macros
#include <stdbool.h> //To use bool flags.
#include "../Lib/hdr/libft.h"//My libft

//Structed

typedef struct s_stack_node // A cointainer for data ,enclosed by {} ,'s' for struct
{
    int                            nbr;
    int                            index;
    int                            push_cost;
    bool                           above_median;
    bool                           cheapest;
    struct s_stack_node            *target_node;
    struct s_stack_node            *next;
    struct s_stack_node            *prev;
}   t_stack_node;

//Main
int 			main(int ac, char **av);

//Handle errors

void 			free_stack(t_stack_node	**stack);
void			free_errors(t_stack_node	**a);
int 			error_duplicate(char *str);
int				error_syntax(char *str);

//Stack initiation

void 			init_stack_a(t_stack_node **a, char **av);
char 			**split(char *s, char c);

//Nodes intiation

t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node	**stack, t_stack_node *top_node, char stack_name);

//Stack utils

// int 			stack_len(t_stack_node *stack);
// bool			sorted_stack(t_stack_node *stack);
 t_stack_node 	*find_last(t_stack_node	*stack);
// t_stack_node 	*find_min(t_stack_node *stack);
// t_stack_node *find_max(t_stack_node *stack);


//Commands

// void			sa(t_stack_node **a, bool print);
// void			sb(t_stack_node **b, bool print);
// void			ss(t_stack_node **a, t_stack_node **b, bool print);
// void			ra(t_stack_node **a, bool print);
// void			rb(t_stack_node **b, bool print);
// void			rr(t_stack_node **a, t_stack_node **b, bool print);
// void			rra(t_stack_node **a, bool print);
// void			rrb(t_stack_node **b, bool print);
// void			rrr(t_stack_node **a, t_stack_node **b, bool print);
// void			pa(t_stack_node **a, t_stack_node **b, bool print);
// void			pb(t_stack_node **b, t_stack_node **a, bool print);

//Algorithm

#endif
