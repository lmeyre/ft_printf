/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:48:23 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 19:49:11 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_env		*initialize_env(void)
{
	t_env *env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->frmt = NULL;
	env->size = 0;
	env->index = 0;
	env->index_buff = 0;
	env->dieze = 0;
	env->zero = 0;
	env->neg = 0;
	env->space = 0;
	env->pos = 0;
	env->width = 0;
	env->hh_char = 0;
	env->h_short = 0;
	env->l_long = 0;
	env->ll_longlong = 0;
	env->j_intmax = 0;
	env->z_size = 0;
	env->precision = 0;
	env->precision_on = 0;
	return (env);
}

void		reset_value(t_env *env)
{
	env->dieze = 0;
	env->zero = 0;
	env->neg = 0;
	env->space = 0;
	env->pos = 0;
	env->width = 0;
	env->hh_char = 0;
	env->h_short = 0;
	env->l_long = 0;
	env->ll_longlong = 0;
	env->j_intmax = 0;
	env->z_size = 0;
	env->precision = 0;
	env->precision_on = 0;
}

void		init_conv_tab(void (*trigger[])(t_env*, va_list*, int))
{
	trigger[0] = &d_conv;
	trigger[1] = &s_conv;
	trigger[2] = &d_conv;
	trigger[3] = &base_conv;
	trigger[4] = &base_conv;
	trigger[5] = &base_conv;
	trigger[6] = &c_conv;
	trigger[7] = &as_conv;
	trigger[8] = &ac_conv;
	trigger[9] = &p_conv;
	trigger[10] = &base_conv;
	trigger[11] = &d_conv;
	trigger[12] = &base_conv;
	trigger[13] = &base_conv;
	trigger[14] = &percent_conv;
	trigger[15] = &b_conv;
}
