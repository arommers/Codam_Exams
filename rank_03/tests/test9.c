/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test9.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adri <adri@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 11:25:06 by adri          #+#    #+#                 */
/*   Updated: 2023/05/09 12:40:58 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    int             value;
    struct s_node   *next;    
}   t_node;

void    print_list(t_node *head)
{
    t_node  *tmp;
    int i = 0;
    
    if(!head)
        return ;
    tmp = head;
    while (tmp)
    {
        printf("Node %d: %d\n", i, tmp->value);
        tmp = tmp->next;
        i++;
    }
}


t_node  *make_list(t_node *head, int value)
{
    t_node  *tmp = NULL;
    t_node  *new = malloc(sizeof(t_node));
    if (!new)
        return (NULL);
    new->value = value;
    if (!head)
    {
        new->next = NULL;
        return (new);
    }
    else
    {
        tmp = head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->next = NULL;
    }
    return (head);
}

t_node  *reverse(t_node *head)
{
    t_node *current = NULL;
    t_node *next_n = NULL;
    t_node *tmp = NULL;
    
    if (!head)
        return (NULL);
    if (!head->next)
        return (head);
    current = head;
    next_n = head->next;
    current->next = NULL;
    while (next_n)
    {
        tmp = next_n->next;
        next_n->next = current;
        current = next_n;
        next_n  = tmp;
    }
    return (current);
}

t_node  *delete_matches(t_node *head, int match)
{
   t_node   *current;
   t_node   *tmp;
   t_node   *new_head;
   
   if (!head)
        return (NULL);
    current = head;
    while (current->value == match)
    {
        tmp = current;
        current = current->next;
        free(tmp);
        if (current == NULL)
            return (NULL);
    }
    head = current;
    while (current->next)
    {
        if (current->next->value == match)
        {
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
        else
            current = current->next;
    }
    return (head);
    
}

int main()
{
    t_node  *head = NULL;
    int i = 11;
    
    while (i < 20)
        head = make_list(head, i++);
    print_list(head);
    head = delete_matches(head, 13);
    print_list(head);
    return (0);
}