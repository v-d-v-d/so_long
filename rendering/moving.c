/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 07:26:27 by vi                #+#    #+#             */
/*   Updated: 2024/06/05 07:13:43 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	move_left(t_game *game, t_mlx mlx)
{
	if (game->map[game->player_j][game->player_i - 1] != '1')
	{
		if (game->map[game->player_j][game->player_i - 1] == 'C')
		{
			game->collec--;
			game->map[game->player_j][game->player_i - 1] = '0';
		}
		if (game->map[game->player_j][game->player_i] == 'E')
		{
			mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[2],
				game->player_i * 80, game->player_j * 80);
		}
		else
		{
			mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[0],
				game->player_i * 80, game->player_j * 80);
		}
		game->player_i--;
		mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[3],
			game->player_i * 80, game->player_j * 80);
	}
}

void	move_up(t_game *game, t_mlx mlx)
{
	if (game->map[game->player_j - 1][game->player_i] != '1')
	{
		if (game->map[game->player_j - 1][game->player_i] == 'C')
		{
			game->collec--;
			game->map[game->player_j - 1][game->player_i] = '0';
		}
		if (game->map[game->player_j][game->player_i] == 'E')
		{
			mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[2],
				game->player_i * 80, game->player_j * 80);
		}
		else
		{
			mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[0],
				game->player_i * 80, game->player_j * 80);
		}
		game->player_j--;
		mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[3],
			game->player_i * 80, game->player_j * 80);
	}
}

void	move_right(t_game *game, t_mlx mlx)
{
	if (game->map[game->player_j][game->player_i + 1] != '1')
	{
		if (game->map[game->player_j][game->player_i + 1] == 'C')
		{
			game->collec--;
			game->map[game->player_j][game->player_i + 1] = '0';
		}
		if (game->map[game->player_j][game->player_i] == 'E')
		{
			mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[2],
				game->player_i * 80, game->player_j * 80);
		}
		else
		{
			mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[0],
				game->player_i * 80, game->player_j * 80);
		}
		game->player_i++;
		mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[3],
			game->player_i * 80, game->player_j * 80);
	}
}

void	move_down(t_game *game, t_mlx mlx)
{
	if (game->map[game->player_j + 1][game->player_i] != '1')
	{
		if (game->map[game->player_j + 1][game->player_i] == 'C')
		{
			game->collec--;
			game->map[game->player_j + 1][game->player_i] = '0';
		}
		if (game->map[game->player_j][game->player_i] == 'E')
		{
			mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[2],
				game->player_i * 80, game->player_j * 80);
		}
		else
		{
			mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[0],
				game->player_i * 80, game->player_j * 80);
		}
		game->player_j++;
		mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image[3],
			game->player_i * 80, game->player_j * 80);
	}
}

int	moving(int key, t_param *param)
{
	t_game		*game;
	t_mlx		mlx;
	static int	cm = 0;

	game = param->game;
	mlx = param->mlx;
	if (key == 65361)
		move_left(game, mlx);
	if (key == 65362)
		move_up(game, mlx);
	if (key == 65363)
		move_right(game, mlx);
	if (key == 65364)
		move_down(game, mlx);
	if (key == 65307)
		mlx_loop_end(mlx.mlx);
	if (65361 <= key && key <= 65364)
	{
		if (game->map[game->player_j][game->player_i] == 'E')
			if (game->collec == 0)
				mlx_loop_end(mlx.mlx);
		ft_putnbr_fd(++cm, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

// 65361 gauche
// 65362 haut
// 65363 droit
// 65364 bas 
// 65307 echap
