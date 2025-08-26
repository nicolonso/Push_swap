#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack_node
{	int		nbr;
	struct s_stack_node	*next;
	struct s_stack_node	*target_node;
}	t_stack_node;

t_stack_node *new_node(int value)
{
    t_stack_node *node = malloc(sizeof(t_stack_node));
    node->nbr = value;
    node->next = NULL;
    node->target_node = NULL;
    return node;
}

void append_node(t_stack_node **stack, int value)
{
    t_stack_node *new = new_node(value);
    t_stack_node *last = *stack;
    if (!last)
    {
        *stack = new;
        return;
    }
    while (last->next)
        last = last->next;
    last->next = new;
}

t_stack_node *find_max(t_stack_node *stack)
{
    t_stack_node *max = stack;
    while (stack)
    {
        if (stack->nbr > max->nbr)
            max = stack;
        stack = stack->next;
    }
    return max;
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)//Find `a` node's target in stack `b`
{
	t_stack_node	*current_b; //To store the pointer to the current node in stack `b` and iterate through each node following
	t_stack_node	*target_node; //To store the pointer to the target node in stack `b`
	long			best_match_index; //In this case, the best match indexe stores the value of the "closest smaller number" so far

	while (a) //As long as we have nodes in stack `a`
	{
		best_match_index = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = b; //Assign to `current_b` the current `b` node
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			if (current_b->nbr < a->nbr 
				&& current_b->nbr > best_match_index) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->nbr; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match_index == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			a->target_node = find_max(b); //If so, find the biggest `nbr` and set this as the target node
		else
			a->target_node = target_node; //If no "closer smaller number" is found, and the best match has changed
		a = a->next; //Move to the next `a` node to find it's target `b` node
	}
}

int main(void)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    // Stack a: 10 -> 20 -> 5
    append_node(&a, 10);
    append_node(&a, 20);
    append_node(&a, 5);

    // Stack b: 15 -> 3 -> 30
    append_node(&b, 15);
    append_node(&b, 3);
    append_node(&b, 30);

    // Call the function
    set_target_a(a, b);

    // Print results
    t_stack_node *cur = a;
    while (cur)
    {
        printf("Node %d -> target %d\n", cur->nbr, cur->target_node->nbr);
        cur = cur->next;
    }

    return 0;
}