/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:01:56 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:57:19 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	needle_len;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen((char *)needle);
	if ((len < needle_len) || (needle_len == 0))
		return (NULL);
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] && j < needle_len
			&& haystack[i + j] == needle[j])
			j++;
		if (j == needle_len && i + j <= len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
