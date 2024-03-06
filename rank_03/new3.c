#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

void	print_list(t_node *head)
{
	t_node	*tmp;
	int		i = 0;

	if (!head)
		return ;
	tmp = head;
	while (tmp)
	{
		printf("Node %d: %d\n", i++, tmp->value);
		tmp = tmp->next;
	}
}

t_node	*make_list(t_node *head, int value)
{
	t_node	*new = NULL;
	t_node	*tmp = NULL;

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

t_node	*reverse(t_node *head)
{
	t_node *current;
	t_node *second;
	t_node *tmp;

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

t_node	*del_node(t_node *head, int match)
{
	t_node	*current;
	t_node	*tmp;

	if (!head)
		return (NULL);
	while (head && head->value == match)
	{
		tmp = head;
		head = head->next;
		free(tmp);
		if (!head)
			return (NULL);
	}
	current = head;
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

int	main()
{
	int 	i = 0;
	t_node *head = NULL;

	while (i < 8)
		head = make_list(head, i++);
	print_list(head);
	head = del_node(head, 5);
	// head = reverse(head);
	print_list(head);
	return (0);
}