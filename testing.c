#include "push_swap.h"





void print_arr (int *arr, int size)
{
    int i;
    printf ("printing arr... \n");
    i = 0;
    while (i < size)
        printf ("%d ", arr[i++]);
    printf ("\n");
}


int *test_len_arr (int *arr, int size, int **indx_arr)
{

    int *len_arr;
    int i;
    int j;

    i = 0;
    j = 0;
    len_arr = malloc (sizeof (int) * size);
    if (!len_arr)
        return (NULL);
    while (i < size)
        len_arr[i++] = 1;
    i = 0;
    while (i < size) {
        while (j < i) {
            if (arr[j] < arr[i]&& len_arr[i] < len_arr[j] + 1)
            {
                len_arr[i] = len_arr[j] + 1;
                *(*indx_arr + i) = j;
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (len_arr);
}