/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:07:44 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/15 18:36:13 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node *biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if(!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return(stack);
		stack = stack->next;
	}
	return (NULL);
}

/* static int node_in_stack(t_stack_node	*stack, t_stack_node	*node)
{
	while (stack)
	{
		if (stack == node)
			return (1);
		stack = stack->next;
	}
	return (0);
	
} */ 

void	prep_for_push(t_stack_node	**stack, t_stack_node *top_node, char stack_name)
{
	int len = stack_len(*stack);
	while ((*stack)->nbr != top_node->nbr && len--)
	{
		/* if (!node_in_stack(*stack, top_node))
        {
            ft_printf("ERROR: top_node [%d] not in stack %c anymore\n", 
                      top_node->nbr, stack_name);
            return;
        } */
		
		if (stack_name == 'a')
		{
			if (top_node->above_median)
			{
				ra(stack, false);
				//ft_printf("Value in stack = %d ,top node :%i\n", top_node->nbr, (*stack)->nbr);
			}	
			else
				rra(stack, false);	
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
