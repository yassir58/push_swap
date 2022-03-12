#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
// testing
#include <string.h>
#include <stdio.h>

typedef struct s_stack 
{
    int data;
    struct s_stack *next; 
    int indx;
    int lis;
    int len;
} t_stack;

typedef struct pos 
{
    int a_pos;
    int b_pos;
    int b_rotate;
    int a_rotate;
    int a_distance;
    int b_distance;
} pos;


void swap_element (t_stack **stack, char c);
void swap_s (t_stack **A, t_stack **B);
void push_element (t_stack **A, t_stack **B,char c);
void rotate_stack (t_stack **stack, char c);
void rotate_r (t_stack **A, t_stack **B);
void r_rotate_stack (t_stack **stack, char c);
void r_rotate_r (t_stack **A, t_stack **B);
void sort_3 (t_stack **a_top);
t_stack *create_node (int data);
int check_duplicate (t_stack *top);
void create_stack (t_stack **top, char *argv[]);
int check_if_sorted (t_stack *stack);
int stack_length (t_stack *stack);
int stack_max (t_stack *stack);
void position_elm_top (t_stack **stack, int elm_indx);
int stack_min (t_stack *stack);
int stack_empty (t_stack *stack);
int get_elm_indx (t_stack **stack, int elm);
void push_elm (t_stack **top, t_stack *node);
t_stack *pop_elm (t_stack **top);
int valid_number (char *str);
int valid_input (char *argv []);
void check_for_valid_input (int argc, char *argv[]);
void check_for_duplicate (t_stack *stack);
void print_stack (t_stack *top);
void sort_5 (t_stack **A, t_stack **B);
pos *pair_elm (t_stack **A, t_stack **B, int B_elm);


int *lis_len(int *stack, int siz/*, int *len*/);
int *convert_to_array(t_stack **stack, int size);
int *init_arr (int *arr,int c, int n);
int max_elm (int a, int b); /*  -------------  */
int arr_max (int *arr, int size);

void find_lis (t_stack **top); /*  -------------  */
int *construct_lis (int *arr, int *indx_arr, int *len_arr, int size, int max);
int *find_indx_arr (int size);
int *find_len_arr (int *arr, int size);
void mark_elements (int pos, t_stack **top); /*  -------------  */
void get_elm (t_stack **top, int indx);
int get_indx (int pos, t_stack **top);
void free_stack (t_stack **stack);
void extract_lis ( t_stack **A);
int in_lis (int *lis, int elm, int size);
int get_pos (t_stack **top);
t_stack *copy_stack (int *arr, int size);
void  prepare_stack(t_stack **stack); /*  -------------  */
void extract_elm (t_stack **A, int *lis, int size);
// int *init_lis (int *lis , int  size, int c);
void move_non_lis (t_stack **A, t_stack **B); /*  -------------  */
int count_len (t_stack **top); /*  -------------  */
void sort_stack (t_stack **A, t_stack **B); /*  -------------  */
pos *init_pos (t_stack **A, t_stack **B); /*  -------------  */
pos *update_pos (pos *elm_pos, int *temp_pos_a, int *temp_pos_b);
pos *get_elm_position (t_stack **A, t_stack **B,int next, int elm);
pos *calculate_best_elm (t_stack **A, t_stack **B); /*  -------------  */
int *get_non_lis (int *lis, int size, t_stack **A, int *non_lis_size);
int *check_position (t_stack **stack, int elm_indx);
void smart_rotate (pos *elm_pos, t_stack **A, t_stack **B); /*  -------------  */
void r_spec_rotate (t_stack **A, t_stack **B, int size,  int rotate); /*  -------------  */
void spec_rotate (t_stack **stack, int size, int rotate, int c); /*  -------------  */
pos *get_max_pos (t_stack **A, t_stack **B,  int elm);
void move_non_lis_to_B (t_stack **A, t_stack **B);
void mark_elm (t_stack **A, int elm);
int last_check (t_stack **A, int elm);
pos *find_best (t_stack **A, t_stack **B, int elm); /*  -------------  */
pos* chose_best_elm (pos *elm_pos, pos *min); /*  -------------  */
void sim_rotate (pos *elm, t_stack **A , t_stack **B);
void sim_pos ( pos* elm, t_stack **A , t_stack **B);
void smart_rotate (pos *elm_pos, t_stack **A, t_stack **B);
void diff_rotate (pos *elm, t_stack **A , t_stack **B);
pos* set_last_pos (pos *elm_pos, t_stack **B, int elm);
void set_indx_len(t_stack **node, int len, int indx);

// checker
int found_elm (char *instr[], char *ins);
int check_valid_instr(char  *argv);
int apply_p_instr (t_stack **A, t_stack **B, char *instr);
int apply_r_instr (t_stack **A, t_stack **B, char *instr);
int apply_s_instr (t_stack **A, t_stack **B, char *instr);
void valid_instructions (char *arg, t_stack *A, t_stack *B);
void free_all (t_stack *A, t_stack *B);
int check_function (t_stack *a_top, t_stack *b_top);
char	**ft_split(char const *s, char c);
char **join_vector (char **dst_vector, char **src_vector);
char **push_str (char **dst_vector, char *str);
char **process_args (int argc, char *argv[]);
void	free_tab(char **tab);
int	ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
int vector_size (char **vector);
int	ft_strcmp(const char *str1, const char *str2);

// testing 
void print_arr (int *arr, int size);
int *test_len_arr (int *arr, int size, int **indx_arr);
void print_stack (t_stack *stack);


#endif