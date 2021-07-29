/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prctg_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:47:25 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:39:23 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_prctg_handler(const char *str, t_flag *flag)
{
	write(1, &str[flag->i], 1);
	(flag->result)++;
	(flag->i)++;
}
