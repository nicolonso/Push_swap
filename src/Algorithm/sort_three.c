/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:07:44 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/07 16:58:02 by nicolas          ###   ########.fr       */
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
		// ft_printf("Here's the error\n");
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

void	prep_for_push(t_stack_node	**stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		//ft_printf("is enter here ?\n");
		if (stack_name == 'a')
		{
			//ft_printf("is enter here ?\n");
			if (top_node->above_median)
			{
				//ft_printf("Value in stack = %d\n",(*stack)->nbr);
				//ft_printf("Value in top_node = %d\n",(top_node)->nbr);
				ra(stack, false);
			}	
			else
				rra(*&stack, false);	
		}
		else if (stack_name == 'b')
		{
			//ft_printf("is enter here ?\n");
			if (top_node->above_median)
				rb(*&stack, false);
			else
				rrb(*&stack, false);
		}
		// I need something to  advance inside the loop
	}
}
/* 
void prep_push_a(t_stack_node	*a, t_stack_node *top_node)
{
	while(a != top_node)
	{
		if (top_node->above_median)
			ra(&a,false);
		else
			rra(&a, false);
	}
}

void prep_push_b(t_stack_node	*b, t_stack_node *top_node)
{
	int len;
	int i;
	
	if (!b|| !top_node)
        return ;
	len = stack_len(b);
	i = top_node->index;
	if (top_node == find_max(b))
        i = (top_node->index + 1) % len;
    if (top_node->above_median)
    {
        while ((b)->index != i)
            rb(&b, false);
    }
    else
    {
        while ((b)->index != i)
            rrb(&b, false);
	}
} */ 
