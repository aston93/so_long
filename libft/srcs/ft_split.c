/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:15:55 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:56:45 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_split_len(const char *s, char c)
{
	int		split_len;
	int		i;

	i = 0;
	if ((s[0] == c) || (ft_strlen(s) == 0))
		split_len = 0;
	else
		split_len = 1;
	while (s[i])
	{
		if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1] != '\0'))
			split_len++;
		i++;
	}
	return (split_len);
}

static void	clean_up(char **splitted_arr, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free(splitted_arr[j]);
		j++;
	}
}

static char	**get_copy_substrs(char **s_arr, const char *s, char c, int s_len)
{
	int		i;
	int		start;
	int		act_str_len;

	i = 0;
	start = 0;
	while (i < s_len)
	{
		act_str_len = 0;
		while (s[start + act_str_len] && s[start + act_str_len] != c)
			act_str_len++;
		if (act_str_len)
			*(s_arr + i) = ft_substr(s, start, act_str_len);
		if (act_str_len && (*(s_arr + i) == NULL))
		{
			clean_up(s_arr, i);
			free(s_arr);
			return (NULL);
		}
		start += act_str_len + 1;
		if (act_str_len)
			i++;
	}
	s_arr[i] = NULL;
	return (s_arr);
}

char	**ft_split(char const *s, char c)
{
	int		split_len;
	char	**splitted_arr;

	split_len = get_split_len(s, c);
	splitted_arr = (char **)malloc((split_len + 1) * sizeof(char *));
	if (splitted_arr == NULL)
		return (NULL);
	splitted_arr = get_copy_substrs(splitted_arr, s, c, split_len);
	return (splitted_arr);
}
