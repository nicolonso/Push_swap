/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:07:07 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/20 21:35:42 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

void	sort_stacks(t_stack_node	**a, t_stack_node	**b)
{
	//Define a function that sort 'a' if had more than 3 arguments
	int	len_a;//To store the lenght of arguments that i have in stack a

	len_a = stack_len(*a);
	if (len_a-- > 3 && !sorted_stack(*a))
		pb(b , a, false);
	if (len_a-- > 3 && !sorted_stack(*a))
		pb(b , a, false);
	while (len_a-- > 3 &&sorted_stack(*a))
	{
		//Inites nodeas a to b 
		//move a to b 
	}
}
