/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:32:50 by tkawahar          #+#    #+#             */
/*   Updated: 2021/04/08 17:04:14 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "get_next_line.h"

typedef struct      s_node
{
    void *data;
    struct s_node *next;
    struct s_node *prev;
}                   t_node;


typedef struct      s_stack
{
    t_node *head;
    t_node *tail;
}                   t_stack;

typedef struct      s_stackdata
{
    t_stack *a_stack;
    t_stack *b_stack;
}                   t_stackdata;


t_node *make_node(void *data);
void insert_after(t_stack *list, t_node *node, t_node *new_node);
void insert_before(t_stack *list, t_node *node, t_node *new_node);
void insert_beginning(t_stack *list, t_node *new_node);
void insert_end(t_stack *list, t_node *new_node);
void clear_stack(t_stack *list);
void print_stack(t_stack *list);
void remove_node(t_stack *list,t_node *node);
void ft_sa_sb(t_stack *list);
void ft_ss(t_stack *a_list, t_stack *b_list);
void ft_ra_rb(t_stack *list);
void ft_rr(t_stack *a_list, t_stack *b_list);
void ft_rra_rrb(t_stack *list);
void ft_rrr(t_stack *a_list, t_stack *b_list);
void ft_pa_pb(t_stack *dest_stack, t_stack *src_list);
int check_duplicates(t_stack *stack);
void print_operations(t_stack *stack);
int is_str_num(char *str);
int validate_sort(t_stack *a_stack, t_stack *b_stack);
int make_stack(int argc, char **argv, t_stack *a_stack);
int check_duplicates(t_stack *stack);
int check_operations(char *line,t_stack *a_stack, t_stack *b_stack);
int read_operations(t_stack *operations);
int exec_operations(t_stack *operations, t_stack *a_stack, t_stack *b_stack);
void end_program(char *err_msg, t_stack *operations, t_stack *a_stack, t_stack *b_stack);
void insert_sort(t_stack *a_stack, t_stack *b_stack);
void clear_words(char **words);
void bubble_sort(t_stack *a_stack, t_stack *b_stack);
void left2num_sort(t_stack *a_stack, t_stack *b_stack);
int stackl_copy(t_stack *a_stack, t_stack *copy,int len);
int stack_len(t_node *head);
char check_pattern(int top, int mid, int bot);
void sort_3numbers(t_stack *op_stack, t_stack *stack, char flag);
void sort_pattern_a_A(t_stack *op_stack, t_stack *stack);
void sort_pattern_a_B(t_stack *op_stack, t_stack *stack);
void sort_pattern_a_C(t_stack *op_stack, t_stack *stack);
void sort_pattern_a_D(t_stack *op_stack, t_stack *stack);
void sort_pattern_a_E(t_stack *op_stack, t_stack *stack);
void sort_pattern_b_A(t_stack *op_stack, t_stack *stack);
void sort_pattern_b_B(t_stack *op_stack, t_stack *stack);
void sort_pattern_b_C(t_stack *op_stack, t_stack *stack);
void sort_pattern_b_E(t_stack *op_stack, t_stack *stack);
void sort_pattern_b_Z(t_stack *op_stack, t_stack *stack);
t_node *find_midnum_node(t_node *sorted_nodes, int *chunk_number);
void print_nodes(t_node *head_node);
int stackl_copy(t_stack *a_stack, t_stack *copy, int len);
void FrontBackSplit(t_node *source, t_node **frontRef, t_node **backRef);
t_node *SortedMerge(t_node *a, t_node *b);
void MergeSort(t_node **headRef);
t_node *SortedMerge_descend(t_node *a, t_node *b);
void MergeSort_descend(t_node **headRef);
int below_num_pos(t_stack *a_stack, int border);
void init_pop_below_midnum(int mid_num, int chunk_num,t_stack *op_stack ,t_stackdata *stkdata);
int pop_below_midnum(int mid_num, int chunk_num,t_stack *op_stack,t_stackdata *stkdata);
int pop_upper_midnum(int mid_num, int chunk_num, t_stack *op_stack, t_stackdata *stkdata);
int make_chunknum_stack(int chunk_num, t_stack *chunk_numbers);
int stack_len(t_node *head);
int stklen_less3(t_node *head);
int b_chunk_sorted(t_node *head);
int a_chunk_sorted(t_node *head);
int add_operation(t_stack *op_stack, char *op);
void print_op_stack(t_stack *op_stack);
int add_node(t_stack *stack,int data);
int prep_sort(t_stack *a_stack,t_stack *tmp_stack, t_stack *mid_stack,int stk_len);

void init_test_left2num_sort(t_stack *a_stack, t_stack *b_stack, int stk_len);
// int b_to_a_sort(t_stack *op_stack,t_stack *a_stack, t_stack *b_stack, int chunk_num);
int b_to_a_sort(t_stack *op_stack,t_stackdata *stackdata, int chunk_num);
// void a_to_b_sort(t_stack *op_stack, t_stack *a_stack, t_stack *b_stack, int stk_len, int init_flag);
void a_to_b_sort(t_stack *op_stack, t_stackdata *stackdata, int stk_len, int init_flag);
int last_pop_upper_midnum(int mid_num, int chunk_num, t_stack *a_stack, t_stack *b_stack);