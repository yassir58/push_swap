#include "push_swap.h"
#include "get_next_line.h"


void apply_p_instr (t_stack **A, t_stack **B, char *instr)
{
    if (strcmp (instr, "pa\n") == 0)
        push_element (A, B, 'a');
    else if (strcmp (instr, "pb\n") == 0)
        push_element (A, B, 'b');
}

void apply_r_instr (t_stack **A, t_stack **B, char *instr)
{
     if (strcmp (instr, "ra\n") == 0)
        rotate_stack (A, 'a');
    else if (strcmp (instr, "rb\n") == 0)
        rotate_stack (B, 'b');
    if (strcmp (instr, "rra\n") == 0)
        r_rotate_stack (A, 'a');
    else if (strcmp (instr, "rrb\n") == 0)
        r_rotate_stack (B, 'b');
    else if (strcmp (instr, "rr\n") == 0)
        rotate_r (A, B);
    else if (strcmp (instr, "rrr\n") == 0)
        r_rotate_r (A, B);
}

void apply_s_instr (t_stack **A, t_stack **B, char *instr)
{
    if (strcmp (instr, "sa\n") == 0)
        swap_element (A, 'a');
    else if (strcmp (instr, "sb\n") == 0)
        swap_element (B, 'b');
    else if (strcmp (instr, "ss\n") == 0)
        swap_s (A, B);
}



int main (int argc, char *argv [])
{
    t_stack *top;
    t_stack *B;
    //t_stack *temp;

    B = NULL;
    top = NULL;
    // testing
    char *str;
    check_for_valid_input (argc, argv);
    create_stack (&top, argc, argv);
    check_for_duplicate (top);
    check_if_sorted (top);
    
    while ((str = get_next_line (1)))
    {
        //valid_instructions (str);
        if (str[0] == 's')
            apply_p_instr (&top, &B, str);
        else if (str[0] == 'p')
            apply_p_instr (&top, &B, str);
        else if (str[0] == 'r')
            apply_r_instr (&top, &B, str);
        else if (str[0] == '\n' || str[0] == '\0')
            break;
        
        free (str);
    }
    print_stack (top);
    check_if_sorted (top);
    free_stack (&top);
    free_stack (&B);
    free (top);
    free (B);
   

    return (0);
}