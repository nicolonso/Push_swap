/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:54:36 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/02 20:14:49 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

void current_index(t_stack_node *stack)
{
	int i;
	int median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)//Find `a` node's target in stack `b`
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	ft_printf("Is my set target the problem ???\n");
	if (!b)//This means that for some reason this is null
		return ;
	while (a) //As long as we have nodes in stack `a`
	{
		ft_printf("IIs enter here ???\n");
		best_match_index = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = b; //Assign to `current_b` the current `b` node
		//target_node = NULL;
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			ft_printf("???\n");
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->nbr; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match_index == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			a->target_node = find_max(b); //If so, find the biggest `nbr` and set this as the target node
		else
			a->target_node = target_node; //If no "closer smaller number" is found, and the best match has changed
		a = a->next; //Move to the next `a` node to find it's target `b` node
	}
	return ;
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	len_a; //To store the length of stack `a`
	int	len_b; //To store the length of stack `b`

	len_a = stack_len(a);
	len_b = stack_len(b);
	ft_printf("IS this a little issue ? who knows?? of course me no\n");
	while (a) //Loop through each node until the end of the stack is reached
	{
		ft_printf("just to be sure\n");
		a->push_cost = a->index; //Assign the current `a` node's push cost, its' index value
		if (!(a->above_median)) //Check if the above_median data is false, meaning it is below median
			a->push_cost = len_a - (a->index); //If so, update `a` node's push cost to the stack's length - index
		if (a->target_node->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			a->push_cost += a->target_node->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->push_cost += len_b - (a->target_node->index); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(t_stack_node *stack) //Define a function that sets a node's `cheapest` attribute as `true` or `false`
{
	long			cheapest_value; //To store the value of the cheapest node so far
	t_stack_node	*cheapest_node; //To store a pointer to the cheapest node so far

	ft_printf("or is here ???\n");
	if (!stack) //Check for an empty stack
		return ;
	cheapest_value = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	while (stack) //Loop through every node until the end of the stack is reached, and we find the cheapest node
	{
		if (stack->push_cost < cheapest_value) //Check if the current node's push cost is cheaper than the cheapest value so far
		{
			cheapest_value = stack->push_cost; //If so, update the cheapest value to the current node's push cost
			cheapest_node = stack; //Assign the current node as the cheapest node so far
		}
		stack = stack->next; //Move to the next node for comparison
	}
	cheapest_node->cheapest = true; //After iterating through the stack, if no cheaper node is found than the current, then set the cheapest node's `cheapest` attribut to `true` in the data structure
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b) //Define a function that combines all the functions needed to prepare stack `a`, ready for our pushing and sorting. These functions set the data inside the node's structure
{
	current_index(a);
	current_index(b);
	if (!b)
		return;
	ft_printf("Here are we\n");
	set_target_a(a, b);
	ft_printf("Here are we\n");
	cost_analysis_a(a, b);
	set_cheapest(a);
}

