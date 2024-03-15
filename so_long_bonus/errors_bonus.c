/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:24:04 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/19 11:00:22 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//ritorna 0 stampando un messaggio in rosso
int	error(char *message)
{
	printf("\033[0;31m" " Error\n  %s\n" "\033[0m", message);
	return (0);
}

//ritorna NULL stampando un messaggio in rosso
void	*null_error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (NULL);
}

// stampa messaggio in giallo
void	print_warning(char *message)
{
	printf("\033[0;33m"" Warning\n %s\n" "\033[0m", message);
}
