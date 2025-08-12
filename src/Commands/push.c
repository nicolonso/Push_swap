/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:10:25 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/12 18:45:33 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static void push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*push_node;
	
	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack_node	**a, t_stack_node **b, bool	print)
{
	push(*&a, *&b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node	**a, t_stack_node **b, bool	print)
{
	push (*&b, *&a);
	if (!print)
		ft_printf("pb\n");
}