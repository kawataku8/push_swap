/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threenum_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:51:18 by takuya            #+#    #+#             */
/*   Updated: 2021/04/08 17:46:24 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_pattern_a_A(t_stack *op_stack,t_stack *stack)
{
    ft_ra_rb(stack);
    ft_sa_sb(stack);
    ft_rra_rrb(stack);
    add_operation(op_stack,"ra");
    add_operation(op_stack,"sa");
    add_operation(op_stack,"rra");
}

void sort_pattern_a_B(t_stack *op_stack, t_stack *stack)
{
    ft_sa_sb(stack);
    ft_ra_rb(stack);
    ft_sa_sb(stack);
    ft_rra_rrb(stack);
    add_operation(op_stack,"sa");
    add_operation(op_stack,"ra");
    add_operation(op_stack,"sa");
    add_operation(op_stack,"rra");
}

void sort_pattern_a_C(t_stack *op_stack, t_stack *stack)
{
    ft_sa_sb(stack);
    add_operation(op_stack,"sa");
}

void sort_pattern_a_D(t_stack *op_stack,t_stack *stack)
{
    ft_sa_sb(stack);
    ft_ra_rb(stack);
    ft_sa_sb(stack);
    ft_rra_rrb(stack);
    ft_sa_sb(stack);
    add_operation(op_stack,"sa");
    add_operation(op_stack,"ra");
    add_operation(op_stack,"sa");
    add_operation(op_stack,"rra");
    add_operation(op_stack,"sa");
}

void sort_pattern_a_E(t_stack *op_stack, t_stack *stack)
{
    ft_ra_rb(stack);
    ft_sa_sb(stack);
    ft_rra_rrb(stack);
    ft_sa_sb(stack);
    add_operation(op_stack,"ra");
    add_operation(op_stack,"sa");
    add_operation(op_stack,"rra");
    add_operation(op_stack,"sa");
}