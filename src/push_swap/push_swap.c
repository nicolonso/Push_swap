/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:13:41 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/10 20:02:57 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

int main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))//Check for incorrect argument counts or if the 2nd argument is '0'
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');//Call ''split()'' to extract each substring
	init_stack_a(&a, av + 1);//Initiate stack  'a' , which also handle errors  
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);//search more about the logig in bool 
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);//clean up the stack
	return (0);
}
//make that the Makefile give the file to excute the program without need to execuaete all , is important
//to implement this part