#include "push_swap.h"

int check_number (int indx, int number, int array[])
{
    int i = 0;

    while (i < indx)
    {
        if (array[i] == number)
            return (0);
        i++;
    }
    return (1);
}

int *generate_numbers (int n)
{
    int indx;
    int num;
    int *output;

    output = (int *)malloc(sizeof(int) * n);
    if (!output)
        return (NULL);
    indx = 0;
    while (indx < n)
    {
        num = rand () % n  + 1;
        if (check_number(indx, num, output))
            output[indx++] = num;
    }
    return (output);
}

int num_len (int num)
{
    int i=0;
    int rem = num;
    while (rem)
    {
        rem = rem / 10;
        i++;
    }
    return (i);
}

char *ft_itoa (int num)
{
    char *str;
    int len = 0;

    len = num_len (num);
    str =  (char *) malloc (sizeof (char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = 0;
    while (len--)
    {
        str[len] = (num % 10) + 48;
        num /= 10; 
    }
    return (str);
}

char **get_numbers(int *output, int n)
{
    char **tmp;
    int i;
    

    tmp = (char **)malloc(sizeof(char *) * (n + 1));
    if (!tmp)
        return (NULL);
    tmp[n] = NULL; 
    i = 0;
    while (i < n)
    {
        tmp[i] = ft_itoa(output[i]);
        i++;
    }
    return (tmp);
}


void free_elements (char **argm, int *numbers)
{
    int i = 0;

    while (argm[i])
    {
        free (argm[i]);
        i++;
    }
    free (argm);
    free (numbers);
}

int main (int argc, char *argv[])
{
    char **output;
    int *numbers;
    int i;
    int n;

    i = 0;
    if (argc <= 1)
    {
        printf ("Error!\n");
        return (1);
    }
    n = atoi (argv[argc - 1]); 
    numbers = generate_numbers(n);
    output = get_numbers(numbers, n);
    while (i < n)
    {
        
        printf("%s", output[i]);
        if (i < (n - 1))
            printf(" ");
        i++;
    }
    free_elements (output, numbers);
    return (0);
}


