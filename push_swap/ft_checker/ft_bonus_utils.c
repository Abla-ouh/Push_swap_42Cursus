/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:13:37 by abouhaga          #+#    #+#             */
/*   Updated: 2022/07/05 21:13:37 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list *stack_a, t_list *stack_b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		ft_swap2(stack_a);
	else if (!ft_strcmp(str, "sb\n"))
		ft_swap2(stack_b);
	else if (!ft_strcmp(str, "ss\n"))
	{
		ft_swap2(stack_a);
		ft_swap2(stack_b);
	}
}

static void	push(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		ft_push2(stack_b, stack_a);
	else if (!ft_strcmp(str, "pb\n"))
		ft_push2(stack_a, stack_b);
}

static void	rotate(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "ra\n"))
		ft_rotate2(stack_a);
	else if (!ft_strcmp(str, "rb\n"))
		ft_rotate2(stack_b);
	else if (!ft_strcmp(str, "rr\n"))
	{
		ft_rotate2(stack_a);
		ft_rotate2(stack_b);
	}
}

static void	rev_rotate(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "rra\n"))
		ft_reverse_rotate2(stack_a);
	else if (!ft_strcmp(str, "rrb\n"))
		ft_reverse_rotate2(stack_b);
	else if (!ft_strcmp(str, "rrr\n"))
	{
		ft_reverse_rotate2(stack_a);
		ft_reverse_rotate2(stack_b);
	}
}

int	check_which_operation(t_list **stack_a, t_list **stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (!ft_strcmp(op, "pa\n") || !ft_strcmp(op, "pb\n"))
			push(stack_a, stack_b, op);
		else if (!ft_strcmp(op, "sa\n") || !ft_strcmp(op, "sb\n")
			|| !ft_strcmp(op, "ss\n"))
			swap(*stack_a, *stack_b, op);
		else if (!ft_strcmp(op, "ra\n") || !ft_strcmp(op, "rb\n")
			|| !ft_strcmp(op, "rr\n"))
			rotate(stack_a, stack_b, op);
		else if (!ft_strcmp(op, "rra\n") || !ft_strcmp(op, "rrb\n")
			|| !ft_strcmp(op, "rrr\n"))
			rev_rotate(stack_a, stack_b, op);
		else
			return (write (2, "Error\n", 6));
		free(op);
		op = get_next_line(0);
	}
	if (!is_sorted(*stack_a) && !(*stack_b))
		return (write (1, "OK\n", 3));
	else
		return (write (1, "KO\n", 3));
}
