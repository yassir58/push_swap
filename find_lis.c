#include "push_swap.h"



int *find_len_arr (int *arr, int size)
{
    int i;
    int j;
    int *len_arr;
    int k;

    i = 0;
    j = 0;
    len_arr = malloc (sizeof (int) * size);
    if (!len_arr)
        return (NULL);
    k = 0;
    while (k < size)
    {
        len_arr[k] = 1;
        k++;
    }
    while (i < size)
    {
        while (j < i)
        {
            if (arr[j] < arr[i])
                len_arr[i] = len_arr[j] + 1;
            j++;
        }
        j = 0;
        i++;
    }
    return (len_arr);
}



int *find_indx_arr (int size)
{
    int k;
    int *indx_arr;

    indx_arr = malloc(sizeof(int) * size);
    if (!indx_arr)
        return (NULL);
    k = 0;
    while (k < size)
        indx_arr[k++] = -1;
    return (indx_arr);
}


int get_pos (int *len_arr, int size)
{
    int i;
    int temp;
    int pos;

    i = 1;
    temp = len_arr[0];
    temp = 0;
    pos = 0;
    while (i < size)
    {
        if (len_arr[i] > temp)
        {
            temp = len_arr[i];
            pos = i ;
        }
        i++;
    }
    return (pos);
}

int *construct_lis (int *arr, int *indx_arr, int *len_arr, int size, int max)
{
    int pos;
    int i;
    int *lis;

    pos = get_pos(len_arr, size);
    i = 0;
    lis = malloc (sizeof (int) * max);
    if (!lis)
        return (NULL);
    while (i < max)
        lis[i++] = 0;
    i = 0;
    while (pos != -1 && i < max)
    {
        lis[i++] = arr[pos];
        pos = indx_arr[pos];
    }
    return (lis);
}


int *init_lis (int *lis , int  size, int c)
{
    int i;

    i = 0;
    while (i < size)
        lis [i++] = c;
    return (lis);
}


void mark_elm (t_stack **A, int elm)
{
    int indx;
    t_stack *temp;

    indx = get_elm_indx (A, elm);
    temp = *A;
    while (temp && indx--)
        temp = temp->next;
    temp->lis = 1;
}
