/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:00:25 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:55:33 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*input_str;
	unsigned char	target;
	unsigned char	*result;
	size_t			i;
	int				exit;

	input_str = (unsigned char *)str;
	target = (unsigned char)c;
	result = 0;
	i = 0;
	exit = 0;
	while ((i < n) && (exit == 0))
	{
		if (input_str[i] == target)
		{
			result = &input_str[i];
			exit = 1;
		}
		i++;
	}
	return ((void *)result);
}
