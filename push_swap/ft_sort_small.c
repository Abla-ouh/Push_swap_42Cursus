/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:36:57 by abouhaga          #+#    #+#             */
/*   Updated: 2022/07/05 23:28:12 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	if (find_big_num(*stack_a) == (*stack_a)->content)
		ft_rotate(stack_a, 'a');
	else if (find_big_num(*stack_a) == (*stack_a)->next->content)
		ft_reverse_rotate(stack_a, 'a');
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap(*stack_a, 'a');
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	smolnum;
	int	aftersmolnum;

	smolnum = find_smol_num(*stack_a);
	if (ft_lstsize(*stack_a) == 5)
		aftersmolnum = find_after_smolnum(*stack_a);
	else
		aftersmolnum = smolnum;
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content == smolnum
			|| (*stack_a)->content == aftersmolnum)
			ft_push(stack_a, stack_b, 'b');
		else
			ft_rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	if ((*stack_b)->next && (*stack_b)->content < (*stack_b)->next->content)
		ft_swap(*stack_b, 'b');
	while (*stack_b)
		ft_push(stack_b, stack_a, 'a');
}
