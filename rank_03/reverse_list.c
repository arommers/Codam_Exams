/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 12:35:38 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/08 15:25:25 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

void	print_list(t_node *head)
{
	t_node	*current;
	int i = 0;

	current = head;
	while (current)
	{
		printf("Node %d: %d\n", i, current->value);
		current = current->next;
		i++;
	}
}

t_node	*insert_at_head(t_node *head, int value)
{
	t_node	*new = malloc(sizeof(t_node));

	new->value = value;
	if (!head)
	{
		new->next = NULL;
		return (new);
	}
	else
		new->next = head;
	return (new);
}

t_node	*insert_at_tail(t_node *head, int value)
{
	t_node	*new = malloc(sizeof(t_node));
	t_node	*tmp;

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

t_node	*ft_reverse(t_node *head)
{
	t_node *current = head;
	t_node *next_node = head->next;
	t_node *tmp;

	if (!head)
		return (NULL);
	if (!head->next)
		return (head);
	current->next = NULL;
	while (next_node)
	{
		tmp = next_node->next;
		next_node->next = current;
		current = next_node;
		next_node = tmp;
	}
	return (current);
}

int	main(void)
{
	t_node	*head = NULL;
	int i = 0;

	while (i <= 9)
	{
		head = insert_at_tail(head, i);
		i++;
	}
	print_list(head);
	head = ft_reverse(head);
	print_list(head);
	return (0);
}
