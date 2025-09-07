/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:27:39 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/07 17:53:42 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static void min_on_top(t_stack_node	*a)
{
	while(a->nbr != find_min(a)->nbr )
	{
		if (find_min(a)->above_median)
			ra(&a, false);
		else
			rra(&a,false);
	}
}
static void rotate_both(t_stack_node	*a,	t_stack_node	*b, t_stack_node *cheapest_node)
{
	while (b != cheapest_node->target_node && a != cheapest_node)
	{
		rr(&a, &b, false);
	}
	current_index(a);
	current_index(b);
}

static void reverse_both(t_stack_node	*a,	t_stack_node	*b, t_stack_node *cheapest_node)
{

	while (b != cheapest_node->target_node && a != cheapest_node)
	{
		rrr(&a, &b, false);
	}
	current_index(a);
	current_index(b);

}

static void	move_a_to_b(t_stack_node	**a, t_stack_node	**b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(*a, *b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		reverse_both(*a, *b, cheapest);
	//ft_printf("cheapest value -> %d\n",cheapest->nbr);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	//prep_push_a(*a, cheapest);
	//prep_push_b(*b, cheapest->target_node);
	pb(*&a, *&b, false);
}

static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a,b, false);
}

void			sort_stacks(t_stack_node	**a, t_stack_node	**b)
{
	int		lenght_a;
	//t_stack_node	*tmp;
	//t_stack_node	*tmp_2;
	lenght_a = stack_len(*a);
	if (lenght_a-- > 3 && !sorted_stack(*a))
		pb(*&a, *&b, false);	
	if (lenght_a-- > 3 && !sorted_stack(*a))
		pb(*&a, *&b, false);
    while (lenght_a-- > 3 && !sorted_stack(*a))
	{
		//we are going to work since here that is the issue
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);			
	}
	sort_three(a);
/*  	tmp = *a;
	while(tmp)
	{
		ft_printf("%d\n",tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("Now all the values in B\n");
	tmp_2 = *b;
	while(tmp_2)
	{
		ft_printf("%d\n",tmp_2->nbr);
		tmp_2 = tmp_2->next;
	} */
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	/* t_stack_node	*tmp_3;
	tmp_3 = *a;
	while(tmp_3)
	{
		ft_printf("%d\n",tmp_3->nbr);
		tmp_3 = tmp_3->next;
	} */
	current_index(*a);
	min_on_top(*a);
}
