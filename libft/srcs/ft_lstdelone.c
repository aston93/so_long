/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:32:21 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:54:43 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	param #1. The element to free.
**	param #2. The address of the function used to delete the
**				content.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if ((lst != NULL) && (del != NULL))
	{
		(*del)(lst->content);
		free(lst);
	}
}
