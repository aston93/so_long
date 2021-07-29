/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:52:09 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:54:31 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	arg #1. The adress of a pointer to an element.
**	arg #2. The adress of the function used to delete the
**			content of the element.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*del_temp;

	temp = *lst;
	del_temp = *lst;
	*lst = NULL;
	if (del != NULL)
	{
		while (temp)
		{
			temp = temp->next;
			ft_lstdelone(del_temp, del);
			del_temp = temp;
		}
	}
}
