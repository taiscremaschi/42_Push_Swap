/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:59:32 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/08/29 20:00:24 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list, char reference)
{
	t_list	*temp;

	temp = *list;
	if (*list == NULL || (*list)->next == NULL)
		return ;
	*list = (*list)->next;
	temp->next = (*list)->next;
	(*list)->next = temp;
	if (reference == 'a')
		write(1, "sa\n", 3);
	else if (reference == 'b')
		write(1, "sb\n", 3);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = temp;
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = temp;
	write(1, "pb\n", 3);
}

void	reverse_rotate(t_list **list, char reference)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *list;
	while (temp->next != NULL)
	{
		temp2 = temp;
		temp = temp->next;
	}
	temp2->next = NULL;
	temp->next = *list;
	*list = temp;
	if (reference == 'a')
		write(1, "rra\n", 4);
	else if (reference == 'b')
		write(1, "rrb\n", 4);
}

void	rotate(t_list **list, char reference)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *list;
	temp2 = *list;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	*list = temp->next;
	temp->next = NULL;
	temp2->next = temp;
	if (reference == 'a')
		write(1, "ra\n", 3);
	else if (reference == 'b')
		write(1, "rb\n", 3);
}
