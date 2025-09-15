/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:13:41 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/15 22:11:05 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		if (!ft_strchr(av[1],' '))
			init_stack_a(&a, av + 1);
		av = ft_split(av[1], ' ');
	}
	init_stack_a(&a, av + 1);
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
/* int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split;
	static int		v = 0;

	a = NULL;
	b = NULL;
	split = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		v = 1;
		split = ft_split(av[1], ' ');
		init_stack_a(&a, split);
	}
	else
		init_stack_a(&a, av + 1);
	if (stack_len(a) == 2)
		sa(&a, true);
	else if (stack_len(a) == 3)
		sort_three(&a);
	else
		sort_stacks(&a, &b);
	//free_helper(a, b, split, v);
	free_stack(&a);
	free_stack(&b);
	if (split)
		free_split(split);
	return (0);
} */
