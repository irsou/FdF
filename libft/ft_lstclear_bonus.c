/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:49:59 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/18 19:24:16 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node 'lst' and all subsequent nodes, 
 * using the function 'del' and free(3).
 * At the end, the pointer to the list must be NULL.
 * 
 * @param lst (**lst)
 * @param del (void (*del)(void*))
 */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (!lst)
		return ;
	if (!*lst || !del)
		return ;
	while (*lst)
	{
		next_node = (*lst)-> next;
		del((*lst)-> content);
		free (*lst);
		*lst = next_node;
	}
	*lst = NULL;
}
