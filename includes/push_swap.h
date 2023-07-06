/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbabken <anbabken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:23:03 by anbabken          #+#    #+#             */
/*   Updated: 2023/07/06 17:03:43 by anbabken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
// # include "get_next_line.h"

typedef struct s_list
{
	int				n;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		len;
}	t_stack;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		push(t_list **stack_to, t_list **stack_from);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		reverse_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

int		fill_list(t_list **lst, int content);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	put_msg(char *str, int fd);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
//validation.c
char	**join_args(int ac, char **av);
char	*limits_check(char *str);
int		arg_check(char **group);
int		atoi_check(char *str);
//utils.c
char	*join_str(char *s1, char *s2);
void	free_dp(char ***group, int a);
t_stack	*make_stack(char ***group);

int		validation(char **res);
int		fill_stack(t_stack *stack, char **res);
void	push_swap(t_stack *stack);
void	valid_check(char **argv);
void	ft_putendl_fd(char *s, int fd);

#endif
