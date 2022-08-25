/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:30:04 by abouhaga          #+#    #+#             */
/*   Updated: 2022/07/05 07:33:04 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_big_num(t_list *stack)
{
	int	bignum;

	bignum = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (stack->content > bignum)
			bignum = stack->content;
		stack = stack->next;
	}
	return (bignum);
}

int	find_smol_num(t_list *stack_a)
{
	int	smolnum;

	smolnum = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->content < smolnum)
			smolnum = stack_a->content;
		stack_a = stack_a->next;
	}
	return (smolnum);
}

int	find_after_smolnum(t_list *stack_a)
{
	int	smolnum;
	int	aftersmolnum;

	smolnum = find_smol_num(stack_a);
	if (stack_a->content == smolnum)
		stack_a = stack_a->next;
	aftersmolnum = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->content < aftersmolnum && stack_a->content != smolnum)
			aftersmolnum = stack_a->content;
		stack_a = stack_a->next;
	}
	return (aftersmolnum);
}

int	find_big_num_index(t_list *stack, int max)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == max)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
