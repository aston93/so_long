/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:45:49 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:38:29 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	c_flag_handler(va_list *arg, t_flag *flag)
{
	unsigned char	chr_temp;

	if (flag->field_width == 0)
		flag->field_width = (size_t)va_arg(*arg, size_t);
	chr_temp = (unsigned int)va_arg(*arg, int);
	if (flag->flag_minus == 1)
	{
		write(1, &chr_temp, 1);
		(flag->result)++;
		if (flag->field_width > 1)
			padding(flag->field_width - 1, flag, ' ');
	}
	else
	{
		if (flag->field_width > 1)
			padding(flag->field_width - 1, flag, ' ');
		write(1, &chr_temp, 1);
		(flag->result)++;
	}
}

void	ft_c_handler(va_list *arg, t_flag *flag)
{
	unsigned char	temp;

	if ((flag->field_width > 0) || (flag->field_width != 0))
		c_flag_handler(arg, flag);
	else
	{
		if (flag->field_width > 1)
			padding(flag->field_width - 1, flag, ' ');
		temp = (unsigned int)va_arg(*arg, int);
		write(1, &temp, 1);
		(flag->result)++;
	}
	(flag->i)++;
}
