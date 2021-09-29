/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:03:13 by takuya            #+#    #+#             */
/*   Updated: 2021/04/08 17:06:30 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// t_node *find_midnum_node(t_node *sorted_nodes, int *chunk_number)
// {
//     t_node *fast; 
//     t_node *slow; 
//     slow = sorted_nodes; 
//     fast = sorted_nodes->next; 
	
//     /* Advance 'fast' two nodes, and advance 'slow' one node */
//     while (fast != NULL) 
//     { 
//         fast = fast->next; 
//         if (fast != NULL) { 
//             (*chunk_number)++;
//             slow = slow->next; 
//             fast = fast->next; 
//         } 
//     }
//     return (slow);
// }

t_node *find_midnum_node(t_node *sorted_nodes, int *chunk_number)
{
	int len;
	t_node *cur_node;

	len = stack_len(sorted_nodes) / 2;
	if ((stack_len(sorted_nodes) % 2) != 0)
		len += 1;
	cur_node = sorted_nodes;

	while(len > 0)
	{
		cur_node = cur_node->next;
		len--;
		(*chunk_number)++;
	}
	return (cur_node);
}


void print_nodes(t_node *head_node)
{
	t_node *node = head_node;

	while(node != NULL)
	{
		printf("%d\n",*(int*)(node->data));
		node = node->next;
	}
}

int stackl_copy(t_stack *a_stack, t_stack *copy, int len)
{
	t_node *cur_node;
	t_node *new_node;
	int *p;

	cur_node = a_stack->head;
	while (cur_node != NULL && len > 0)
	{
		if (!(p = (int*)malloc(sizeof(int))))
			return (0);
		*p = *(int*)cur_node->data;
		if (!(new_node = make_node((void*)p)))
			return (0);
		insert_end(copy, new_node);
		cur_node = cur_node->next;
		len--;
	}
	return (1);
}

void FrontBackSplit(t_node *source, t_node **frontRef, t_node **backRef) 
{ 
	t_node *fast; 
	t_node *slow; 
	slow = source; 
	fast = source->next; 
  
	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) { 
		fast = fast->next; 
		if (fast != NULL) { 
			slow = slow->next; 
			fast = fast->next; 
		} 
	} 
  
	/* 'slow' is before the midpoint in the list, so split it in two 
	at that point. */
	*frontRef = source; 
	*backRef = slow->next; 
	slow->next = NULL; 
} 

t_node *SortedMerge(t_node *a, t_node *b) 
{ 
	t_node *result = NULL; 
  
	/* Base cases */
	if (a == NULL) 
		return (b); 
	else if (b == NULL) 
		return (a); 
  
	/* Pick either a or b, and recur */
	if (*(int*)a->data <= *(int*)b->data) { 
		result = a; 
		result->next = SortedMerge(a->next, b); 
	} 
	else { 
		result = b; 
		result->next = SortedMerge(a, b->next); 
	} 
	return (result); 
} 


void MergeSort(t_node **headRef) 
{ 
	t_node *head = *headRef; 
	t_node *a; 
	t_node *b; 
  
	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 
  
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b); 
  
	/* Recursively sort the sublists */
	MergeSort(&a); 
	MergeSort(&b); 
  
	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b); 
} 

t_node *SortedMerge_descend(t_node *a, t_node *b) 
{ 
	t_node *result = NULL; 
  
	/* Base cases */
	if (a == NULL) 
		return (b); 
	else if (b == NULL) 
		return (a); 
  
	/* Pick either a or b, and recur */
	if (*(int*)a->data >= *(int*)b->data) { 
		result = a; 
		result->next = SortedMerge_descend(a->next, b); 
	} 
	else { 
		result = b; 
		result->next = SortedMerge_descend(a, b->next); 
	} 
	return (result); 
} 

void MergeSort_descend(t_node **headRef) 
{ 
	t_node *head = *headRef; 
	t_node *a; 
	t_node *b; 
  
	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 
  
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b); 
  
	/* Recursively sort the sublists */
	MergeSort_descend(&a); 
	MergeSort_descend(&b); 
  
	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge_descend(a, b); 
} 

// if num in upper returns 1, in below returns 2
int below_num_pos(t_stack *a_stack, int border)
{
	t_node *cur_node;
	int len;
	int ret;
	
	ret = 0;
	len = stack_len(a_stack->head);
	cur_node = a_stack->head;
	while (cur_node != NULL)
	{
		if (*(int*)cur_node->data < border)
			break ;
		ret++;
		cur_node = cur_node->next;
	}
	if (ret <= (len / 2))
		ret = 1;
	else
		ret = 2;
	return (ret);
}

