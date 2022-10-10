/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:41:02 by jungchoi          #+#    #+#             */
/*   Updated: 2022/03/22 14:46:43 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstPtr;

	lstPtr = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (lstPtr->next)
			lstPtr = lstPtr->next;
		lstPtr->next = new;
	}
}
