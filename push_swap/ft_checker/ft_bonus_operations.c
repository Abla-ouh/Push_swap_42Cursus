/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_bns.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:36:07 by abouhaga          #+#    #+#             */
/*   Updated: 2022/07/05 20:36:07 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap2(t_list *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	ft_push2(t_list **stack_src, t_list **stack_dest)
{
	t_list	*temp;

	if (!*stack_src)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = NULL;
	ft_lstadd_front(stack_dest, temp);
}

void	ft_rotate2(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}

void	ft_reverse_rotate2(t_list **stack)
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
}
