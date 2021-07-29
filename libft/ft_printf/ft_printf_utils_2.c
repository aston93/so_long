/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:25:30 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:51:13 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	padding(int padding_size, t_flag *flag, char chr)
{
	int	i;

	i = 0;
	if (padding_size <= 0)
		return ;
	while (i < padding_size)
	{
		write(1, &chr, 1);
		i++;
		(flag->result)++;
		(flag->prtd_in_handl)++;
	}
}

void	ft_putstr_printf(char *str, t_flag *flag)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		write(1, &str[j], 1);
		(flag->result)++;
		(flag->prtd_in_handl)++;
		j++;
	}
}

char	store_uppercase(int num)
{
	char	arr[16];
	int		i;

	i = 0;
	while (i < 10)
	{
		arr[i] = i + '0';
		i++;
	}
	i = 0;
	while (i < 6)
	{
		arr[i + 10] = i + 'A';
		i++;
	}
	return (arr[num]);
}

char	store_lowercase(int num)
{
	char	arr[16];
	int		i;

	i = 0;
	while (i < 10)
	{
		arr[i] = i + '0';
		i++;
	}
	i = 0;
	while (i < 6)
	{
		arr[i + 10] = i + 'a';
		i++;
	}
	return (arr[num]);
}
