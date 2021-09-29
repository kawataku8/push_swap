/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:37:10 by takuya            #+#    #+#             */
/*   Updated: 2021/03/25 16:37:44 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void insert_sort(t_stack *a_stack, t_stack *b_stack)
// {
//     int times = 0;
    
//     while (a_stack->head != NULL && a_stack->tail != NULL)
//     {
//         if (b_stack->head == NULL || *(int*)a_stack->head->data > *(int*)b_stack->head->data)
//         {
//             ft_pa_pb(b_stack, a_stack);
//             times++;
//         }
//         else if(*(int*)a_stack->head->data < *(int*)b_stack->tail->data)
//         {
//             ft_pa_pb(b_stack, a_stack);
//             ft_ra_rb(b_stack);
//             // if(*(int*)a_stack->head->data > *(int*)a_stack->tail->data)
//             //     ft_rr(a_stack,b_stack);
//             // else
//             //     ft_ra_rb(b_stack);
//             times += 2;
//         }
//         else
//         {
//             while(b_stack->head != NULL && !(*(int*)(a_stack->head->data) > *(int*)(b_stack->head->data)))
//             {
//                 ft_pa_pb(a_stack,b_stack);
//                 ft_sa_sb(a_stack);
//                 times += 2;
//             }
//             ft_pa_pb(b_stack, a_stack);
//             times++;
//             while(a_stack->head != NULL && *(int*)(a_stack->head->data) > *(int*)(b_stack->head->data))
//             {
//                 ft_pa_pb(b_stack, a_stack);
//                 times++;
//             }
//         }
//     }
//     while(b_stack->head != NULL)
//     {
//         ft_pa_pb(a_stack,b_stack);
//         times++;
//     }
//     printf("TIMES:%d\n",times);
// }

// int find_min(t_stack *a_stack)
// {
//     int min;
//     t_node *cur_node;
    
//     min = *(int*)a_stack->head->data;
//     cur_node = a_stack->head;
//     while(cur_node != NULL)
//     {
//         if (min > *(int*)cur_node->data)
//             min = *(int*)cur_node->data;
//         cur_node = cur_node->next;
//     }
//     return min;
// }

// // uppser -> 1, down -> 2
// int min_location(int min, t_stack *a_stack)
// {
//     t_node *head_node = a_stack->head;
//     t_node *tail_node = a_stack->tail;
//     while(head_node != NULL)
//     {
//         if (*(int*)head_node->data == min)
//             return 1;
//         else if (*(int*)tail_node->data == min)
//             return 2;
//         head_node = head_node->next;
//         tail_node = tail_node->prev;
//     }
//     return 1;
// }

// void bubble_sort(t_stack *a_stack, t_stack *b_stack)
// {
//     int times = 0;
//     int min;

//     while(a_stack->head != NULL)
//     {
//         min = find_min(a_stack);
//         if(min_location(min,a_stack) == 1)
//         {
//             while(*(int*)a_stack->head->data != min)
//             {
//                 ft_ra_rb(a_stack);
//                 times++;
//             }
//         }
//         else
//         {
//             while(*(int*)a_stack->head->data != min)
//             {
//                 ft_rra_rrb(a_stack);
//                 times++;
//             }
//         }
//         ft_pa_pb(b_stack,a_stack);
//         times++;
//     }
//     while(b_stack->head != NULL)
//     {
//         ft_pa_pb(a_stack,b_stack);
//         times++;
//     }
//     printf("TIMES:%d\n",times);
// }