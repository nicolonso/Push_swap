/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:27:39 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/15 18:37:20 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static void min_on_top(t_stack_node	**a)
{
	int	min;

	min = find_min(*a)->nbr;
	while((*a)->nbr != min )
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a,false);
	}
}
static void rotate_both(t_stack_node	**a,	t_stack_node	**b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
	{
		rr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

static void reverse_both(t_stack_node	**a,	t_stack_node	**b, t_stack_node *cheapest_node)
{

	while (*b != cheapest_node->target_node && *a != cheapest_node)
	{
		rrr(a, b, false);
	}
	current_index(*a);
	current_index(*b);

}

static void	move_a_to_b(t_stack_node	**a, t_stack_node	**b)
{
	t_stack_node	*cheapest;

	init_nodes_b(*a, *b);
	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		reverse_both(a, b, cheapest);
	//ft_printf("Cheapest value %d\n", cheapest->nbr);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	/* t_stack_node *tmp = *a;
	ft_printf("stack a\n");
	while (tmp)
	{
		ft_printf("%d\n",tmp->nbr);
		tmp = tmp->next;
	}
	t_stack_node *tmp_2 = *a;
	ft_printf("stack b\n");
	while (tmp_2)
	{
		ft_printf("%d\n",tmp_2->nbr);
		tmp_2 = tmp_2->next;
	} */
	pb(a, b, false);
	init_nodes_b(*a, *b);
	current_index(*a);
	current_index(*b);
}

static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	init_nodes_b(*a, *b);
	prep_for_push(a, (*b)->target_node, 'a');
	/* t_stack_node *tmp = *a;
	while (tmp)
	{
		ft_printf("%d\n",tmp->nbr);
		tmp = tmp->next;
	} */ 
	pa(a, b, false);
	init_nodes_b(*a, *b);
}

void			sort_stacks(t_stack_node	**a, t_stack_node	**b)
{
	int		lenght_a;

	lenght_a = stack_len(*a);
	if (lenght_a-- > 3 && !sorted_stack(*a))
		pb(*&a, *&b, false);	
	if (lenght_a-- > 3 && !sorted_stack(*a))
		pb(*&a, *&b, false);
    while (lenght_a-- > 3 && !sorted_stack(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);			
	}
	sort_three(a);
	while (*b)
	{
		//init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
	/* t_stack_node *tmp = *a;
	while (tmp)
	{
		ft_printf("%d\n",tmp->nbr);
		tmp = tmp->next;
	} */
}
