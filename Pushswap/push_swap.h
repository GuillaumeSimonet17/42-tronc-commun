/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:26:13 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/08 16:16:27 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
// # include <stdio.h>
# include <stdlib.h>

typedef struct s_list_a
{
	long int			num;
	int					index;
	struct s_list_a		*next;
}	t_list_a;

typedef struct s_list_b
{
	long int			num;
	int					index;
	struct s_list_b		*next;
}	t_list_b;

t_list_a	new_list(void);

// parsing
long long	ft_atol(const char *str);
int			ft_parsing(char **argv, t_list_a **lsta, t_list_b **lstb);
int			ft_attribute_num_to_lst(t_list_a **lsta, t_list_b **lstb, char *s);

// split
char		**ft_split(char const *s, char c);

// check
int			ft_check_all(t_list_a **lsta, t_list_b **lstb);
int			is_a_sorted(t_list_a **lsta);
int			ft_comp(int a, int b);
int			ft_check_doublon(t_list_a **lsta);
int			ft_str_is_conform(char *s);

// create_list
t_list_a	*ft_create_elem_a(int num);
void		ft_lstadd_back_a(t_list_a **lsta, int num);
t_list_b	*ft_create_elem_b(int num);
void		ft_lstadd_back_b(t_list_b **lstb, int num);

// free
int			ft_free_all(t_list_a **lsta, t_list_b **lstb);
void		ft_clear_b(t_list_b **lstb);
void		ft_clear_a(t_list_a **lsta);
void		ft_lstdelone_b(t_list_b *lstb);
void		ft_lstdelone_a(t_list_a *lsta);

// utils
void		*ft_calloc(size_t elementCount, size_t elementSize);
int			ft_lstsize(t_list_a *lsta);
int			ft_lstsize_b(t_list_b *lstb);
int			ft_strlen(char *c);

// get_min_max
int			get_max(t_list_a **lsta);
int			get_min_num(t_list_a **lsta);

//  swap
t_list_a	*sa(t_list_a **lsta);
t_list_b	*sb(t_list_b **lstb);
t_list_a	*ra(t_list_a **lsta);

// swap suite
t_list_a	*pa(t_list_a **lsta, t_list_b **lstb);
t_list_b	*pb(t_list_a **lsta, t_list_b **lstb);

// pre sort
t_list_b	*ft_pre_sort(t_list_a **lsta, t_list_b **lstb);
t_list_b	*ft_assign_index(t_list_b **lstb);
t_list_a	*ft_lsta_indexee(t_list_a **lsta, t_list_b **lstb);
void		ft_sort_a(t_list_a **lsta, t_list_b **lstb);
int			ft_long_num_max(int max);

// sort
void		ft_sort_algo(t_list_a **lsta, t_list_b **lstb, int div);
int			ft_which_digit(t_list_a **lsta, t_list_b **lstb, long n, int div);
long		ft_convert_base_binary(long num);
void		ft_all_in_lsta(t_list_a **lsta, t_list_b **lstb);

// sort low
int			ft_sort3(t_list_a **lsta, t_list_b **lstb, int true);
int			ft_sort5(t_list_a **lsta, t_list_b **lstb);
int			ft_sort5bis(t_list_a **lsta, t_list_b **lstb, int i, int min);

#endif
