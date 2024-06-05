/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 06:30:19 by vdunatte          #+#    #+#             */
/*   Updated: 2024/06/05 07:26:47 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "get_next_line.h"
# include "minilibx-linux/mlx.h"

typedef struct s_game
{
	char	**map;
	int		collec;
	int		player_j;
	int		player_i;
}	t_game;

#endif
