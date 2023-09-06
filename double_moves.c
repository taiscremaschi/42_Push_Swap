/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:23:52 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/08/29 19:30:52 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_list **list_a, t_list **list_b)
{
	swap(list_a, 'd');
	swap(list_b, 'd');
	write(1, "ss\n", 3);
}

void	double_rotate(t_list **list_a, t_list **list_b)
{
	rotate(list_a, 'c');
	rotate(list_b, 'c');
	write(1, "rr\n", 3);
}

void	double_r_rotate(t_list **list_a, t_list **list_b)
{
	reverse_rotate(list_a, 'c');
	reverse_rotate(list_b, 'c');
	write(1, "rrr\n", 4);
}
