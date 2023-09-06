/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:19:37 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/08/29 19:59:41 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_org(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_repeat(t_list **stack, int n)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->nbr != n)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

long long	atoi_p(char *arg)
{
	int			i;
	int			s;
	long long	n;

	i = 0;
	s = 1;
	n = 0;
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i] == '-')
			s *= -1;
		i++;
	}
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		n *= 10;
		n += arg[i++] - '0';
	}
	return (n * s);
}

long long	true_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	print_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		printf(" - %d", tmp->nbr);
		tmp = tmp->next;
	}
	printf("\n");
}
