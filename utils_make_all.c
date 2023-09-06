/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_make_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:09:30 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/08/29 21:10:15 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	average(t_list **list)
{
	long long	sumator;
	t_list		*temp;

	sumator = 0;
	temp = *list;
	while (temp)
	{
		sumator += temp->nbr;
		temp = temp->next;
	}
	return (sumator / ft_lstsize(*list));
}

int	count_moves(t_list *list, int position)
{
	if (position <= ft_lstsize(list) / 2)
		return (position);
	return (ft_lstsize(list) - position);
}

int	custo(t_list *list_1, t_list *list_2)
{
	t_list	*temp;
	int		counter_b;
	int		custo;
	int		new_custo;
	int		index;

	temp = list_2;
	counter_b = 0;
	custo = 0;
	while (temp)
	{
		best_friend(list_1, temp);
		new_custo = count_moves(list_1, index_bff(list_1, temp)) + 1
			+ count_moves(list_2, counter_b);
		if (custo == 0 || new_custo < custo)
		{
			index = counter_b;
			custo = new_custo;
		}
		temp = temp->next;
		counter_b++;
	}
	return (index);
}
