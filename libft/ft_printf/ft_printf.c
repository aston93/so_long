/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:07:49 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:51:39 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	check_handlers_engine(const char *str, va_list *argList, t_flag *F)
{
	(F->i)++;
	check_flags(F, str, argList);
	if (str[F->i] == '%')
		ft_prctg_handler(str, F);
	else if (str[F->i] == 'c')
		ft_c_handler(argList, F);
	else if (str[F->i] == 's')
		ft_s_handler(argList, F);
	else if (str[F->i] == 'p')
		ft_p_handler(argList, F);
	else if ((str[F->i] == 'd') || (str[F->i] == 'i'))
		ft_d_i_handler(argList, F);
	else if (str[F->i] == 'u')
		ft_u_handler(argList, F);
	else if (str[F->i] == 'X')
		ft_hex_converter(argList, F, 'X');
	else if (str[F->i] == 'x')
		ft_hex_converter(argList, F, 'x');
}

/* main engine */

static void	v_printf(const char *str, va_list *argList, t_flag *flag)
{
	while (str[flag->i] != '\0')
	{
		if (str[flag->i] == '%')
			check_handlers_engine(str, argList, flag);
		else
		{
			write(1, &str[flag->i], 1);
			(flag->i)++;
			(flag->result)++;
		}
	}
}

/* setting up the environment (flag, va_list) */

int	ft_printf(const char *str, ...)
{
	va_list	argList;
	t_flag	*flag;
	int		res;

	va_start(argList, str);
	flag = (t_flag *)malloc(sizeof(t_flag));
	flag->i = 0;
	flag->result = 0;
	if (flag == NULL)
		return (-1);
	v_printf(str, &argList, flag);
	va_end(argList);
	res = flag->result;
	free(flag);
	return (res);
}
