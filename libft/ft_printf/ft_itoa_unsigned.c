/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:46:13 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:39:11 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_str_len(unsigned int digits)
{
	size_t	nbr_of_digits;

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

static void	conversion_itoa(size_t strlen, unsigned int n, char *result)
{
	char	temp;

	result[strlen] = '\0';
	strlen--;
	while (strlen)
	{
		temp = (n % 10) + '0';
		result[strlen] = temp;
		n = n / 10;
		strlen--;
	}
	result[strlen] = n + '0';
}

char	*ft_itoa_unsigned(unsigned int n)
{
	size_t	strlen;
	char	*result;

	strlen = 0;
	strlen += check_str_len(n);
	result = (char *)malloc(strlen + 1);
	if (result == NULL)
		return (result);
	conversion_itoa(strlen, n, result);
	return (result);
}
