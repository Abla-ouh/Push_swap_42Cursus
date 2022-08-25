/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:20:30 by abouhaga          #+#    #+#             */
/*   Updated: 2022/07/05 07:31:45 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *stack, char s)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (s == 'a')
		ft_putendl_fd("sa", 1);
	if (s == 'b')
		ft_putendl_fd("sb", 1);
}

void	ft_push(t_list **stack_src, t_list **stack_dest, char s)
{
	t_list	*temp;

	if (!*stack_src)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = NULL;
	ft_lstadd_front(stack_dest, temp);
	if (s == 'a')
		ft_putendl_fd("pa", 1);
	if (s == 'b')
		ft_putendl_fd("pb", 1);
}

void	ft_rotate(t_list **stack, char s)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	if (s == 'a')
		ft_putendl_fd("ra", 1);
	if (s == 'b')
		ft_putendl_fd("rb", 1);
}

void	ft_reverse_rotate(t_list **stack, char s)
{	
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
	if (s == 'a')
		ft_putendl_fd("rra", 1);
	if (s == 'b')
		ft_putendl_fd("rrb", 1);
}
