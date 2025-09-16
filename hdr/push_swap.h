/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:38:24 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/16 20:24:43 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "../Lib/hdr/libft.h"

//Structed

typedef struct s_stack_node
{
	int						nbr;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

//Main

int				main(int ac, char **av);

//Handle errors

void			free_stack(t_stack_node	**stack);
void			free_errors(t_stack_node	**a);
int				error_duplicate(t_stack_node *a, int n);
int				error_syntax(char	*str);
void			free_split(char	**split);

//Stack initiation

void			init_stack_a(t_stack_node	**a, char	**av);
char			**split(char	*s, char c);

//Nodes intiation

void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);

//Stack utils

int				stack_len(t_stack_node *stack);
bool			sorted_stack(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node	*stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			min_on_top(t_stack_node **a);

//Commands

void			sa(t_stack_node	**a, bool print);
void			sb(t_stack_node	**b, bool print);
void			ss(t_stack_node	**a, t_stack_node **b, bool print);
void			ra(t_stack_node	**a, bool print);
void			rb(t_stack_node	**b, bool print);
void			rr(t_stack_node	**a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

//Algorithm

void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node	**a, t_stack_node	**b);
void			sort_and_free(t_stack_node **a, t_stack_node **b);
#endif
