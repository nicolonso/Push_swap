/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:13:41 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/18 22:51:00 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**splitt;
	int				j;

	a = NULL;
	b = NULL;
	splitt = NULL;
	j = 0;
	if (ac > 1)
	{
		while (++j < ac)
		{
			if ((!av[j][0]) || space_check(av[j]) || error_syntax(av[j]))
				free_errors(&a);
			splitt = ft_split(av[j], ' ');
			init_stack_a(&a, splitt);
			free_split(splitt);
		}
	}
	sort_and_free(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
