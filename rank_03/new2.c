#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
	int				value;
	struct s_node	*next;
}	t_node;

t_node	*make_list(t_node *head, int value)
{
	t_node	*new;
	t_node	*tmp;

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

void	print_list(t_node *head)
{
	t_node	*tmp;
	int		i = 0;

	if (!head)
		return ;
	tmp = head;
	while (tmp)
	{
		printf("Node %d: %d\n", i, tmp->value);
		tmp = tmp->next;
	}
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

t_node	*reverse(t_node *head)
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

void	apply_f(t_node *head, void (*function)(void *value))
{
	t_node	*tmp = head;

	while (tmp)
	{
		function(&tmp->value);
		tmp = tmp->next;
	}
}

void	function(void *arg)
{
	*(int *) arg += 10;
}

int	main()
{
	t_node	*head = NULL;
	int i = 0;

	while (i < 5)
		head = make_list(head, i++);
	print_list(head);
	// head = reverse(head);
	// head = del_node(head, 2);
	apply_f(head, function);
	print_list(head);
	return (0);
}
