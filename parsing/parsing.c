/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:28:16 by vdunatte          #+#    #+#             */
/*   Updated: 2024/06/05 08:27:04 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing_error(char *str, t_game *game, char **map2)
{
	int	n;

	n = 0;
	n = ft_strlen(str);
	write(STDERR_FILENO, str, n);
	free_tab(game->map);
	free_tab(map2);
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**map_dup(char **map)
{
	int		i;
	char	**map2;

	i = 0;
	map2 = malloc((ft_tablen(map) + 1) * sizeof(char *));
	while (map != NULL && map[i] != NULL)
	{
		map2[i] = ft_strdup(map[i]);
		i++;
	}
	map2[i] = NULL;
	return (map2);
}

int	parsing(char *file_map, t_game *game)
{
	int		fd;
	char	**map2;

	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		return (1);
	game->map = get_map(fd);
	close(fd);
	if (game->map == NULL)
		return (parsing_error("grrr pas content, map empty\n", game, NULL));
	map2 = map_dup(game->map);
	if (map_is_closed(game->map))
		return (parsing_error("", game, map2));
	if (char_checker(game))
		return (parsing_error("grrr pas content, wrong char\n", game, map2));
	if (take_all_c(game))
		return (parsing_error("grrr pas content, unfinishable\n", game, map2));
	free_tab(game->map);
	game->map = map2;
	return (0);
}

// int	main(void)
// {
// 	int		fd;
// 	t_game	game;

// 	fd = open("map/map1", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	if (!parsing(fd, &game))
// 		printf("%s\n", "good");
// 	printf("%s\n", game.map[0]);
// 	printf("%s\n", game.map[1]);
// 	printf("%s\n", game.map[2]);
// 	printf("%s\n", game.map[3]);
// 	printf("%s\n", game.map[4]);
// 	printf("%s\n", game.map[5]);
// 	return (0);
// }
