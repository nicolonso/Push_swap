/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:07:44 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/21 20:02:16 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node *biggest_node;//To store a pointer with the biggest node in stack 'a'
	
	biggest_node = find_max(*a);//Assign the value with the biggest ptr in my stack
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
		// ft_printf("Here's the error\n");
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}
