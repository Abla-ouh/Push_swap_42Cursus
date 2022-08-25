/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:39:31 by abouhaga          #+#    #+#             */
/*   Updated: 2022/07/06 00:24:14 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stoi(const char *number)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	if (number[i] == '-' || number[i] == '+')
	{
		if (number[i++] == '-')
			sign *= -1;
		if (number[i] < '0' || number[i] > '9')
			ft_error();
	}
	num = 0;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			ft_error();
		num = num * 10 + (number[i++] - '0');
	}
	if (sign * num <= INT_MIN || sign * num >= INT_MAX)
		ft_error();
	return (sign * num);
}

void	ft_error( void )
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	small_stack_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_swap(*stack_a, 'a');
	}
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
}

void	big_stack_sort(t_list **stack_a, t_list **stack_b,
						int *sorted_arr, t_utils *utils)
{
	utils->totalnums = ft_lstsize(*stack_a);
	utils->mid = (utils->totalnums / 2);
	init_chunks(&utils->totalnums, &utils->n);
	utils->chunk_size = (utils->totalnums / utils->n);
	utils->start = utils->mid - utils->chunk_size;
	utils->end = utils->mid + utils->chunk_size;
	from_a_to_b(stack_a, stack_b, sorted_arr, utils);
	from_b_to_a(stack_a, stack_b, sorted_arr, utils);
}

int	main(int ac, char **av)
{
	t_list	*stack[2];
	int		*sorted_arr;
	t_utils	utils;

	if (ac < 2)
		return (0);
	is_valid(ac, av);
	stack[0] = ft_fill_stack(ac - 1, av + 1);
	stack[1] = NULL;
	if (ac < 3)
		return (0);
	sorted_arr = ft_sorted_array(stack[0]);
	if (ft_lstsize(stack[0]) <= 5 && is_sorted(stack[0]))
		small_stack_sort(&stack[0], &stack[1]);
	else if (is_sorted(stack[0]))
		big_stack_sort(&stack[0], &stack[1], sorted_arr, &utils);
	return (0);
}
