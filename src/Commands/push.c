/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:10:25 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/02 22:37:49 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static void push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*push_node;
	
	//printf("IN push: *dest=%p *src=%p\n", (void *)*dest, (void *)*src);
	//printf("Value in :*src=%p\n", (void *)src);
	ft_printf("This is the value that src is rigt now src : %p\n",(void*)*src);
	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	//printf("DEBUG: *dest is %p\n", (void *)*dest);
	if (!*dest)
	{
		printf("Are u enter here mothefucker?????\n");
		*dest = push_node;
		ft_printf("b :%d",(*dest)->nbr);
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
	//fprintf(stdout, "BEFORE push: *a=%p *b=%p\n", (void *)*a, (void *)*b);
	push(*&a, *&b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node	**a, t_stack_node **b, bool	print)
{
	ft_printf("This inside the pb before push, a =%p\n",(void*)*a);
	push (*&b, *&a);
	if (!print)
		ft_printf("pb\n");
}
