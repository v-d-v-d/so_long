/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:02:02 by vi                #+#    #+#             */
/*   Updated: 2024/06/05 07:32:34 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	error_mlx(t_mlx *mlx, char *str)
{
	int	n;

	n = 0;
	while (n < 5)
	{
		if (mlx->image[n] != NULL)
			mlx_destroy_image(mlx->mlx, mlx->image[n]);
		n++;
	}
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	n = ft_strlen(str);
	write(STDERR_FILENO, str, n);
	return (1);
}

int	open_image(t_mlx *mlx)
{
	int	n;

	mlx->image[0] = mlx_xpm_file_to_image(mlx->mlx, "image/0.xpm", &n, &n);
	mlx->image[1] = mlx_xpm_file_to_image(mlx->mlx, "image/1.xpm", &n, &n);
	mlx->image[2] = mlx_xpm_file_to_image(mlx->mlx, "image/E.xpm", &n, &n);
	mlx->image[3] = mlx_xpm_file_to_image(mlx->mlx, "image/P.xpm", &n, &n);
	mlx->image[4] = mlx_xpm_file_to_image(mlx->mlx, "image/C.xpm", &n, &n);
	n = 0;
	while (n < 5)
	{
		if (mlx->image[n] == NULL)
			return (1);
		n++;
	}
	return (0);
}

int	exit_window(t_param *param)
{
	return (moving(65307, param));
}

int	rendering(t_game *game)
{
	t_mlx	mlx;
	t_param	param;
	int		i;
	int		j;

	i = ((int)ft_strlen(game->map[0]) - 1) * 80;
	j = ft_tablen(game->map) * 80;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (error_mlx(&mlx, "grrr pas content, mlx init\n"));
	mlx.window = mlx_new_window(mlx.mlx, i, j, "grrr j'ai pas d'idee");
	if (mlx.window == NULL)
		return (error_mlx(&mlx, "grrr pas content, mlx window\n"));
	if (open_image(&mlx))
		return (error_mlx(&mlx, "grrr pas content, image not good\n"));
	if (display_map(*game, mlx))
		return (error_mlx(&mlx, "grrr pas content, display_map ko\n"));
	param = (t_param){game, mlx};
	mlx_key_hook(mlx.window, moving, &param);
	mlx_hook(mlx.window, 33, (1L << 17), exit_window, &param);
	mlx_loop(mlx.mlx);
	error_mlx(&mlx, "");
	return (0);
}
