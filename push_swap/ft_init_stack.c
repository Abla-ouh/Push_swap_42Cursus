/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:39:08 by abouhaga          #+#    #+#             */
/*   Updated: 2022/07/05 07:39:29 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_chunks(int *totalnums, int *n)
{
	if (*totalnums <= 30)
		*n = 5;
	else if (*totalnums <= 150)
		*n = 8;
	else
		*n = 18;
}
