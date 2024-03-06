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

t_node	*make_list(t_node *head, int value)
{
	t_node *new;
	t_node *tmp;

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

t_node	*ft_reverse(t_node *head)
{
	t_node	*current;
	t_node	*next_n;
	t_node	*tmp;

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
		next_n = tmp;
	}
	return (current);
}

int	main(void)
{
	t_node	*head = NULL;
	int i = 0;

	while (i <= 9)
		head = make_list(head, i++);
	print_list(head);
	head = ft_reverse(head);
	print_list(head);
	return (0);
}