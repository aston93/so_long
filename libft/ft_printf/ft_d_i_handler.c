/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:46:01 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:38:37 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	d_i_neg_with_zero(t_flag *flag, char *i_arr, size_t value_len)
{
	write(1, &i_arr[0], 1);
	(flag->result)++;
	padding(flag->field_width - value_len, flag, '0');
	ft_putstr_printf(i_arr + 1, flag);
}

static void	d_i_left_padded(va_list *arg, t_flag *F)
{
	int		value;
	int		zero_padding;

	zero_padding = 0;
	value = va_arg(*arg, int);
	F->Fstr = ft_printf_itoa(value, F);
	if (((F->precision == -1) || (F->precision == 0)) && (value == 0))
	{
		if ((value == 0) && (!((F->flag_dot) && (F->precision == 0))))
			ft_putstr_printf(F->Fstr, F);
		padding(F->field_width - F->prtd_in_handl, F, ' ');
		return ;
	}
	F->val_len = ft_strlen(F->Fstr);
	if (F->precision > F->val_len)
		zero_padding = F->precision - F->val_len;
	padding(zero_padding, F, '0');
	ft_putstr_printf(F->Fstr, F);
	if (F->field_width > (zero_padding + F->val_len))
		padding(F->field_width - F->val_len - zero_padding, F, ' ');
}

static void	middle_engine(t_flag *flag)
{
	if (flag->field_width > (flag->precision + 1))
		padding(flag->field_width - flag->precision - 1, flag, ' ');
	write(1, flag->Fstr, 1);
	(flag->result)++;
	(flag->prtd_in_handl)++;
	padding(flag->precision - flag->val_len + 1, flag, '0');
	ft_putstr_printf(flag->Fstr + 1, flag);
}

static void	d_i_right_padded(t_flag *flag, int zero_padding)
{
	if ((flag->precision == 0) && (flag->val == 0) && (flag->flag_dot))
	{
		padding(flag->field_width, flag, ' ');
		return ;
	}
	if (((flag->Fstr)[0] == '-') && (flag->precision > (flag->val_len - 1)))
	{
		middle_engine(flag);
		return ;
	}
	else if (flag->precision > flag->val_len)
		zero_padding = flag->precision - flag->val_len;
	else if ((flag->field_width > flag->val_len) && (flag->flag_zero == 1))
		zero_padding = flag->field_width - flag->val_len;
	if (flag->field_width > (flag->val_len + zero_padding))
		padding(flag->field_width - flag->val_len - zero_padding, flag, ' ');
	if ((flag->val < 0) && (flag->flag_zero == 1))
		d_i_neg_with_zero(flag, flag->Fstr, flag->val_len);
	else
	{
		padding(zero_padding, flag, '0');
		ft_putstr_printf(flag->Fstr, flag);
	}
}

void	ft_d_i_handler(va_list *arg, t_flag *flag)
{
	int		zero_padding;

	if (flag->flag_minus == 1)
		d_i_left_padded(arg, flag);
	else
	{
		zero_padding = 0;
		flag->val = va_arg(*arg, int);
		flag->Fstr = ft_printf_itoa(flag->val, flag);
		flag->val_len = ft_strlen(flag->Fstr);
		d_i_right_padded(flag, zero_padding);
	}
	free(flag->Fstr);
	(flag->i)++;
}
