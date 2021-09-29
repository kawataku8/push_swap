/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threenum_sort2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:47:56 by takuya            #+#    #+#             */
/*   Updated: 2021/04/08 17:46:48 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_pattern_b_A(t_stack *op_stack, t_stack *stack)
{
    ft_sa_sb(stack);
    ft_ra_rb(stack);
    ft_sa_sb(stack);
    ft_rra_rrb(stack);
    add_operation(op_stack,"sb");
    add_operation(op_stack,"rb");
    add_operation(op_stack,"sb");
    add_operation(op_stack,"rrb");

}

void sort_pattern_b_B(t_stack *op_stack, t_stack *stack)
{
    ft_ra_rb(stack);
    ft_sa_sb(stack);
    ft_rra_rrb(stack);
    add_operation(op_stack,"rb");
    add_operation(op_stack,"sb");
    add_operation(op_stack,"rrb");
}

void sort_pattern_b_C(t_stack *op_stack, t_stack *stack)
{
    ft_ra_rb(stack);
    ft_sa_sb(stack);
    ft_rra_rrb(stack);
    ft_sa_sb(stack);
    add_operation(op_stack,"rb");
    add_operation(op_stack,"sb");
    add_operation(op_stack,"rrb");
    add_operation(op_stack,"sb");
}

void sort_pattern_b_E(t_stack *op_stack, t_stack *stack)
{
    ft_sa_sb(stack);
    add_operation(op_stack,"sb");
}

void sort_pattern_b_Z(t_stack *op_stack, t_stack *stack)
{
    ft_sa_sb(stack);
    ft_ra_rb(stack);
    ft_sa_sb(stack);
    ft_rra_rrb(stack);
    ft_sa_sb(stack);
    add_operation(op_stack,"sb");
    add_operation(op_stack,"rb");
    add_operation(op_stack,"sb");
    add_operation(op_stack,"rrb");
    add_operation(op_stack,"sb");
}