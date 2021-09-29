/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:03:46 by takuya            #+#    #+#             */
/*   Updated: 2021/04/06 15:19:04 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int add_operation(t_stack *op_stack, char *op)
{
    char *data;
    t_node *new_node;

    if (!(data = ft_strdup(op)))
        return (0);
    if (!(new_node = make_node((void*)data)))
        return (0);
    insert_end(op_stack, new_node);
    return (1);
}

void print_op_stack(t_stack *op_stack)
{
    t_node *node = op_stack->head;

    while(node)
    {
        printf("%s\n",(char*)(node->data));
        node = node->next;
    }
}