#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <limits.h> //To define MIN and MAX macros
#include <stdbool.h> //To use bool flags.
#include "libft.h"
#include <ft_printf.h>

//Structed
typedef struct s_stack_node // A cointainer for data ,enclosed by {} ,'s' for struct
{
    int                            num;
    int                            index;
    int                            push_cost;
    bool                           above_median;
    bool                           cheapest;
    struct s_stack_node            *target_node;
    struct s_stack_node            *next;
    struct s_stack_node            *prev;
}   s_stack_node;


//HaNdle errors


//Stack initiation

//Nodes intiation

//Stack utils

//Commands

//Algorithm

#endif
