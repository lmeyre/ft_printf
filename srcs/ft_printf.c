/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:00:49 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/21 23:12:07 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putchar_buff(t_env *env, char c)
{
	if (env->index_buff < BUFF_SIZE - 1)
		env->buff[env->index_buff++] = c;
	if (env->index_buff + 1 == BUFF_SIZE)
		reset_buf(env);
}

void		ft_putstr_buff(t_env *env, char *str)
{
	int h;

	h = 0;
	if (!str)
		return ;
	while (env->index_buff < BUFF_SIZE - 1 && str[h])
	{
		env->buff[env->index_buff++] = str[h];
		++h;
		if (env->index_buff + 1 == BUFF_SIZE)
			reset_buf(env);
	}
}

static	int	ft_filler(const char *format, t_env *env, va_list *ap)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while (format[env->index])
	{
		if (format[env->index] == '%')
		{
			if (launch_scan(env, ap) == -1)
				return (-1);
			reset_value(env);
		}
		else if (format[env->index] == '{')
			check_color(env, format);
		else
		{
			++(env->size);
			ft_putchar_buff(env, format[env->index++]);
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_env	*env;
	int		bool;
	int		return_val;

	bool = 0;
	if ((env = initialize_env()) == NULL)
		return (-1);
	va_start(ap, format);
	if (!(env->frmt = ft_strdup(format)))
		return (-1);
	bool = ft_filler(format, env, &ap);
	env->buff[env->index_buff] = '\0';
	if (env->index_buff > 0)
		ft_putstr(env->buff);
	va_end(ap);
	ft_strdel(&env->frmt);
	return_val = env->size;
	free(env);
	return (bool == -1 ? -1 : return_val);
}

int			launch_scan(t_env *env, va_list *ap)
{
	++env->index;
	attrib_start(env);
	field_width_start(env);
	precision_start(env);
	flag_start(env);
	if (convertion_start(env, ap) == -1)
		return (-1);
	return (1);
}
