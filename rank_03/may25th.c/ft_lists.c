/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lists.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 14:52:59 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/24 15:30:00 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

void	print_list(t_node *head)
{
	t_node		*current;
	static int	i = 0;

	if (!head)
		return ;
	current = head;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
t_node	*make_list(t_node *head, int value)
{
	t_node	*new;
	t_node	*current;

	new = malloc(sizeof(t_node));
	new->value = value;
	if (!head)
	{
		new->next = NULL;
		return (new);
	}
	current = head;
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
	return (head);
}

t_node	*reverse_list(t_node *head)
{
	t_node	*current;
	t_node	*second;
	t_node	*tmp;

	if (!head)
		return (NULL);
	if (!head->next)
		return (head);
	current = head;
	second = head->next;
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

int	cmp(void *a, int b)
{
	if ((int)a == b)
		return (0);
	return (1);
}

void	del_node(t_node **head, void *match, int (*cmp)(void *a, int b))
{
	t_node	*current;
	t_node	*tmp;

	if (!head || !*head)
		return ;
	current = *head;
	while (current && cmp(match, current->value) == 0)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*head = current;
	while (current->next)
	{
		if ((*cmp)(match, current->next->value) == 0)
		{
			tmp = current->next;
			current->next = current->next->next;
			free(tmp);
		}
	}
}

void	apply_f(t_node *head, void (*f)(void *))
{
	t_node	*current;

	current = head;
	while (current)
	{
		(*f)(&current->value);
		current = current->next;
	}
}

int	main ()
{
	t_node *head = NULL;
	int i = 8;

	head = make_list(head, 8);
	head = make_list(head, 8);
	head = make_list(head, 4);
	head = make_list(head, 3);
	head = make_list(head, 8);
	head = make_list(head, 7);
	print_list(head);
	del_node(&head, &i, &cmp);
	print_list(head);
	return (0);
}
