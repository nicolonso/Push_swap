/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:20:20 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/15 18:23:53 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static void swap(t_stack_node	**stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node	**a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node	**b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node		**a, t_stack_node	**b,	bool print)
{
	swap(a);
	swap(b);
	if(!print)
		ft_printf("ss\n");
}
