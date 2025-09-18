/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:28:26 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/18 22:25:46 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static long	ft_atoi_long(const char *s)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = (result * 10) + (*s++ - 48);
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->nbr = n;
	node->next = NULL;
	node->cheapest = 0;
	node->above_median = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **av)
{
	long	n;
	long	i;

	i = -1;
	while (av[++i])
	{
		if (error_syntax(av[i]))
		{
			free_split(av);
			free_errors(a);
		}
		n = ft_atoi_long(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
	}
}

