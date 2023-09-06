/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:22:11 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/08/29 21:12:02 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nbr;
	int				bff;
	int				cost;
	int				index_bff;
	struct s_list	*next;
}					t_list;

// //////// DOUBLE MOVES ////////////////

void				double_swap(t_list **list_a, t_list **list_b);
void				double_rotate(t_list **list_a, t_list **list_b);
void				double_r_rotate(t_list **list_a, t_list **list_b);

//////////// FT UTILS //////////////

void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(int n);
int					ft_lstsize(t_list *lst);

//////////// MAIN ////////////

void				error(t_list *list);
void				validation(char **av, t_list **list);

///////// MAKE 3 AND MAKE 5 ///////////

void				make_3(t_list **stack, int n1, int n2, int n3);
void				make_5(t_list **list_1, t_list **list_2);
int					small_nbr(t_list **list);
void				function_5(t_list **list_1, t_list **list_2,
						int small_index, int diference);

/////////// MAKE ALL ////////

int					best_friend(t_list *list_1, t_list *list_2);
int					index_bff(t_list *stack_a, t_list *stack_b);
void				make_all(t_list **list_1, t_list **list_2);
void				moves_all_lists(t_list **list, char reference, int posi);

/////////// UTILS MAKE ALL ////////

long long			average(t_list **list);
int					count_moves(t_list *list, int position);
int					custo(t_list *list_1, t_list *list_2);

/////////// MOVES ///////////

void				swap(t_list **list, char reference);
void				push_a(t_list **stack_a, t_list **stack_b);
void				push_b(t_list **stack_a, t_list **stack_b);
void				rotate(t_list **list, char reference);
void				reverse_rotate(t_list **list, char reference);

//////////// UTILS //////////

int					check_org(t_list **stack);
int					check_repeat(t_list **stack, int n);
long long			atoi_p(char *arg);
long long			true_int(char *str);
void				print_stack(t_list **stack);

#endif