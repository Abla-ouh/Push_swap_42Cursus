/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:24:23 by abouhaga          #+#    #+#             */
/*   Updated: 2022/07/05 07:27:21 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_fill_stack(int ac, char **av)
{
	int		i;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	while (i < ac)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_stoi(av[i])));
		i++;
	}
	return (stack_a);
}

void	ft_bubble_sort(int *arr, int arr_len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{	
			if ((j + 1 < arr_len) && arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	is_sorted(t_list *stack_a)
{
	while (stack_a)
	{
		if (stack_a->next && stack_a->content > stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	is_valid(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_stoi(av[i]) == ft_stoi(av[j]))
				ft_error();
			j++;
		}
		i++;
	}
}

int	*ft_sorted_array(t_list *stack)
{
	size_t	i;
	int		*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (ft_lstsize(stack)));
	while (stack)
	{
		arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
	ft_bubble_sort(arr, i);
	return (arr);
}
