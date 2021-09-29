/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuya <takuya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:47:21 by takuya            #+#    #+#             */
/*   Updated: 2021/04/08 11:21:47 by takuya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_str_num(char *str)
{
    int i;

    i = 0;
    if(str[i] && str[i] == '-' && str[i + 1])
        i++;
    while(str[i])
    {
        if(!(ft_isdigit(str[i])))
            return (0);
        i++;
    }
    return (1);
}

int validate_sort(t_stack *a_stack, t_stack *b_stack)
{
    t_node *cur_node;

    if (b_stack->head != NULL)
        return (0);
    cur_node = a_stack->head;
    while (cur_node != NULL)
    {
        if (cur_node->next)
        {
            if (*(int*)(cur_node->data) > *(int*)(cur_node->next->data))
                return (0);            
        }
        cur_node = cur_node->next;
    }
    return (1);
}

void clear_words(char **words)
{
    int idx;
    char **tmp;

    idx = 0;
    tmp = words;
    while(words[idx] != NULL)
        free(words[idx++]);
    if(tmp != NULL)
        free(tmp);
}


int add_node(t_stack *stack,int data)
{
    int *p;
    t_node *new_node;

    if(!(p = (int*)malloc(sizeof(int))))
        return (0);
    *p = data;
    if (!(new_node = make_node((void*)p)))
    {
        free(p);
        return (0);
    }
    insert_end(stack, new_node);
    return (1);
}

int make_stack(int argc, char **argv, t_stack *a_stack)
{
    int i;
    int idx;
    char **words;

    i = 1;
    idx = 0;
    while (i < argc)
    {
        //TODO: "1 34 2 45" " 33 54 1" -> error
        //TODO: 文字列として max int '2784392849324329'と argv[i]比べる->大きかったらエラー
        idx = 0;
        words = ft_split(argv[i],' ');
        while(words[idx])
        {
            if (is_str_num(words[idx]))
            {
                add_node(a_stack,ft_atoi(words[idx]));
            }
            else
                return 0;
            idx++;
        }
        i++;
        clear_words(words);
    }
    return 1;
}

int check_duplicates(t_stack *stack)
{
    int head_num;
    t_node *head;
    t_node *next_head;

    head = stack->head;
    while (head != NULL)
    {
        next_head = head->next;
        head_num = *(int*)(head->data);
        while (next_head)
        {   
            if (head_num == *(int*)(next_head->data))
                return (0);
            next_head = next_head->next;
        }
        head = head->next;
    }
    return (1);
}

int check_operations(char *line,t_stack *a_stack, t_stack *b_stack)
{
    if(ft_strncmp("sa",line,2) == 0 && ft_strlen(line) == 2)
        ft_sa_sb(a_stack);
    else if(ft_strncmp("sb",line,2) == 0 && ft_strlen(line) == 2)
        ft_sa_sb(b_stack);
    else if(ft_strncmp("ss",line,2) == 0 && ft_strlen(line) == 2)
        ft_ss(a_stack,b_stack);
    else if(ft_strncmp("ra",line,2) == 0 && ft_strlen(line) == 2)
        ft_ra_rb(a_stack);
    else if(ft_strncmp("rb",line,2) == 0 && ft_strlen(line) == 2)
        ft_ra_rb(b_stack);
    else if(ft_strncmp("rr",line,2) == 0 && ft_strlen(line) == 2)
        ft_rr(a_stack,b_stack);
    else if(ft_strncmp("rra",line,3) == 0 && ft_strlen(line) == 3)
        ft_rra_rrb(a_stack);
    else if(ft_strncmp("rrb",line,3) == 0 && ft_strlen(line) == 3)
        ft_rra_rrb(b_stack);
    else if(ft_strncmp("rrr",line,3) == 0 && ft_strlen(line) == 3)
        ft_rrr(a_stack,b_stack);
    else if(ft_strncmp("pa",line,2) == 0 && ft_strlen(line) == 2)
        ft_pa_pb(a_stack,b_stack);
    else if(ft_strncmp("pb",line,2) == 0 && ft_strlen(line) == 2)
        ft_pa_pb(b_stack,a_stack);
    else
        return 0;
    return 1;
}

int read_operations(t_stack *operations)
{
    char *line;
    t_node *new_node;
	int res;
	
	while ((res = get_next_line(0,&line)) > 0)
	{
        if (!(new_node = make_node((void*)line)))
            return 0;
        insert_end(operations,new_node);
	}

    return (1);
}

int exec_operations(t_stack *operations, t_stack *a_stack, t_stack *b_stack)
{
    t_node *cur_node;

    cur_node = operations->head;
    if (cur_node == NULL)
        return (0);
    while(cur_node != NULL)
    {
        if(check_operations((char*)cur_node->data,a_stack,b_stack) == 0)
            return 0;
        printf("--------------a---------------\n");
        print_stack(a_stack);
        printf("--------------b---------------\n");
        print_stack(b_stack);
        printf("===============================\n");
        cur_node = cur_node->next;
    }
    return (1);
}

void end_program(char *err_msg, t_stack *operations, t_stack *a_stack, t_stack *b_stack)
{
    if(err_msg)
        write(2,err_msg,ft_strlen(err_msg));
    if(operations != NULL)
        clear_stack(operations);
    clear_stack(a_stack);
    clear_stack(b_stack);
    exit(1);
}

// int main(int argc, char **argv)
// {
//     t_stack a_stack;
//     t_stack b_stack;
//     t_stack operations;

//     a_stack.head = NULL;
//     a_stack.tail = NULL;
//     b_stack.head = NULL;
//     b_stack.tail = NULL;
//     operations.head = NULL;
//     operations.tail = NULL;

//     if(argc < 2 || !(make_stack(argc, argv, &a_stack)))
//         end_program("Error\n", &operations, &a_stack, &b_stack);
//     if(!(check_duplicates(&a_stack)))
//         end_program("Error\n", &operations, &a_stack, &b_stack);
//     if (read_operations(&operations) == 0)
//         end_program("Error\n", &operations, &a_stack, &b_stack);
//     if (exec_operations(&operations, &a_stack, &b_stack) == 0)
//         end_program("Error\n", &operations, &a_stack, &b_stack);
//     if (validate_sort(&a_stack, &b_stack) == 1)
//         write(1,"OK\n",3);
//     else
//         write(1,"KO\n",3);

//     end_program(NULL, &operations, &a_stack, &b_stack);    
    
//     return 0;
// }