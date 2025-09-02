/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:27:39 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/02 22:39:25 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

// static void min_on_top(t_stack_node	*a)
// {
// 	while(a->nbr != find_min(a)->nbr )
// 	{
// 		if (find_min(a)->above_median)
// 			ra(&a, false);
// 		else
// 			rra(&a,false);
// 	}
// }
// static void rotate_both(t_stack_node	*a,	t_stack_node	*b, t_stack_node *cheapest_node)
// {
// 	while (b != cheapest_node->target_node && a != cheapest_node)
// 		rr(&a, &b, false);
// 	current_index(a);
// 	current_index(b);
// }

// static void reverse_both(t_stack_node	*a,	t_stack_node	*b, t_stack_node *cheapest_node)
// {

// 	while (b != cheapest_node->target_node && a != cheapest_node)
// 		rrr(&a, &b, false);
// 	current_index(a);
// 	current_index(b);

// }

// static void	move_a_to_b(t_stack_node	**a, t_stack_node	**b)
// {
// 	t_stack_node	*cheapest;

// 	cheapest = get_cheapest(*a);
// 	if (cheapest->above_median && cheapest->target_node->above_median)
// 		rotate_both(*a, *b, cheapest);
// 	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
// 		reverse_both(*a, *b, cheapest);
// 	prep_for_push(a, cheapest, 'a');
// 	prep_for_push(b, cheapest->target_node, 'b');
// 	pb(b, a, false);
// }

// static void move_b_to_a(t_stack_node **a, t_stack_node **b)
// {
// 	prep_for_push(a, (*b)->target_node, 'a');
// 	pa(a,b, false);
// }

static void print_node(t_stack_node *node)
{
    if (!node) return;
    ft_printf("nbr: %d\n", node->nbr);
    //ft_printf("index: %d\n", node->index);
	//ft_printf("push_cost: %d\n", node->push_cost);
	// ft_printf("above_median: %s\n", node->above_median ? "true" : "false");
	// ft_printf("cheapest: %s\n", node->cheapest ? "true" : "false");
	// ft_printf("target_node: %p\n", (void*)node->target_node);
	// ft_printf("next: %p\n", (void*)node->next);
	// ft_printf("prev: %p\n", (void*)node->prev);
}

void			sort_stacks(t_stack_node	**a, t_stack_node	**b)
{
	// int		lenght_a;
	
	// lenght_a = stack_len(*a);


	ft_printf("My first test a: %p\n",(void*)*a);
	pb(*&b, *&a, false);
	while (*a)
	{
		print_node(*a);
		*a = (*a)->next;
	}
	// print_node(*b);
	// printf("Before pb: *a=%p *b=%p\n", (void *)*a, (void *)*b);
	// if (lenght_a-- > 3 && !sorted_stack(*a))
	// {
	// 	ft_printf("%d\n", (*a)->nbr);
	// 	printf("Values that i give a pb: *a =%p , *a = %d *b =%p\n", (void *)*a, (*a)->nbr, (void *)*b);
	// 	pb(b, a, false);// Destiny || Source
	// }
	// if (lenght_a-- > 3 && !sorted_stack(*a))
	// {
	// 	ft_printf("%d\n", (*a)->nbr);	
	// 	ft_printf("%d\n", (*b)->nbr);
	// 	pb(b, a, false);
	// }
	// print_node(*b);
	
	// while (lenght_a-- > 3 && !sorted_stack(*a))
	// {
	// 	init_nodes_a(*a, *b);
	// 	move_a_to_b(a, b);//This part move the cheapest node in cost and then with the next
	// 	//Create the part that with already all info we are going to move everything		
	// }
	// sort_three(a);//In this part with my already 3 values with sort in order and then we can start push everything in a
	// // In this part we are be focus on push all in a already sorted
	// while (*b)
	// {
	// 	ft_printf("Here's the error when need to sort all in 'a'\n");
	// 	ft_printf("Is this working ? , %p, b : %d\n", *b, (*b)->nbr);
	// 	init_nodes_b(*a, *b);
	// 	move_b_to_a(a, b);//Here move to a already sorted
	// 	//Here allocate my function that would move everything to my nde 'a'  from 'b'
	// }
	// current_index(*a);
	// min_on_top(*a);//Check if my smallest nbr is on top of my stack
}
