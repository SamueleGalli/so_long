/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:15:45 by sgalli            #+#    #+#             */
/*   Updated: 2023/01/30 14:26:21 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICS_BONUS_H
# define BASICS_BONUS_H

# include "libft_bonus/libft_bonus.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

int		error(char *message);
void	*null_error(char *message);
void	print_warning(char *message);

#endif
