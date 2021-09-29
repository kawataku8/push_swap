/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:31:54 by takuya            #+#    #+#             */
/*   Updated: 2021/04/08 17:42:42 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int prep_sort(t_stack *a_stack,t_stack *tmp_stack, t_stack *mid_stack,int stk_len)
{
	tmp_stack->head = NULL;
	tmp_stack->tail = NULL;
	mid_stack->head = NULL;

	stackl_copy(a_stack,tmp_stack, stk_len);
	if ((a_chunk_sorted(tmp_stack->head)) > 0)
	{
		clear_stack(tmp_stack);
		return (0);
	}
	MergeSort(&(tmp_stack->head));
	mid_stack->head = tmp_stack->head;
	return (1);
}


// int transfer_loop(t_stack *stackdata,t_stack *mid_stack, t_stack *chunk_numbers) 
// {
// 	int chunk_num;

// 	chunk_num = 0;
// 	while(1)
// 	{
// 		if (stklen_less3(mid_stack->head) == 1)
// 			break;
// 		chunk_num = 0;
// 		mid_stack->head = find_midnum_node(mid_stack->head,&chunk_num);
// 		make_chunknum_stack(chunk_num, chunk_numbers);
// 		if (init_flag == 1)
// 			init_pop_below_midnum(*(int*)(mid_stack->head->data), chunk_num, op_stack, stackdata->a_stack, stackdata->b_stack);
// 		else
// 			pop_below_midnum(*(int*)(mid_stack->head->data), chunk_num, op_stack, stackdata->a_stack, stackdata->b_stack); 
// 	}
	
// 	return (chunk_num);
// }