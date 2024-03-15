/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:50:51 by sgalli            #+#    #+#             */
/*   Updated: 2022/12/21 15:05:25 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef enum e_bool
{
        TRUE = 1,
        FALSE = 0,
}       t_bool;

typedef struct s_vector
{       
        int     x;  
        int     y;
}       t_vector;
*/
#include "map.h"

//controllo se ho un elemento di gioco
int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'
		|| c == 'H' || c == 'V' || c == 'F')
		return (TRUE);
	return (FALSE);
}

//verifico che il carattere c non sia uguale a p
//bool di default FALSE c e diverso da checker(primo caso)
//nel caso e vero diveta TRUE e nel secondo ciclo se si avvera la condizione
//ritorna FALSE
int	valid_uniquechar(char c, char checker, t_bool *bool)
{
	if (c == checker && *bool == FALSE)
		*bool = TRUE;
	else if (c == checker && *bool == TRUE)
		return (FALSE);
	return (TRUE);
}

//controllo il primo o l'ultimo x/y e vedo se e diverso da 1
//se e diverso ritorno FALSE altrimenti TRUE
int	valid_border(char c, t_vector point, t_vector size)
{
	if (point.y == 0 || point.x == 0
		|| point.y == size.y - 1 || point.x == size.x -1)
	{
		if (c != '1')
		{
			return (FALSE);
		}
	}
	return (TRUE);
}
