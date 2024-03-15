/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:04:17 by sgalli            #+#    #+#             */
/*   Updated: 2022/12/23 10:18:29 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//crea con mallocun nuovo elemento della lista
//con contenuto = <con> e successivo = NULL
t_list	*ft_lstnew(void *con)
{
	t_list	*output;

	output = (t_list *)malloc(sizeof(t_list));
	if (output == 0)
		return (NULL);
	output->content = con;
	output->next = NULL;
	return (output);
}

//aggiunge <new> alla fine della lista
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst != NULL)
		(ft_lstlast(*lst))->next = new;
	else
		*lst = new;
}

//mette l'elemento puntato da <new> come
//primo elemento della lista
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

//ritorna un puntatore all'ultimo elemento di <lst>
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

//ritorna il numero di elementi
int	ft_lstsize(t_list *lst)
{
	int	count;

	if (lst == NULL)
		return (0);
	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
