/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:47:42 by abouhaga          #+#    #+#             */
/*   Updated: 2022/07/05 19:47:42 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (ac <= 2)
		return (0);
	is_valid(ac, av);
	stack_a = ft_fill_stack(ac - 1, av + 1);
	check_which_operation(&stack_a, &stack_b);
	return (0);
}
