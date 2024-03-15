/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:35:06 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/26 10:23:26 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//ritorna il numero di righe divise da '\n'
int	ft_chartable_linecount(char **table)
{
	int	count;

	count = 0;
	while (table[count] != NULL)
		count++;
	return (count);
}

//libero ogni riga della martrice
void	ft_free_chartable(char **table)
{
	char	**t;

	t = table;
	while (*t != NULL)
	{
		free(*t);
		t++;
	}
	free(table);
}
