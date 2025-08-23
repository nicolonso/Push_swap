/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:07:07 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/23 19:58:08 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

int calculate_cost(t_stack_node *a, t_stack_node *b)
{
	int 			cost;
	t_stack_node	*current; 
	
	if (!a || !b)
		return ;
	current = a->nbr;
	cost = 0;
	while (vg)
	
	
}

void sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int lenght;
	
	lenght = stack_len(&a); 
	if (lenght-- > 3)
		pb(&b, &a, false);
	if (lenght-- > 3)
		pb(&b, &a, false);
	//This is a good idea to imlement thgis part but i need t do it 2 times and then
	//start to calculate the cost
	
	//Now I need to calculate what is the bigger and the smaller in tha stack b 
	//So i just can do a comparision or i could create a function that always give me this imnformation 
	//What is better? Okay I just do it in this function and then change it 

	t_stack_node stack;
	
	while (*b)
	{
		stack = &b->nbr > next->nbr;
		// | - this its doesnt work 
	}
}