/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:38:56 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:58:02 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	result;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		result = size + src_len;
	else
	{
		i = 0;
		while (i + dst_len + 1 < size && *(src + i))
		{
			*(dst + dst_len + i) = *(src + i);
			i++;
		}
		*(dst + dst_len + i) = '\0';
		result = dst_len + src_len;
	}
	return (result);
}
