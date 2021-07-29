/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:55:17 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:57:10 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_in_set(char const in_array, char const *arr_set)
{
	int		i;

	i = 0;
	while (arr_set[i])
	{
		if (arr_set[i] == in_array)
			return (1);
		i++;
	}
	return (0);
}

static int	check_len(char const *arr, char const *set)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = ft_strlen((char *)arr) - 1;
	flag = 1;
	while ((arr[i]) && flag)
	{
		if (!is_in_set(arr[i], set))
			flag = 0;
		else
			i++;
	}
	if (i == (j + 1))
		return (0);
	while ((is_in_set(arr[j], set)) && (j > 0))
		j--;
	return (j - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		result_len;

	i = 0;
	result_len = check_len(s1, set);
	result = (char *)malloc(result_len + 1);
	if (result == NULL)
		return (NULL);
	if (result_len != 0)
	{
		while (is_in_set(s1[i], set) && s1[i])
			i++;
		ft_memcpy(result, s1 + i, result_len);
	}
	result[result_len] = '\0';
	return (result);
}
