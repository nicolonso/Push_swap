/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:15:38 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/10 22:20:46 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static void reverse(t_stack_node **stack)
{
	t_stack_node	*last;
	
	if ( !*stack|| !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void rra(t_stack_node **a, bool print)
{
	reverse(*a);
	if (!print)
		ft_printf("rra\n");
}

void rrb(t_stack_node **b, bool print)
{
	reverse(*b);
	if (!print)
		ft_printf("rrb\n");
}

void rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse (*a);
	reverse (*b);
	if (!print)
		ft_printf("rrr\n");
}
