/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:24:03 by takuya            #+#    #+#             */
/*   Updated: 2021/04/06 15:46:55 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char check_pattern(int top, int mid, int bot)
{
    if (top < mid && top < bot)
    {
        if (mid > bot)
            return ('A');
    }
    else if(mid < top && mid < bot)
    {
        if(top > bot)
            return ('B');
        else
            return ('C');
    }
    else
    {
        if (top > mid)
            return ('D');
        else
            return ('E');
    }
    return ('Z');
}

void sort_3numbers(t_stack *op_stack, t_stack *stack, char flag)
{
    int top;
    int mid;
    int bot;
    char pattern;

    top = *(int*)stack->head->data;
    mid = *(int*)stack->head->next->data;
    bot = *(int*)stack->head->next->next->data;
    if (flag == 'a')
    {
        pattern = check_pattern(top, mid, bot);
        if (pattern == 'A')
            sort_pattern_a_A(op_stack,stack);
        else if (pattern == 'B')
            sort_pattern_a_B(op_stack,stack);
        else if (pattern == 'C')
            sort_pattern_a_C(op_stack,stack);
        else if (pattern == 'D')
            sort_pattern_a_D(op_stack,stack);
        else if (pattern == 'E')
            sort_pattern_a_E(op_stack,stack);
    }
    else
    {
        pattern = check_pattern(top, mid, bot);
        if (pattern == 'A')
            sort_pattern_b_A(op_stack,stack);
        else if (pattern == 'B')
            sort_pattern_b_B(op_stack,stack);
        else if (pattern == 'C')
            sort_pattern_b_C(op_stack,stack);
        else if (pattern == 'E')
            sort_pattern_b_E(op_stack,stack);
        else if (pattern == 'Z')
            sort_pattern_b_Z(op_stack,stack);
    }
}