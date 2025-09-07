/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:20:20 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/06 19:02:30 by nicolas          ###   ########.fr       */
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
	swap(*&a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node	**b, bool print)
{
	swap(*&b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node		**a, t_stack_node	**b,	bool print)
{
	swap(*&a);
	swap(*&b);//Exist one way that i could do this at the same time and wrote in one line ?
	if(!print)
		ft_printf("ss\n");
}


//Errors that i find while im doing these function 

//expression must have pointer-to-struct-or-union type but it has type "t_stack_node **" (aka "struct s_stack_node **")C/C++(132)