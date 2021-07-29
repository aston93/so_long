/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:47:42 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:52:02 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	u_zero_and_width_handler(t_flag *flag)
{
	if ((flag->field_width > flag->val_len)
		&& (flag->precision > flag->val_len))
	{
		padding(flag->field_width - flag->precision, flag, ' ');
		padding(flag->precision - flag->val_len, flag, '0');
	}
	else if (flag->flag_zero)
		padding(flag->field_width - flag->val_len, flag, '0');
	else if (flag->precision > flag->val_len)
		padding(flag->precision - flag->val_len, flag, '0');
	else
		padding(flag->field_width - flag->val_len, flag, ' ');
}

static void	u_handler_part_one(t_flag *F)
{
	if (F->field_width > (F->precision + F->val_len))
	{
		padding(F->precision - F->val_len, F, '0');
		ft_putstr_printf(F->Fstr, F);
		if (F->field_width > F->prtd_in_handl)
			padding(F->field_width - F->prtd_in_handl, F, ' ');
	}
	else if (F->precision > F->val_len)
	{
		padding(F->precision - F->val_len, F, '0');
		ft_putstr_printf(F->Fstr, F);
	}
	else
	{
		ft_putstr_printf(F->Fstr, F);
		if (F->field_width > F->val_len)
			u_zero_and_width_handler(F);
	}
}

void	ft_u_handler(va_list *arg, t_flag *F)
{
	unsigned int	value;

	value = (unsigned int)va_arg(*arg, unsigned int);
	F->Fstr = ft_itoa_unsigned(value);
	F->val_len = (int)ft_strlen(F->Fstr);
	if ((F->flag_minus) && (!((F->precision == 0) && (value == 0))))
		u_handler_part_one(F);
	else if (!((F->precision == 0) && (value == 0)))
	{
		if ((F->field_width > F->val_len) || (F->precision > F->val_len))
			u_zero_and_width_handler(F);
		ft_putstr_printf(F->Fstr, F);
	}
	else if ((F->precision == 0) && (value == 0) && (F->field_width > 0))
		padding(F->field_width, F, ' ');
	(F->i)++;
	free(F->Fstr);
}
