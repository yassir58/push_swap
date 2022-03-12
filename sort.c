
#include "push_swap.h"

pos *find_best(t_stack **A, t_stack **B, int elm)
{
    t_stack *top;
    int *a_pos;
    int *b_pos;
    pos *elm_pos;

    top = *A;
    elm_pos = init_pos(A, B);
    if (elm > stack_max(*A) || elm < stack_min(*A))
        return (get_max_pos(A, B, elm));
    if (last_check(A, elm))
    {
        elm_pos = set_last_pos(elm_pos, B, elm);
        return (elm_pos);
    }
    while (top)
    {
        if (elm > top->data && elm < top->next->data)
        {
            a_pos = check_position(A, get_elm_indx(A, top->next->data));
            b_pos = check_position(B, get_elm_indx(B, elm));
            return (update_pos(elm_pos, a_pos, b_pos));
        }
        top = top->next;
    }
    return (elm_pos);
}

pos *chose_best_elm(pos *elm_pos, pos *min)
{

    if (elm_pos->a_rotate == elm_pos->b_rotate)
    {
        if (max_elm(elm_pos->a_pos, elm_pos->b_pos) < (min->a_pos + min->b_pos))
            return (elm_pos);
    }
    if ((elm_pos->a_pos + elm_pos->b_pos) < (min->a_pos + min->b_pos))
        return (elm_pos);
    return (min);
}

pos *calculate_best_elm(t_stack **A, t_stack **B)
{
    t_stack *temp_b;
    pos *tmp;
    pos *min;

    temp_b = *B;
    tmp = init_pos(A, B);
    min = init_pos(A, B);
    while (temp_b)
    {
        tmp = find_best(A, B, temp_b->data);
        min = chose_best_elm(tmp, min);
        temp_b = temp_b->next;
    }
    return (min);
}

void sort_stack(t_stack **A, t_stack **B)
{
    int size;
    pos *pos;

    size = stack_length(*B);
    while (size)
    {
        pos = calculate_best_elm(A, B);
        smart_rotate(pos, A, B);
        push_element(A, B, 'a');
        size = stack_length(*B);
        free(pos);
    }
    position_elm_top(A, get_elm_indx(A, stack_min(*A)));
}
