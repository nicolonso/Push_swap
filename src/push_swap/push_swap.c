/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:13:41 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/02 22:37:17 by nalfonso         ###   ########.fr       */
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
	free_stack(&a);
	free(a);
	free(b);
	return (0);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	(void)av;
// 	t_stack_node 	*node = malloc(sizeof(t_stack_node));
// 	if (!node)
// 		retur (ft_ft_printf("Error"),1);
// 	node->nbr = 9999999;
// 	node->index = 0;
// 	node->push_cost = 5;
// 	node->above_median = true;
// 	node->cheapest = false;
// 	node->target_node = (void*)33;
// 	node->next = (void*)55;
// 	node->prev = (void*)42;	
// 	ftft_printf("nbr: %d\n", node->nbr);
// 	ftft_printf("index: %d\n", node->index);
// 	ftft_printf("push cost: %d\n", node->push_cost);
// 	ftft_printf("above median: %s\n", node->above_median ? "true" : "false");
// 	ftft_printf("cheapest: %s\n", node->cheapest ? "true" : "false");
// 	ftft_printf("target node: %p\n", (void*)node->target_node);
// 	ftft_printf("next: %p\n", (void*)node->next);
// 	ftft_printf("prev: %p\n", (void*)node->prev);
// 	free(node);
// 	return (0);
// }

//Practice and do manually with a least 3 pointers in my linked list