/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test11.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 10:54:01 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/10 11:54:31 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
	int value;
	struct s_node *next;
}	t_node;


t_node	*make_list(t_node *head, int value)
{
	t_node	*tmp;
	t_node	*current;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	if (!head)
	{
		tmp->next = NULL;
		return (tmp);
	}
	current = head;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	return (head);
}

void	print_list(t_node *head)
{
	t_node	*tmp;
	int	i = 0;

	tmp = head;
	while (tmp)
	{
		printf("Node %d: %d\n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}
}

void	function(void *value)
{
	*(int *) value += 1;
}


void	apply_f(t_node **head, void (*function)(void *value))
{
	t_node	*tmp;

	tmp = *head;
	while (tmp)
	{
		(*function)(&tmp->value);
		tmp = tmp->next;
	}
}

int	main ()
{
	t_node 	*head = NULL;
	int i = 0;

	while (i < 9)
		head = make_list(head, i++);
	print_list(head);
	apply_f(&head, function);
	print_list(head);
}
