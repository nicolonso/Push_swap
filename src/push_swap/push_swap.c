/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:13:41 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/07 14:24:40 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

// static void print_node(t_stack_node *node)
// {
// 	t_stack_node *temp;
//     if (!node) return;
//     ft_printf("nbr: %d\n", node->nbr);
//     // ft_printf("index: %d\n", node->index);
// 	// ft_printf("push_cost: %d\n", node->push_cost);
// 	// ft_printf("above_median: %s\n", node->above_median ? "true" : "false");
// 	// ft_printf("cheapest: %s\n", node->cheapest ? "true" : "false");
// 	// ft_printf("target_node: %p\n", (void*)node->target_node);
// 	// ft_printf("next: %p\n", (void*)node->next);
// 	// ft_printf("prev: %p\n", (void*)node->prev);
// 	temp = node;
// 	while(temp)
// 	{
// 		printf("%d", node->nbr);
// 		node = node->next;
// 	}
// }


int main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');
		//I have problems with leaks in my split function
	init_stack_a(&a, av + 1);
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	/* ft_printf("Values sorted in A\n");
	t_stack_node	*tmp = a;
	while(tmp)
	{
		ft_printf("%d\n",tmp->nbr);
		tmp = tmp->next;
	}
	free(tmp); */
	free_stack(&a);
	free(a);
	free(b);
	return (0);
}
