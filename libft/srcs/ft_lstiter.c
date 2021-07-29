/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:08:32 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:55:03 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Iterates the list ’lst’ and applies the function
**		’f’ to the content of each element.
**
**	arg #1. The adress of a pointer to an element.
**	arg #2. The adress of the function used to iterate on
**			the list.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f != NULL)
	{
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}
