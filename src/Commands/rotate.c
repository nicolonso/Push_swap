/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:12:38 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/15 18:23:33 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static void rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;
		
	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate (a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate (b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate (a);
	rotate (b);
	if (!print)
		ft_printf("rr\n");
}
