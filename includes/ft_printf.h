/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 01:55:08 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/25 01:56:14 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# define BUFF_SIZE 4096

typedef	struct		s_env
{
	char			buff[BUFF_SIZE];
	int				index;
	int				index_buff;
	int				size;
	char			*frmt;
	int				dieze;
	int				zero;
	int				neg;
	int				space;
	int				pos;
	int				width;
	int				precision;
	int				precision_on;
	int				hh_char;
	int				h_short;
	int				l_long;
	int				ll_longlong;
	int				j_intmax;
	int				z_size;
}					t_env;

int					ft_printf(const char *format, ...);
void				reset_buf(t_env *env);
void				ft_putchar_buff(t_env *env, char c);
void				ft_putstr_buff(t_env *env, char *str);
t_env				*initialize_env(void);
void				reset_value(t_env *env);
void				init_conv_tab(void (*trigger[])(t_env*, va_list*, int));
int					launch_scan(t_env *env, va_list *ap);
void				attrib_start(t_env *env);
void				field_width_start(t_env *env);
void				precision_start(t_env *env);
void				flag_start(t_env *env);
int					convertion_start(t_env *env, va_list *ap);
void				handle_space(int *count, int neg, t_env *env);
void				handle_pos(t_env *env, int number);
void				handle_precision_int(t_env *env, int size);
void				handle_precision_str(t_env *env, char *str);
void				handle_precision_wstr(t_env *env, wchar_t *wstr);
void				handle_width_other(t_env *env, int size);
void				handle_width_unicod(t_env *env, int size);
void				as_conv(t_env *env, va_list *ap, int bigger);
void				ac_conv(t_env *env, va_list *ap, int c);
void				percent_conv(t_env *env, va_list *ap, int usls);
void				s_conv(t_env *env, va_list *ap, int null);
void				d_conv(t_env *env, va_list *ap, int count);
void				b_conv(t_env *env, va_list *ap, int count);
void				c_conv(t_env *env, va_list *ap, int c);
void				base_conv(t_env *env, va_list *ap, int big);
void				p_conv(t_env *env, va_list *ap, int bigger);
void				check_color(t_env *env, const char *format);

#endif
