#include "push_swap.h"

int  main(int ac, char  *av[])
{
    t_stack_node  *a; //To store pointer to stack 'a'
    t_stack_node  *b; //To store pointer to stack 'b'

    a = NULL;
    b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0])) //Check for incorrect argument counts or if the 2nd argument is '0'
        return (1);
    else if (ac == 2)//Check if the argument count is 2 and the 2nd is not empty, this implies a string
        //av = split (re-build my split function that needed handle doesnt matter how manys data i give to it)
    return (0);
}
