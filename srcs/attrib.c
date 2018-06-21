/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:59:41 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 18:59:53 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		handle_space(int *count, int neg, t_env *env)
{
	if (neg == 0 && env->space == 1)
	{
		ft_putchar_buff(env, ' ');
		++(*count);
	}
}

void		handle_pos(t_env *env, int number)
{
	if (env->pos == 1 && number >= 0)
		ft_putchar_buff(env, '+');
}
