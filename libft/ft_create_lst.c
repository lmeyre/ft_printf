/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:59:08 by lmeyre            #+#    #+#             */
/*   Updated: 2017/12/05 19:10:00 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_create_lst(int size)
{
	t_list	*start;
	t_list	*curr;
	t_list	*prev;

	start = ft_lst_new(0);
	curr = start;
	prev = NULL;
	while (size > 0)
	{
		curr->next = ft_lst_new(0);
		curr->prev = prev;
		prev = curr;
		curr = curr->next;
		--size;
	}
	return (start);
}
