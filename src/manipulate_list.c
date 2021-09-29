/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:21:34 by tkawahar          #+#    #+#             */
/*   Updated: 2021/03/13 15:50:51 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node *make_node(void *data)
{
    t_node *new_node;

    if (!(new_node = (t_node*)malloc(sizeof(t_node))))
        return (NULL);
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return (new_node);
}

void insert_after(t_stack *stack, t_node *node, t_node *new_node)
{
    new_node->prev = node;
    new_node->next = node->next;
    if (node->next == NULL)
        stack->tail = new_node;
    else
        node->next->prev = new_node;
    node->next = new_node;
}

void insert_before(t_stack *stack, t_node *node, t_node *new_node)
{
    new_node->prev = node->prev;
    new_node->next = node;
    if (node->prev == NULL)
        stack->head = new_node;
    else
        node->prev->next = new_node;
    node->prev = new_node;
}

void insert_beginning(t_stack *stack, t_node *new_node)
{
    if (stack->head == NULL)
    {
        stack->head = new_node;
        stack->tail = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    else
        insert_before(stack,stack->head, new_node);
}

void insert_end(t_stack *stack, t_node *new_node)
{
    if (stack->tail == NULL)
        insert_beginning(stack, new_node);
    else     
        insert_after(stack, stack->tail, new_node);
}

void clear_stack(t_stack *stack)
{
    t_node *cur_node;
    t_node *next_node;

    if((cur_node = stack->head) != NULL)
    {
        while (cur_node->next != NULL)
        {
            next_node = cur_node->next;
            free(cur_node->data);
            free(cur_node);
            cur_node = next_node;
        }
        free(cur_node->data);
        free(cur_node);
    }
}

void remove_node(t_stack *stack,t_node *node)
{
    if (node->prev == NULL)
        stack->head = node->next;
    else
        node->prev->next = node->next;
    if (node->next == NULL)
        stack->tail = node->prev;
    else    
       node->next->prev = node->prev;
    free(node->data);
    free(node);
}

void print_stack(t_stack *stack)
{
    t_node *node = stack->head;

    while(node)
    {
        printf("%d\n",*(int*)(node->data));
        node = node->next;
    }
}

void print_operations(t_stack *stack)
{
    t_node *node = stack->head;

    while(node)
    {
        printf("%s\n",(char*)(node->data));
        node = node->next;
    }
}