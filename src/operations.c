/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:07:05 by takuya            #+#    #+#             */
/*   Updated: 2021/04/06 18:44:14 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_sa_sb(t_stack *list)
{
    void *tmp;

    if(list->head ==  NULL || list->head->next == NULL)
        return ;
    tmp = list->head->data;
    list->head->data = list->head->next->data;
    list->head->next->data = tmp;
}

void ft_ss(t_stack *a_stack, t_stack *b_stack)
{
    ft_sa_sb(a_stack);
    ft_sa_sb(b_stack);
}

void ft_ra_rb(t_stack *list)
{
    t_node *tmp;
    if(list->head == list->tail)
        return ;

    tmp  = list->head->next;
    insert_end(list,list->head);
    tmp->prev = NULL;
    list->head = tmp;

}

void ft_rr(t_stack *a_stack, t_stack *b_stack)
{
    ft_ra_rb(a_stack);
    ft_ra_rb(b_stack);
}

void ft_rra_rrb(t_stack *list)
{
    t_node *tmp;

    if (list->head == list->tail)
        return ;

    tmp = list->tail->prev;
    insert_beginning(list,list->tail);
    tmp->next = NULL;
    list->tail = tmp;
}

void ft_rrr(t_stack *a_stack, t_stack *b_stack)
{
    ft_rra_rrb(a_stack);
    ft_rra_rrb(b_stack);
}

// pa(a_stack,b_stack),pb(b_stack,a_stack)
void ft_pa_pb(t_stack *dest_stack, t_stack *src_list)
{
    t_node *tmp;

    if (src_list->head == NULL)
        return ;
    tmp = src_list->head->next;
    insert_beginning(dest_stack, src_list->head);
    if (tmp == NULL)
        src_list->tail = NULL;
    else
        tmp->prev = NULL;
    src_list->head = tmp;
}