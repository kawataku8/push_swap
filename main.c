/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:36:50 by tkawahar          #+#    #+#             */
/*   Updated: 2021/03/13 16:41:17 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list a_list;
    t_list b_list;

    insert_beginning(&a_list,1);
    insert_end(&a_list, 2);
    insert_end(&a_list, 3);
    insert_end(&a_list, 4);
    insert_end(&a_list, 5);

    insert_beginning(&b_list,10);
    insert_end(&b_list, 20);
    insert_end(&b_list, 30);
    insert_end(&b_list, 40);
    insert_end(&b_list, 50);

    ft_pa_pb(&a_list,&b_list);
    ft_pa_pb(&b_list,&a_list);
    ft_pa_pb(&b_list,&a_list);


    printf("------------a---------\n");
    print_list(&a_list);
    printf("------------b---------\n");
    print_list(&b_list);
    clear_list(&b_list);  
    clear_list(&a_list);    
    
    return (0);
}
