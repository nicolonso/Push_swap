/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:28:26 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/07 23:40:29 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

static long ft_atoi_long(const char *s)
{
	long	result;
	long	sign;
	//Define a function that converts every string in a long value

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
	while (*s >= '0' && *s <= '9')// I can use if is digit for libft -- Implement later
		result = (result * 10) + (*s++ - 48);
	return (result * sign);
}

static void append_node(t_stack_node **stack, int n)
{
	//Define a function taht searches for the last node to append to the linked list
	t_stack_node	*node;
	t_stack_node	last_node;
	
	if(!stack)
		return ;
	node = malloc(sizeof(t_stack_node));//Allocate memory for the newnode
	if (!node)
		return ;//Search more info. about this
	node->next = NULL;//Set the nxt pointer of the new node to NULL becouse it will be the last node in the list
	node->nbr = n;//Set the 'next' data of the new node to 'n' value
	node->cheapest = 0;//Initiliase cheapest to 0;
	//other elements in the struct could be initialized as well but for now, this was only one causing a valgraind issue
	if(!(*stack))//Check if the stack is empty or currently pointing to NULL, indicating a first nose needs to be found
	{
		*stack = node;//If empty, update the pointer *stack to point to the node, effectively making it the new head of the linked list 
		node->prev = NULL;//Set the head node's previus pointer to NULL as it's the first node
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void init_stack_a(t_stack_node **a, char **av)
{
	//Define a function that initiates stack `a` by handling any errors and appending required nodes to complete a stack
	long	n;
	long	i;
	
	i = -1;
	while (av[++i])
	{
		if (error_syntax(av[i]))
			free_errors(a);
		n = ft_atoi_long(av[i]);
		if (n > INT_MAX || n < INT_MIN)//Check overflow
			free_errors(a);
		if(error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	 //Define a function that searches for the cheapest node, that is set by bool
	if(!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return(stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node	**stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)//Check if the required node is not already the first node
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
			ra(stack, false);
			else
				rra(stack, false);	
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
	
}
