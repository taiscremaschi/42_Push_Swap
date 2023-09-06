/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:20:16 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/08/29 21:10:15 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_friend(t_list *list_1, t_list *list_2)
{
	int	temp;
	int	first;
	int	i;

	first = 1;
	i = 0;
	while (list_1)
	{
		if (list_1->nbr > list_2->nbr)
		{
			if (first)
				temp = list_1->nbr;
			else if (list_1->nbr < temp)
				temp = list_1->nbr;
			first = 0;
		}
		i++;
		list_1 = list_1->next;
	}
	list_2->bff = temp;
	return (temp);
}

int	index_bff(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	int		posi;
	int		bff;

	temp = stack_a;
	posi = 0;
	bff = best_friend(stack_a, stack_b);
	while (temp != NULL)
	{
		if (temp->nbr == bff)
		{
			break ;
		}
		temp = temp->next;
		posi++;
	}
	stack_b->index_bff = posi;
	return (posi);
}

void	make_all(t_list **list_1, t_list **list_2)
{
	while (ft_lstsize((*list_1)) > 5)
	{
		if ((*list_1)->nbr < average(list_1))
		{
			push_b(list_1, list_2);
		}
		else
		{
			rotate(list_1, 'a');
		}
	}
	make_5(list_1, list_2);
	while (ft_lstsize(*list_2) != 0)
	{
		moves_all_lists(list_2, 'b', custo(*list_1, *list_2));
		moves_all_lists(list_1, 'a', (*list_2)->index_bff);
		push_a(list_1, list_2);
	}
	moves_all_lists(list_1, 'a', small_nbr(list_1));
}

void	moves_all_lists(t_list **list, char reference, int posi)
{
	int	i;

	i = posi;
	while (i > 0 && i < ft_lstsize(*list))
	{
		if (posi < ft_lstsize(*list) / 2)
		{
			rotate(list, reference);
			i--;
		}
		else
		{
			reverse_rotate(list, reference);
			i++;
		}
	}
}
