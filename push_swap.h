/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:34:33 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/17 12:51:33 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

/// testing 
#include <stdio.h>

# define _INT_MAX 2147483647
# define _INT_MIN -2147483648

typedef long long int	t_long ;

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	int				indx;
	int				lis;
	int				len;
}	t_stack;

typedef struct s_pos
{
	int	a_pos;
	int	b_pos;
	int	b_rotate;
	int	a_rotate;
}	t_pos;

void	swap_element(t_stack **stack, char c);
void	swap_s(t_stack **A, t_stack **B);
void	push_element(t_stack **A, t_stack **B, char c);
void	rotate_stack(t_stack **stack, char c);
void	rotate_r(t_stack **A, t_stack **B);
void	r_rotate_stack(t_stack **stack, char c);
void	r_rotate_r(t_stack **A, t_stack **B);
void	sort_3(t_stack **a_top);
t_stack	*create_node(int data);
int		check_duplicate(t_stack *top);
void	create_stack(t_stack **top, char *argv[]);
int		check_if_sorted(t_stack *stack, t_stack *stack_b);
int		stack_length(t_stack *stack);
int		stack_max(t_stack *stack);
void	position_elm_top(t_stack **stack, int elm_indx);
int		stack_min(t_stack *stack);
int		stack_empty(t_stack *stack);
int		get_elm_indx(t_stack **stack, int elm);
void	push_elm(t_stack **top, t_stack *node);
t_stack	*pop_elm(t_stack **top);
int		valid_number(char *str);
int		valid_input(char *argv []);
void	check_for_valid_input(char *argv[]);
void	check_for_duplicate(t_stack *stack, char **vector);
void	print_stack(t_stack *top);
void	sort_5(t_stack **A, t_stack **B);
t_pos	*pair_elm(t_stack **A, t_stack **B, int B_elm);
int		ft_isdigit(char c);
int		max_elm(int a, int b);
void	find_lis(t_stack **top);
void	mark_elements(int pos, t_stack **top);
void	get_elm(t_stack **top, int indx);
int		get_indx(int pos, t_stack **top);
void	free_stack(t_stack **stack);
void	extract_lis(t_stack **A);
int		in_lis(int *lis, int elm, int size);
int		get_pos(t_stack **top);
t_stack	*copy_stack(int *arr, int size);
void	prepare_stack(t_stack **stack);
void	extract_elm(t_stack **A, int *lis, int size);
void	move_non_lis(t_stack **A, t_stack **B);
int		count_len(t_stack **top);
void	sort_stack(t_stack **A, t_stack **B);
t_pos	*init_pos(t_stack **A, t_stack **B);
t_pos	*update_pos(t_pos *elm_pos, t_stack **A, t_stack **B, int *arr);
t_pos	*get_elm_position(t_stack **A, t_stack **B, int next, int elm);
t_pos	*calculate_best_elm(t_stack **A, t_stack **B);
int		*get_non_lis(int *lis, int size, t_stack **A, int *non_lis_size);
int		*check_position(t_stack **stack, int elm_indx);
void	smart_rotate(t_pos *elm_pos, t_stack **A, t_stack **B);
void	r_spec_rotate(t_stack **A, t_stack **B, int size, int rotate);
void	spec_rotate(t_stack **stack, int size, int rotate, int c);
t_pos	*get_max_pos(t_stack **A, t_stack **B, int elm, t_pos *elm_pos);
int		last_check(t_stack **A, int elm);
t_pos	*find_best(t_stack **A, t_stack **B, int elm);
t_pos	*chose_best_elm(t_pos *elm_pos, t_pos *min);
void	sim_rotate(t_pos *elm, t_stack **A, t_stack **B);
void	sim_pos(t_pos *elm, t_stack **A, t_stack **B);
void	smart_rotate(t_pos *elm_pos, t_stack **A, t_stack **B);
void	diff_rotate(t_pos *elm, t_stack **A, t_stack **B);
t_pos	*set_last_pos(t_pos *elm_pos, t_stack **B, int elm);
void	set_indx_len(t_stack **node, int len, int indx);
t_pos	*update_elm_pos(t_pos *elm_pos, t_pos *min);
int		found_elm(char *instr[], char *ins);
int		check_valid_instr(char *argv);
void	apply_p_instr(t_stack **A, t_stack **B, char *instr);
void	apply_r_instr(t_stack **A, t_stack **B, char *instr);
void	apply_s_instr(t_stack **A, t_stack **B, char *instr);
int		valid_instructions(char *arg);
void	free_all(t_stack *A, t_stack *B);
char	**check_function(void);
char	**ft_split(char const *s, char c);
char	**join_vector(char **dst_vector, char **src_vector);
char	**push_str(char **dst_vector, char *str);
char	**process_args(int argc, char *argv[]);
void	free_tab(char **tab);
t_long	ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
int		vector_size(char **vector);
int		ft_strcmp(const char *str1, const char *str2);
int		*get_arr(int a, int b);
void	sort_helper_1(t_stack **a_top);
void	sort_helper_2(t_stack **a_top);
int		range_num(long long int num, t_stack **stack, char **tab);
void	clean_function(t_stack *a_top, t_stack *b_top, char **vector);
void 	*handle_err ();
int 	one_word (char *str);
char	**one_word_tab (char *str);
void *instruction_err (char *str, char **tab);
void init_stack (t_stack **a_top, char **vector);
void sort_test (t_stack **a_top, t_stack **b_top, char **instr);
void rotate_instructions (t_stack **a_top, t_stack **b_top, char *instr);

#endif
