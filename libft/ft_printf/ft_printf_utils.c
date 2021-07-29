/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:46:47 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:51:31 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	reset_flags(t_flag *flag)
{
	flag->flag_asterisks = 0;
	flag->flag_dot = 0;
	flag->flag_minus = 0;
	flag->flag_zero = 0;
	flag->precision = -1;
	flag->flag_plus = 0;
	flag->field_width = 0;
	flag->val_len = 0;
	flag->prtd_in_handl = 0;
}

static void	check_aster_field_width(t_flag *flag, va_list *arg)
{
	int	width;

	flag->flag_asterisks = 1;
	width = va_arg(*arg, int);
	if (width < 0)
	{
		width *= -1;
		flag->flag_minus = 1;
	}
	flag->field_width = (size_t)width;
}

static void	check_digit_field_width(t_flag *flag, const char *arr)
{
	while ((arr[flag->i] >= '0') && (arr[flag->i] <= '9'))
	{
		flag->field_width = flag->field_width * 10;
		flag->field_width += (arr[flag->i] - '0');
		(flag->i)++;
	}
	(flag->i)--;
}

static void	check_precision(t_flag *flag, va_list *arg, const char *arr)
{
	flag->precision = 0;
	flag->flag_dot = 1;
	if (arr[flag->i + 1] == '*')
	{
		flag->precision = va_arg(*arg, int);
		if (flag->precision < 0)
		{
			flag->precision = -1;
			flag->flag_dot = 0;
		}
		(flag->i)++;
	}
	else if ((arr[flag->i + 1] >= '0') && (arr[flag->i + 1] <= '9'))
	{
		while (((arr[(flag->i) + 1]) >= '0') && ((arr[(flag->i) + 1]) <= '9'))
		{
			flag->precision = flag->precision * 10;
			flag->precision += (arr[(flag->i) + 1]) - '0';
			(flag->i)++;
		}
	}
}

void	check_flags(t_flag *flag, const char *arr, va_list *arg)
{
	int	stop;

	stop = 0;
	reset_flags(flag);
	while (!stop && arr[flag->i])
	{
		if (arr[flag->i] == '-')
			flag->flag_minus = 1;
		else if ((arr[flag->i] >= '1') && (arr[flag->i] <= '9'))
			check_digit_field_width(flag, arr);
		else if (arr[flag->i] == '*')
			check_aster_field_width(flag, arg);
		else if (arr[flag->i] == '0')
			flag->flag_zero = 1;
		else if (arr[flag->i] == '.')
			check_precision(flag, arg, arr);
		else if (arr[flag->i] != '-' && arr[flag->i] != '*'
			&& arr[flag->i] != '.' && arr[flag->i] != '0')
			stop = 1;
		(flag->i)++;
	}
	(flag->i)--;
	if (flag->precision != -1)
		flag->flag_zero = 0;
}
