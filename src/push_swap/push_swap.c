/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:13:41 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/16 20:52:54 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

/* int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				i;
	
	a = NULL;
	b = NULL;
	i = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2 && ft_strchr(av[1], ' '))
	{
		av = split(av[1], ' ');
		i = 1;
	}
	if (ac >= 2)
	{
		init_stack_a(&a, av + 1);
		{
			if (stack_len(a) == 1)
				return (free_stack(&a), free_stack(&b), 0);
			if (stack_len(a) == 2 && !sorted_stack(a))
				sa(&a, false);
			else if (stack_len(a) == 2 ||stack_len(a) == 3)
				sort_three(&a);
			else if (stack_len(a) > 3)
				sort_stacks(&a, &b);
		}
	}
	if (i == 1)
		free_split(av);
	return (free_stack(&a), free_stack(&b), 0);
}
 */
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
/* static void	sort_and_free(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 1)
	{
		free_stack(a);
		free_stack(b);
		exit(0);
	}
	if (stack_len(*a) == 2 && !sorted_stack(*a))
		sa(a, false);
	else if (stack_len(*a) == 2 || stack_len(*a) == 3)
		sort_three(a);
	else if (stack_len(*a) > 3)
		sort_stacks(a, b);
} */

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				splitted;

	a = NULL;
	b = NULL;
	splitted = 0;
	if (ac == 1)
		return (1);
	if ((ac == 2 && !av[1][0]))
		free_errors(&a);
	if (ac == 2 && ft_strchr(av[1], ' '))
	{
		av = split(av[1], ' ');
		splitted = 1;
	}
	if (ac >= 2)
		init_stack_a(&a, av + 1);
	sort_and_free(&a, &b);
	if (splitted == 1)
		free_split(av);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
