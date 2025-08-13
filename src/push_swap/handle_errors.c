/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:56:57 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/13 19:56:04 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

void free_stack(t_stack_node	**stack)
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
	if (!(str == '+' || str == '-' || (str >= '0' && str <= '9')))
		return (1);
	if (!(str[1] == '+' || str[1] == '-' || (str[1] >= '0' && str[1] <= '9')))
		return (1);
	while (*++str)
	{
		if (!(str >= '0' && str <= '9'))
			return (1);
	}
	return (0);
}

int error_duplicate(char *str)
{
	while (*++str)
	{
		if (*str == *str + 1)
			return (1);
	}
	return (0);
}

void	free_errors(t_stack_node	**a)
{
	free_stack(*&a);
	ft_printf("Error\n");
	exit(1);
}
