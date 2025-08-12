/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:20:20 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/12 19:47:29 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static void swap(t_stack_node	**stack)
{//change name to top 
	if (!*stack || !(*stack)->next)//Check if the stop node, or the second stock of stack exist
		return ;
	*stack = (*stack)->next; //Update `top` to point to the next node, effectively swapping the first and second nodes
	(*stack)->prev->prev = *stack; //Update the `prev` pointer of the node before the `new top` to point to the `new top`
	(*stack)->prev->next = (*stack)->next; //Update the `next` pointer of the node before the `new head` to skip the `old top` and point directly to the `new top`
	if ((*stack)->next) //Check if there's a `next` node after the `new top` and
		(*stack)->next->prev = (*stack)->prev; //If so, update its `prev` pointer to point back to the `new top`
	(*stack)->next = (*stack)->prev; //Update the `next` pointer of the `new top` to point to the `old head`, effectively reversing their positions
	(*stack)->prev = NULL; //Sets the `prev` pointer of the `new head` to `NULL` completing the swap
}

void	sa(t_stack_node	**a, bool print)
{
	swap(*&a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node	**b, bool print)
{
	swap(*&b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node		**a, t_stack_node	**b,	bool print)
{
	swap(*&a);
	swap(*&b);//Exist one way that i could do this at the same time and wrote in one line ?
	if(!print)
		ft_printf("ss\n");
}


//Errors that i find while im doing these function 

//expression must have pointer-to-struct-or-union type but it has type "t_stack_node **" (aka "struct s_stack_node **")C/C++(132)

/*static void swap(t_stack_node **stack) // stack = pointer to a pointer to the top node
{
    // 1. Check if we have at least two nodes to swap
    if (!*stack                  // *stack → the top node pointer
        ||                       // logical OR
        !(*stack)->next)         // (*stack)->next → pointer to the 2nd node
        return;                  // if either is NULL, leave the function

    // 2. Move the "top pointer" from the first node to the second node
    // *stack = (*stack)->next means:
    // - Right side: (*stack)->next → follow the top node to get the address of node 2
    // - Left side: *stack → the variable that stores the top node pointer
    // Assigning changes the top pointer to point to node 2's address
    *stack = (*stack)->next;

    // 3. Set the old top node's prev to point to the new top
    // (*stack) = new top (node 2)
    // ->prev = old top (node 1)
    // ->prev = *stack means: old top's prev pointer now stores new top's address
    (*stack)->prev->prev = *stack;

    // 4. Make old top's next pointer skip new top and point to what new top was pointing to
    // (*stack) = new top
    // ->prev = old top
    // ->next = (*stack)->next means:
    //     old top's next pointer now points to the third node (or NULL if none)
    (*stack)->prev->next = (*stack)->next;

    // 5. If there is a third node after the new top
    if ((*stack)->next)
        // Set that third node's prev pointer to point back to the old top
        (*stack)->next->prev = (*stack)->prev;

    // 6. Make new top's next pointer point to old top
    (*stack)->next = (*stack)->prev;

    // 7. Make new top's prev pointer NULL because it's now the first node
    (*stack)->prev = NULL;
}*/