int upper_num_pos(t_stack *a_stack, int border)
{
	t_node *cur_node;
	int len;
	int ret;
	
	ret = 0;
	len = stack_len(a_stack->head);
	cur_node = a_stack->head;
	while (cur_node != NULL)
	{
		if (*(int*)cur_node->data > border)
			break ;
		ret++;
		cur_node = cur_node->next;
	}
	if (ret <= (len / 2))
		ret = 1;
	else
		ret = 2;
	return (ret);
}

void init_pop_below_midnum(int mid_num, int chunk_num, t_stack *op_stack,t_stackdata *stkdata)
{
	int flag;

	while (chunk_num > 0)
	{
		flag = below_num_pos(stkdata->a_stack, mid_num);
		while (!(mid_num > *(int*)stkdata->a_stack->head->data))
		{
			if (flag == 1)
			{
				ft_ra_rb(stkdata->a_stack);
				add_operation(op_stack,"ra");
			}
			else
			{
				ft_rra_rrb(stkdata->a_stack);
				add_operation(op_stack,"rra");
			}
		}
		ft_pa_pb(stkdata->b_stack, stkdata->a_stack);
		add_operation(op_stack,"pb");
		chunk_num--;

	}
}

int pop_below_midnum(int mid_num, int chunk_num, t_stack *op_stack, t_stackdata *stkdata)
{
	int rb_counter = 0;
	int pop_counter = 0;
	
	while (chunk_num > 0)
	{
		if (mid_num > *(int*)stkdata->a_stack->head->data)
		{
			ft_pa_pb(stkdata->b_stack, stkdata->a_stack);
			add_operation(op_stack,"pb");
			pop_counter++;
			chunk_num--;
		}
		else
		{
			ft_ra_rb(stkdata->a_stack);
			add_operation(op_stack, "ra");
			rb_counter++;
		}
	}
	while (rb_counter-- > 0)
	{
		ft_rra_rrb(stkdata->a_stack);
		add_operation(op_stack,"rra");
	}
	return (pop_counter);
}

int pop_upper_midnum(int mid_num, int chunk_num,t_stack *op_stack, t_stackdata *stkdata)
{
	int rb_counter = 0;
	int pop_counter = 0;
	
	while(chunk_num > 0)
	{   
		if (mid_num < *(int*)stkdata->b_stack->head->data)
		{
			ft_pa_pb(stkdata->a_stack, stkdata->b_stack);
			add_operation(op_stack,"pa");
			pop_counter++;
			chunk_num--;
		}
		else
		{
			ft_ra_rb(stkdata->b_stack);
			add_operation(op_stack,"rb");
			rb_counter++;
		}
	}
	while (0 < rb_counter--)
	{
		ft_rra_rrb(stkdata->b_stack);
		add_operation(op_stack,"rrb");

	}
	return (pop_counter);
}

int make_chunknum_stack(int chunk_num, t_stack *chunk_numbers)
{
	int *p;
	t_node *new_node;

	if (!(p = (int*)malloc(sizeof(int))))
		return (0);
	*p = chunk_num;
	if (!(new_node = make_node((void*)p)))
		return (0);
	insert_end(chunk_numbers, new_node);
	return (1);
}

int stack_len(t_node *head)
{
	int len;
	t_node *cur_node;

	len = 0;
	cur_node = head;
	while (cur_node != NULL)
	{
		len++;
		cur_node = cur_node->next;
	}
	return (len);
}

int stklen_less3(t_node *head)
{
	int len;
	t_node *cur_node;

	len = 0;
	cur_node = head;
	while(cur_node != NULL && len < 4)
	{
		len++;
		cur_node = cur_node->next;
	}
	if (len > 3)
		return (0);
	return (1);
}

int a_chunk_sorted(t_node *head)
{
	int len;
	t_node *cur_node;

	len = 0;
	cur_node = head;
	while (cur_node != NULL)
	{
		if (cur_node->next)
		{
			if (*(int*)(cur_node->data) > *(int*)(cur_node->next->data))
				return (-1);
		}
		cur_node = cur_node->next;
		len++;
	}
	return (len);
}

int b_chunk_sorted(t_node *head)
{
	int len;
	t_node *cur_node;

	len = 0;
	cur_node = head;
	while (cur_node != NULL)
	{
		if (cur_node->next)
		{
			if (*(int*)(cur_node->data) < *(int*)(cur_node->next->data))
				return (-1);
		}
		cur_node = cur_node->next;
		len++;
	}
	return (len);
}

