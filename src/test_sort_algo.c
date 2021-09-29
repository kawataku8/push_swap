/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:03:13 by takuya            #+#    #+#             */
/*   Updated: 2021/04/08 17:42:07 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int stklen_less2(t_node *head)
{
	int len;
	t_node *cur_node;

	len = 0;
	cur_node = head;
	while(cur_node != NULL && len < 3)
	{
		len++;
		cur_node = cur_node->next;
	}
	if (len > 2)
		return (0);
	return (1);
}

// int b_to_a_sort(t_stack *op_stack, t_stack *a_stack, t_stack *b_stack, int chunk_num)
int b_to_a_sort(t_stack *op_stack, t_stackdata *stackdata, int chunk_num)
{
	int res;
	int pop_counter;
	t_stack tmp_stack;
	t_stack  mid_stack;

	pop_counter = 0;
	res = 0;
	tmp_stack.head = NULL;
	tmp_stack.tail = NULL;
	mid_stack.head = NULL;
	int sorted;
  
	stackl_copy(stackdata->b_stack,&tmp_stack, chunk_num);
	
	if ((sorted = b_chunk_sorted(tmp_stack.head)) > 0)
	{
		while (sorted > 0)
		{
			ft_pa_pb(stackdata->a_stack,stackdata->b_stack);
			add_operation(op_stack,"pa");
			sorted--;
		}
		clear_stack(&tmp_stack);
		return (8);
	}
	MergeSort_descend(&tmp_stack.head);
	mid_stack.head = tmp_stack.head;

	while(1)
	{
		if (stklen_less2(mid_stack.head) == 1)
			break ;
		chunk_num = 0;
		mid_stack.head = find_midnum_node(mid_stack.head,&chunk_num);

 
		pop_counter = 0;
		pop_counter = pop_upper_midnum(*(int*)(mid_stack.head->data), chunk_num, op_stack, stackdata);
			
		a_to_b_sort(op_stack, stackdata, pop_counter, 0);
	}
	int n = 2;
	if (stack_len(mid_stack.head) == 2)
	{
		if (*(int*)stackdata->b_stack->head->data < *(int*)stackdata->b_stack->head->next->data)
		{
			ft_sa_sb(stackdata->b_stack);
			add_operation(op_stack,"sb");
		}
		while(n > 0)
		{
			ft_pa_pb(stackdata->a_stack,stackdata->b_stack);
			add_operation(op_stack, "pa");
			n--;
		}
	}
	else
	{
		ft_pa_pb(stackdata->a_stack,stackdata->b_stack);
		add_operation(op_stack, "pa");
	}
	clear_stack(&tmp_stack);

	return (res);
}

void a_to_b_sort(t_stack *op_stack, t_stackdata *stackdata, int stk_len, int init_flag)
{
	int		chunk_num;
	t_stack	tmp_stack;
	t_stack	mid_stack;
	t_stack	chunk_numbers;

	chunk_numbers.head = NULL;
	chunk_numbers.tail = NULL;
	// tmp_stack.head = NULL;
	// tmp_stack.tail = NULL;
	// mid_stack.head = NULL;
	
	if(prep_sort(stackdata->a_stack,&tmp_stack, &mid_stack,stk_len) == 0)
		return ;
	// printf("yo\n");
	// stackl_copy(stackdata->a_stack,&tmp_stack, stk_len);
	// if ((a_chunk_sorted(tmp_stack.head)) > 0)
	// {
	// 	clear_stack(&tmp_stack);
	// 	return ;
	// }
	// MergeSort(&tmp_stack.head);
	// mid_stack.head = tmp_stack.head;

	while(1)
	{
		if (stklen_less3(mid_stack.head) == 1)
			break;
		chunk_num = 0;
		mid_stack.head = find_midnum_node(mid_stack.head,&chunk_num);
		make_chunknum_stack(chunk_num, &chunk_numbers);
		if (init_flag == 1)
			init_pop_below_midnum(*(int*)(mid_stack.head->data), chunk_num, op_stack, stackdata);
		else
			pop_below_midnum(*(int*)(mid_stack.head->data), chunk_num, op_stack, stackdata); 
	}
	if (stack_len(mid_stack.head) == 3)
		sort_3numbers(op_stack,stackdata->a_stack,'a');
	else if(stack_len(mid_stack.head) == 2 && (*(int*)stackdata->a_stack->head->data > *(int*)stackdata->a_stack->head->next->data))
	{
		ft_sa_sb(stackdata->a_stack);
		add_operation(op_stack,"sa");
	}

	t_node *chunk_node;
	chunk_node = chunk_numbers.tail;
	while (chunk_node)
	{
		b_to_a_sort(op_stack, stackdata, *(int*)chunk_node->data);
		chunk_node = chunk_node->prev;
	}
	clear_stack(&tmp_stack);
	clear_stack(&chunk_numbers);
}
