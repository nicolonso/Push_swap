/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:54:28 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/26 22:40:43 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static void set_target_b(t_stack_node	*a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	if (!a || !b)
		return ;
	//best_match_index = 0;
	//ft_printf("b->nbr=%d, best_match_index=%ld, target_node=%p\n",b->nbr, best_match_index, (void*)target_node);
	//ft_printf("Here's the error before to enter on this loop?\n");
	//target_node = NULL;
		//ft_printf("b->nbr=%d, best_match_index=%ld, target_node=%p\n",b->nbr, best_match_index, (void*)target_node);
		//ft_printf("B exist?\n");
	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		ft_printf("Here's the error in my loop?\n");
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
		{
			if (a)
				b->target_node = find_min(a);
			else
				b->target_node = NULL;
		}
		else
				b->target_node = target_node;
		b = b->next;
	}
	ft_printf("Here's the error\n");
}

void			init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	ft_printf("Here's the error\n");
	set_target_b(a, b);
	ft_printf("Here's the error before to set target in b?\n");
	current_index(a);
	current_index(b);
}