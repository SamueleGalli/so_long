/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:19:18 by sgalli            #+#    #+#             */
/*   Updated: 2022/12/23 10:34:21 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

//applica <funct> a tutti i contenuti di <lst>
void	ft_lstiter(t_list *lst, void (*funct)(void *))
{
	while (lst != NULL)
	{
		funct(lst->content);
		lst = lst->next;
	}
}

//applica <del> al contenuto della <lst, e la libera
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free (lst);
}

//applica <del> a tutti i contenuti
//e libera tutti i nodi
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*new_next;

	aux = *lst;
	if (*lst == NULL)
		return ;
	while (aux != NULL)
	{
		new_next = aux->next;
		ft_lstdelone (aux, del);
		aux = new_next;
	}
	*lst = NULL;
}

t_list	*ftlstmap(t_list *lst, void *(*funct)(void *), void(*del)(void *))
{
	t_list	*output;
	t_list	*og_output;

	if (lst == NULL || funct == NULL)
		return (NULL);
	output = ft_lstnew(funct(lst->content));
	if (output == NULL)
		return (NULL);
	og_output = output;
	lst = lst->next;
	while (lst != NULL)
	{
		output->next = ft_lstnew(funct(lst->content));
		if (output == NULL)
		{
			ft_lstclear(&og_output, del);
			return (NULL);
		}
		lst = lst->next;
		output = output->next;
	}
	return (og_output);
}
