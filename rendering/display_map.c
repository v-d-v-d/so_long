/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:13:36 by vi                #+#    #+#             */
/*   Updated: 2024/06/05 07:11:41 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	nb_image(char c)
{
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == 'E')
		return (2);
	if (c == 'P')
		return (3);
	if (c == 'C')
		return (4);
	return (0);
}

int	display_map(t_game game, t_mlx mlx)
{
	int	i;
	int	j;

	j = 0;
	while (game.map[j] != NULL)
	{
		i = 0;
		while (game.map[j][i] != '\n')
		{
			mlx_put_image_to_window(mlx.mlx, mlx.window,
				mlx.image[nb_image(game.map[j][i])], i * 80, j * 80);
			i++;
		}
		j++;
	}
	return (0);
}
