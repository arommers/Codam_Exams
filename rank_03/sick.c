#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    int             value;
    struct s_node   *next;
}   t_node;

void    print_list(t_node *head)
{
    t_node  *tmp;
    int     i = 0;

    tmp = head;
    while (tmp)
    {
        printf("Node %d: %d\n", i++, tmp->value);
        tmp = tmp->next;
    }
}

t_node  *make_list(t_node *head, int value)
{
    t_node  *new;
    t_node  *tmp;

    new = malloc(sizeof(t_node));
    new->value = value;
    if (!head)
    {
        new->next = NULL;
        return (new);
    }
    tmp = head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    new->next = NULL;
    return (head);
}

t_node  *reverse_list(t_node *head)
{
    t_node  *current;
    t_node  *second;
    t_node  *tmp;

    current = head;
    second = head->next;
    if (!head)
        return (NULL);
    if (!head->next)
        return (head);
    current->next = NULL;
    while (second)
    {
        tmp = second->next;
        second->next = current;
        current = second;
        second = tmp;
    }
    return (current);
}

int main()
{
    t_node *head = NULL;
    int i = 0;

    while (i < 9)
        head = make_list(head, i++);
    print_list(head);
    head = reverse_list(head);
    print_list(head);
    return (0);
}