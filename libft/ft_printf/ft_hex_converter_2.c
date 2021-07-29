/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_converter_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:47:08 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:38:54 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	hex_helper_2(t_flag *flag)
{
	if (flag->precision > flag->val_len)
	{
		padding(flag->precision - flag->val_len, flag, '0');
		ft_putstr_printf(flag->Fstr, flag);
	}
	else
	{
		ft_putstr_printf(flag->Fstr, flag);
		if (flag->field_width > flag->val_len)
			padding(flag->field_width - flag->val_len, flag, ' ');
	}
}

void	hex_helper_3(t_flag *flag)
{
	if ((flag->precision > flag->field_width)
		&& (flag->precision > flag->val_len))
		padding(flag->precision - flag->val_len, flag, '0');
	else if ((flag->field_width > flag->val_len) && (flag->flag_zero == 1))
		padding(flag->field_width - flag->val_len, flag, '0');
	else if ((flag->field_width > flag->val_len) && (flag->flag_zero == 0))
	{
		if ((flag->precision > flag->val_len)
			&& (flag->field_width > flag->precision))
		{
			padding(flag->field_width - flag->precision, flag, ' ');
			padding(flag->precision - flag->val_len, flag, '0');
		}
		else
			padding(flag->field_width - flag->val_len, flag, ' ');
	}
	ft_putstr_printf(flag->Fstr, flag);
}
