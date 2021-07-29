/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:33:11 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:56:03 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	char	*dst;
	char	*src;
	char	*buff;
	size_t	i;

	dst = (char *)destination;
	src = (char *)source;
	buff = (char *)malloc(num + 1);
	i = 0;
	while (i < num)
	{
		buff[i] = src[i];
		i++;
	}
	i = 0;
	while (i < num)
	{
		dst[i] = buff[i];
		i++;
	}
	free(buff);
	return (destination);
}
