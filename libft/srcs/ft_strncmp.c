/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:04:16 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:57:30 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (n == 0)
		return (0);
	while (n > 0 && *str1 && *str2)
	{
		if ((*str1 != *str2) || (n == 1))
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1++;
		str2++;
		n--;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
