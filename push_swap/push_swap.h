/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:09:57 by marvin            #+#    #+#             */
/*   Updated: 2022/07/06 00:46:29 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# define BUFFER_SIZE 1024

typedef struct s_utils
{
	int	mid;
	int	chunk_size;
	int	start;
	int	end;
	int	n;
	int	totalnums;
	int	unorder_num;
	int	max_i;
}t_utils;

/*---------------------- CHECK ------------------------------------*/
t_list	*ft_fill_stack(int ac, char **av);
void	ft_bubble_sort(int *arr, int arr_len);
int		is_sorted(t_list *stack_a);
void	is_valid(int ac, char **av);
int		*ft_sorted_array(t_list *stack);
int		ft_stoi(const char *str);
/*---------------------- SEARCH -------------------------------------*/
int		find_big_num(t_list *stack);
int		find_smol_num(t_list *stack_a);
int		find_after_smolnum(t_list *stack_a);
int		find_big_num_index(t_list *stack, int max);
/*---------------------- SORT BIG ------------------------------------*/
void	init_chunks(int *totalnums, int *n);
void	from_a_to_b(t_list **stack_a, t_list **stack_b,
			int *sorted_arr, t_utils *utils);
void	from_b_to_a(t_list **stack_a, t_list **stack_b,
			int *sorted_arr, t_utils *utils);
void	check_cases(t_list **stack_a, t_list **stack_b,
			int *sorted_arr, t_utils *utils);
void	not_max_num(t_list **stack_a, t_list **stack_b, t_utils *utils);
/*----------------------- SORT SMALL ---------------------------------*/
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);
/*----------------------- OPERATIONS ----------------------------------*/
void	ft_swap(t_list *stack, char s);
void	ft_push(t_list **stack_src, t_list **stack_dest, char s);
void	ft_rotate(t_list **stack, char s);
void	ft_reverse_rotate(t_list **stack, char s);
/*----------------------- OTHERS ---------------------------------------*/
void	ft_error( void );
void	small_stack_sort(t_list **stack_a, t_list **stack_b);
void	big_stack_sort(t_list **stack_a, t_list **stack_b,
			int *sorted_arr, t_utils *utils);
/*---------------------- BONUS -----------------------------------------*/

int		check_which_operation(t_list **stack_a, t_list **stack_b);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
/*----------------------- BONUS OPERATIONS -------------------------------*/
void	ft_swap2(t_list *stack);
void	ft_push2(t_list **stack_src, t_list **stack_dest);
void	ft_rotate2(t_list **stack);
void	ft_reverse_rotate2(t_list **stack);
#endif
