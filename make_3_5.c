/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:20:08 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/08/29 21:01:16 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_3(t_list **list, int n1, int n2, int n3)
{
	if (check_org(list))
		return ;
	if ((*list)->nbr > (*list)->next->nbr)
	{
		if (n1 > n3 && n2 < n3)
			rotate(list, 'a');
		else if (n3 > n1 && n3 > n2 && n2 < n1)
			swap(list, 'a');
		else
		{
			swap(list, 'a');
			reverse_rotate(list, 'a');
		}
	}
	else if (n3 < n2 && n3 < n1)
	{
		reverse_rotate(list, 'a');
	}
	else
	{
		swap(list, 'a');
		rotate(list, 'a');
	}
}

int	small_nbr(t_list **list)
{
	t_list	*temp;
	int		temp2;
	int		i;
	int		posi;

	temp = *list;
	temp2 = temp->nbr;
	i = 0;
	posi = 0;
	while (temp->next != NULL)
	{
		if (temp2 > temp->next->nbr)
		{
			temp2 = temp->next->nbr;
			posi = i + 1;
		}
		temp = temp->next;
		i++;
	}
	return (posi);
}

void	make_5(t_list **list_1, t_list **list_2)
{
	while (ft_lstsize(*list_1) > 3)
		function_5(list_1, list_2, small_nbr(list_1), 0);
	make_3(list_1, (*list_1)->nbr, (*list_1)->next->nbr,
		(*list_1)->next->next->nbr);
	push_a(list_1, list_2);
	push_a(list_1, list_2);
}

void	function_5(t_list **list_1, t_list **list_2, int small_index,
		int diference)
{
	if (small_index > 2)
	{
		diference = ft_lstsize(*list_1) - small_index;
		while (diference != 0)
		{
			reverse_rotate(list_1, 'a');
			diference--;
		}
		push_b(list_1, list_2);
	}
	else if (small_index < 3)
	{
		if (small_index == 2)
		{
			rotate(list_1, 'a');
			swap(list_1, 'a');
		}
		else if (small_index == 1)
			swap(list_1, 'a');
		push_b(list_1, list_2);
	}
}
