/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:46:26 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:39:30 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*itoa_add_prec(char *result, t_flag *F, int input_str_len)
{
	char	*input_str_cpy;
	int		i;
	int		j;

	i = 1;
	j = 1;
	input_str_cpy = ft_strdup(result);
	free(result);
	result = (char *)malloc(F->precision + 2);
	result[0] = '-';
	while (i < F->precision - input_str_len + 2)
	{
		result[i] = '0';
		i++;
	}
	while (i < F->precision + 1)
	{
		result[i] = input_str_cpy[j];
		i++;
		j++;
	}
	result[i] = '\0';
	free(input_str_cpy);
	return (result);
}

static char	*check_min_int(int n, int *error_nbr)
{
	char	*result;

	result = NULL;
	if (n == -2147483648)
	{
		result = (char *)malloc(12);
		if (result == NULL)
			*error_nbr = 1;
		else
			ft_memcpy(result, "-2147483648", 12);
	}
	return (result);
}

static int	check_str_len(int digits)
{
	int	nbr_of_digits;

	if (digits == 0)
		return (1);
	nbr_of_digits = 0;
	while (digits > 0)
	{
		digits = digits / 10;
		nbr_of_digits++;
	}
	return (nbr_of_digits);
}

static void	conversion_itoa(size_t strlen, size_t is_n, int n, char *result)
{
	char	temp;

	result[strlen] = '\0';
	strlen--;
	while (strlen > is_n)
	{
		temp = (n % 10) + '0';
		result[strlen] = temp;
		n = n / 10;
		strlen--;
	}
	result[strlen] = n + '0';
	if (is_n)
		result[0] = '-';
}

char	*ft_printf_itoa(int n, t_flag *flag)
{
	int		strlen;
	int		is_negative;
	char	*result;
	int		error_nbr;

	strlen = 0;
	is_negative = 0;
	error_nbr = 0;
	result = check_min_int(n, &error_nbr);
	if ((result != NULL) || (error_nbr == 1))
		return (result);
	if (n < 0)
	{
		strlen++;
		n *= -1;
		is_negative = 1;
	}
	strlen += check_str_len(n);
	result = (char *)malloc(strlen + 1);
	if (result == NULL)
		return (result);
	conversion_itoa(strlen, (size_t)is_negative, n, result);
	if ((is_negative) && (flag->precision > strlen))
		result = itoa_add_prec(result, flag, strlen);
	return (result);
}
