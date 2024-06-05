/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 05:38:11 by vi                #+#    #+#             */
/*   Updated: 2024/06/05 07:11:12 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "../minilibx-linux/mlx.h"

# include "../so_long.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*image[5];
}	t_mlx;

typedef struct s_param
{
	t_game	*game;
	t_mlx	mlx;
}	t_param;

int	rendering(t_game *game);
int	display_map(t_game game, t_mlx mlx);
int	moving(int key_code, t_param *param);
#endif