/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:47:17 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:39:18 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	p_handle_null(t_flag *flag)
{
	int		j;
	char	arr[4];

	j = 0;
	arr[0] = '0';
	arr[1] = 'x';
	arr[2] = '0';
	arr[3] = '\0';
	while (arr[j])
	{
		write(1, &arr[j], 1);
		j++;
		(flag->result)++;
		(flag->prtd_in_handl)++;
	}
}

static void	p_helper_1(long int *i, long int *exp,
	long long *num, long long *temp)
{
	*i = 0;
	*exp = 0;
	*temp = *num;
	while ((*temp) >= 16)
	{
		(*exp)++;
		(*temp) /= 16;
	}
}

static void	hex_helper_p(long long num, t_flag *flag)
{
	long int	i;
	long int	j;
	long int	exp;
	long long	temp;
	char		hex[100];

	p_helper_1(&i, &exp, &num, &temp);
	while (i <= exp)
	{
		temp = num;
		j = i;
		while (j <= exp)
		{
			if (j == exp)
				hex[i] = store_lowercase(temp % 16);
			else
				temp /= 16;
			j++;
		}
		i++;
	}
	hex[exp + 1] = '\0';
	write(1, "0x", 2);
	(flag->result) += 2;
	ft_putstr_printf(hex, flag);
}

void	ft_p_handler(va_list *arg, t_flag *flag)
{
	long long	value;

	value = (long long)va_arg(*arg, void *);
	if ((value == 0) && (flag->field_width > 3) && (flag->flag_minus != 1))
	{
		padding(flag->field_width - 3, flag, ' ');
		p_handle_null(flag);
	}
	else if (value == 0)
		p_handle_null(flag);
	else
		hex_helper_p(value, flag);
	if (flag->field_width > flag->prtd_in_handl)
		padding(flag->field_width - flag->prtd_in_handl, flag, ' ');
	(flag->i)++;
}
