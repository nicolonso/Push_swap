/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:12:38 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/11 19:57:34 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static void rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
		
	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate (*a);
	if (!print)//How can i know to manipulate my bool value to that happen
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate (*b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate (*a);
	rotate (*b);
	if (!print)
		ft_printf("rr\n");
}

//Becouse when i send a vulue and taths is possible how they could work and sen that information
//taht i going to print look for more info. about it 