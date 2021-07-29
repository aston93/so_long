/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:02:07 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:57:58 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (src_len == 0)
		dst[i] = src[i];
	while ((i < src_len) && (size != 0) && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if ((i > 0) && (src_len > 0))
		dst[i] = '\0';
	return (src_len);
}
