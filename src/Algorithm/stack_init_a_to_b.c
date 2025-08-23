/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:54:36 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/23 22:14:38 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

void current_index(t_stack_node *stack)
{
	int i;
	int median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		i = stack->index;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}

void cheapest(t_stack_node *stack)
{
	
}

void cost_analyze(t_stack_node *stack)
{
	int len_
}

void	initialize_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	
	
}