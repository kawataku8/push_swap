/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:43:45 by takuya            #+#    #+#             */
/*   Updated: 2021/04/08 18:32:44 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		op_stack;
	t_stack		a_stack;
	t_stack		b_stack;
	t_stackdata	stackdata;

	op_stack.head = NULL;
	op_stack.tail = NULL;
	a_stack.head = NULL;
	a_stack.tail = NULL;
	b_stack.head = NULL;
	b_stack.tail = NULL;

	stackdata.a_stack = &a_stack;
	stackdata.b_stack = &b_stack;
	if (argc < 2 || !(make_stack(argc, argv, &a_stack)))
		end_program("Error\n", NULL, &a_stack, &b_stack);
	if (a_stack.head == NULL)
		end_program("Error\n", NULL, &a_stack, &b_stack);
	if (!(check_duplicates(&a_stack)))
		end_program("Error\n", NULL, &a_stack, &b_stack);
	a_to_b_sort(&op_stack, &stackdata, stack_len(a_stack.head), 1);

	// print_op_stack(&op_stack);

	if (validate_sort(stackdata.a_stack,stackdata.b_stack) == 1)
		printf("OK\n");
	else
		printf("KO\n");
	
	clear_stack(&op_stack);
	end_program(NULL, NULL, &a_stack, &b_stack);
	return (0);
}
