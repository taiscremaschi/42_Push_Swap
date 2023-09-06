/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:20:00 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/08/29 20:45:37 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_list *list)
{
	ft_lstclear(&list);
	exit(write(2, "Error\n", 7));
}

void	validation(char **av, t_list **list)
{
	long long	nbr;
	int			i;

	i = 0;
	while (av[++i])
	{
		nbr = atoi_p(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error(*list);
		else if (true_int(av[i]) == 1 && check_repeat(list, nbr) == 1)
			ft_lstadd_back(list, ft_lstnew(nbr));
		else
			error(*list);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (0);
	validation(av, &stack_a);
	if (!check_org(&stack_a))
	{
		if (ac == 3)
		{
			if (stack_a->nbr > stack_a->next->nbr)
				rotate(&stack_a, 'a');
		}
		else
			make_all(&stack_a, &stack_b);
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
