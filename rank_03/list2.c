/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 11:58:18 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/11 12:04:09 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_node{
	int value;
	struct s_node *next;
}	t_node;

void	apply_f(t_node **head, void (*function(void *value)))
{
	t_node	*tmp;
	t_node 	*current;

	tmp = *head;
	current = *head;
	while (current)
	{
		if((*function)(tmp->value) == 1)
		{
			current = (*head)->next;
			
		}
		tmp = tmp->
	}
}