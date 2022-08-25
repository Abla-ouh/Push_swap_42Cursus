/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:48:33 by abouhaga          #+#    #+#             */
/*   Updated: 2022/07/05 23:15:26 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_a_to_b(t_list **stack_a, t_list **stack_b,
					int *sorted_arr, t_utils *utils)
{
	while (*stack_a)
	{
		if (ft_lstsize(*stack_a) == 1)
			ft_push(stack_a, stack_b, 'b');
		while (ft_lstsize(*stack_b) < utils->end - utils->start)
		{
			if (!((*stack_a)->content < sorted_arr[utils->end]
					&& (*stack_a)->content >= sorted_arr[utils->start]))
				ft_rotate(stack_a, 'a');
			else
			{
				ft_push(stack_a, stack_b, 'b');
				if ((*stack_b)->content < sorted_arr[utils->mid])
					ft_rotate(stack_b, 'b');
			}
		}
		utils->start -= utils->chunk_size;
		if (utils->start < 0)
			utils->start = 0;
		utils->end += utils->chunk_size;
		if (utils->end >= utils->totalnums)
			utils->end = utils->totalnums - 1;
	}
}

void	check_case2(t_list **stack_a, t_utils *utils)
{
	if (utils->unorder_num > 0)
	{
		ft_reverse_rotate(stack_a, 'a');
		(utils->unorder_num)--;
		(utils->max_i)--;
	}
}

void	from_b_to_a(t_list **stack_a, t_list **stack_b,
			int *sorted_arr, t_utils *utils)
{
	utils->unorder_num = 0;
	utils->max_i = ft_lstsize(*stack_b) - 1;
	while (*stack_b)
	{
		if ((*stack_b) && find_big_num(*stack_b) == sorted_arr[utils->max_i])
			check_cases(stack_a, stack_b, sorted_arr, utils);
		else
			check_case2(stack_a, utils);
	}
	while (utils->unorder_num != 0)
	{
		ft_reverse_rotate(stack_a, 'a');
		utils->unorder_num--;
	}
}

void	check_cases(t_list **stack_a, t_list **stack_b,
						int *sorted_arr, t_utils *utils)
{
	if ((*stack_b)->content == sorted_arr[utils->max_i])
	{
		ft_push(stack_b, stack_a, 'a');
		(utils->max_i)--;
		if ((*stack_a)->next && (*stack_a)->content > (*stack_a)->next->content)
		{
			ft_swap(*stack_a, 'a');
			(utils->max_i)--;
		}
	}
	else if ((*stack_b)->content == sorted_arr[utils->max_i - 1])
		ft_push(stack_b, stack_a, 'a');
	else
		not_max_num(stack_a, stack_b, utils);
}

void	not_max_num(t_list **stack_a, t_list **stack_b, t_utils *utils)
{
	if (utils->unorder_num == 0
		|| (*stack_b)->content > ft_lstlast(*stack_a)->content)
	{
		ft_push(stack_b, stack_a, 'a');
		ft_rotate(stack_a, 'a');
		(utils->unorder_num)++;
	}
	else
	{
		if (find_big_num_index(*stack_b,
				find_big_num(*stack_b)) < ft_lstsize(*stack_b) / 2)
			ft_rotate(stack_b, 'b');
		else
			ft_reverse_rotate(stack_b, 'b');
	}
}
