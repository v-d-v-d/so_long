/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_all_C.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:53:54 by vdunatte          #+#    #+#             */
/*   Updated: 2024/06/04 04:33:43 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	find_p(t_game *game)
{
	int	len_line;

	len_line = ft_strlen(game->map[0]) - 1;
	game->player_i = 1;
	game->player_j = ft_tablen(game->map) - 1;
	while (game->player_j > 0)
	{
		while (game->player_i <= len_line)
		{
			if (game->map[game->player_j][game->player_i] == 'P')
				return ;
			game->player_i++;
		}
		game->player_i = 1;
		game->player_j--;
	}
}

int	explo_map(char **map, int i, int j)
{
	int	nb;

	nb = 0;
	if (map[j][i] == 'E' || map[j][i] == 'C')
		nb++;
	map[j][i] = '1';
	if (map[j + 1][i] != '1')
		nb += (explo_map(map, i, j + 1));
	if (map[j - 1][i] != '1')
		nb += (explo_map(map, i, j - 1));
	if (map[j][i + 1] != '1')
		nb += (explo_map(map, i + 1, j));
	if (map[j][i - 1] != '1')
		nb += (explo_map(map, i - 1, j));
	return (nb);
}

int	take_all_c(t_game *game)
{
	int	nc;

	find_p(game);
	nc = game->collec + 1;
	if (explo_map(game->map, game->player_i, game->player_j) != nc)
		return (1);
	return (0);
}
