/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:23:44 by vi                #+#    #+#             */
/*   Updated: 2024/06/05 08:25:56 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "parsing/parsing.h"
#include "rendering/rendering.h"

int	so_long_error(char *str, char **map)
{
	int	n;

	n = 0;
	n = ft_strlen(str);
	write(STDERR_FILENO, str, n);
	if (map != NULL)
		free_tab(map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		return (so_long_error("grrr pas content, wrong argc\n", NULL));
	if (ft_strncmp_r(argv[1], ".ber", 5))
		return (so_long_error("grrr pas content, name file\n", NULL));
	if (parsing(argv[1], &game))
		return (so_long_error("grrr pas content, parsing ko\n", NULL));
	if (rendering(&game))
		return (so_long_error("grrr pas content, rendering ko\n", game.map));
	free_tab(game.map);
	return (0);
}
	// printf("%s\n", game.map[0]);
	// printf("%s\n", game.map[1]);
	// printf("%s\n", game.map[2]);
	// printf("%s\n", game.map[3]);
	// printf("%s\n", game.map[4]);
	// printf("%p\n", game.map[5]);