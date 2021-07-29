/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:47:34 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:51:48 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	s_print_null(t_flag *flag)
{
	int		j;
	char	str[7];

	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	j = 0;
	if ((flag->flag_dot != 1) || (flag->precision >= 6))
	{
		while (str[j] != '\0')
		{
			write(1, &str[j], 1);
			(flag->result)++;
			(flag->prtd_in_handl)++;
			j++;
		}
	}
}

static void	s_add_padding(t_flag *F)
{
	if (F->precision > F->val_len)
	{
		if ((F->field_width > F->val_len) || (F->field_width > F->precision))
			padding(F->field_width - F->val_len, F, ' ');
		else if (F->field_width > F->precision)
			padding(F->field_width - F->precision, F, ' ');
	}
	else if ((F->precision < F->val_len)
		&& (F->field_width > F->precision) && F->flag_dot)
		padding(F->field_width - F->precision, F, ' ');
	else
	{
		if (F->field_width > F->val_len)
			padding(F->field_width - F->val_len, F, ' ');
	}
}

static void	s_with_precision(const char *str, t_flag *flag)
{
	int	j;

	j = 0;
	if (flag->flag_dot)
	{
		while ((str[j]) && (j < flag->precision))
		{
			write(1, &str[j], 1);
			j++;
			(flag->result)++;
			(flag->prtd_in_handl)++;
		}
	}
	else
	{
		while (str[j])
		{
			write(1, &str[j], 1);
			j++;
			(flag->result)++;
			(flag->prtd_in_handl)++;
		}
	}
}

static void	s_minus_handler(t_flag *F)
{
	if (F->Fstr == NULL)
		s_print_null(F);
	else
		s_with_precision(F->Fstr, F);
}

void	ft_s_handler(va_list *arg, t_flag *F)
{
	F->Fstr = va_arg(*arg, char *);
	F->val_len = ft_strlen(F->Fstr);
	if (F->flag_minus)
		s_minus_handler(F);
	else
	{
		if (F->Fstr == NULL)
		{
			if (F->field_width > 6)
				padding(F->field_width - 6, F, ' ');
			s_print_null(F);
		}
		else
		{
			s_add_padding(F);
			s_with_precision(F->Fstr, F);
		}
	}
	if (F->field_width > F->prtd_in_handl)
		padding(F->field_width - F->prtd_in_handl, F, ' ');
	(F->i)++;
}
