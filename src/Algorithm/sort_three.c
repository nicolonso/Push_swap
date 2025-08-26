/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:07:44 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/26 22:39:51 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node *biggest_node;//To store a pointer with the biggest node in stack 'a'
	
	biggest_node = find_max(*a);//Assign the value with the biggest ptr in my stack
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
		// ft_printf("Here's the error\n");
	if ((*a)->nbr > (*a)->next->nbr)
	{	
		ft_printf("Here's the error in this?\n");
		sa(a, false);
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	 //Define a function that searches for the cheapest node, that is set by bool
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

void	prep_for_push(t_stack_node	**stack, t_stack_node *top_node, char stack_name)
{
	ft_printf("Here's the error\n");
	while (*stack != top_node)//Check if the required node is not already the first node
	{
		ft_printf("Here's the error\n");
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
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
