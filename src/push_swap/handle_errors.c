/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:56:57 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/18 23:03:57 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

void	free_stack(t_stack_node	**stack)
{
	t_stack_node	*ephemeral;
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		ephemeral = current->next;
		current->nbr = 0;
		free(current);
		current = ephemeral;
	}
	*stack = NULL;
}

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
        i++;
	if (str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' || str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}

int	error_duplicate(t_stack_node *a, int n)
{
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_errors(t_stack_node	**a)
{
	free_stack(a);
	write (2, "Error\n", 6);
	exit(1);
}

int	space_check(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] != ' ' && arg[i] != '\t')
			return (0);
	}
	return (1);
}
