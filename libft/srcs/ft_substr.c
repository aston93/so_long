/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:23:26 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:57:07 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	arr_len;
	size_t	ammount_to_cpy;
	char	*result;

	arr_len = ft_strlen((char *) s);
	if ((size_t)start > arr_len)
		return (ft_strdup(""));
	ammount_to_cpy = arr_len - start;
	if (len < ammount_to_cpy)
		ammount_to_cpy = len;
	result = (char *)malloc(ammount_to_cpy + 1);
	if (result == 0)
		return (NULL);
	ft_memcpy(result, s + start, ammount_to_cpy);
	result[ammount_to_cpy] = '\0';
	return (result);
}
