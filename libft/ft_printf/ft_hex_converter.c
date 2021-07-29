/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:47:08 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:38:47 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	hex_helper_A(long int *i, long int *exp,
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

static void	hex_helper_B(char chr, char *hex, long int i, long long temp)
{
	if (chr == 'x')
		hex[i] = store_lowercase(temp % 16);
	else
		hex[i] = store_uppercase(temp % 16);
}

static void	hex_helper_C(t_flag *flag, long int	exp)
{
	(flag->Fstr)[exp + 1] = '\0';
	flag->val_len = ft_strlen(flag->Fstr);
	if (flag->flag_minus)
		hex_helper_2(flag);
	else
		hex_helper_3(flag);
}

static void	hex_helper(long long num, t_flag *flag, char chr)
{
	long int	i;
	long int	j;
	long int	exp;
	long long	temp;
	char		hex[100];

	hex_helper_A(&i, &exp, &num, &temp);
	flag->Fstr = hex;
	while (i <= exp)
	{
		temp = num;
		j = i;
		while (j <= exp)
		{
			if (j == exp)
				hex_helper_B(chr, hex, i, temp);
			else
				temp /= 16;
			j++;
		}
		i++;
	}
	hex_helper_C(flag, exp);
}

void	ft_hex_converter(va_list *arg, t_flag *flag, char chr)
{
	long long	value;

	value = (long long)va_arg(*arg, unsigned int);
	if ((!((flag->precision == 0) && (flag->flag_dot) && value == 0))
		|| ((flag->precision == 0) && (flag->flag_dot) && value > 0))
		hex_helper(value, flag, chr);
	if (flag->field_width > flag->prtd_in_handl)
		padding(flag->field_width - flag->prtd_in_handl, flag, ' ');
	(flag->i)++;
}
