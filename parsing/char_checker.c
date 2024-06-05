/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:12:07 by vdunatte          #+#    #+#             */
/*   Updated: 2024/06/01 07:52:09 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	char_correct(char **map)
{
	if (*map == NULL)
		return (0);
	if (map[0][0] == '\0')
		return (char_correct(map + 1));
	if (ft_strchr("EPC01\n", map[0][0]) == NULL)
		return (1);
	map[0]++;
	return (char_correct(map));
}

int	char_count(char **map, char c)
{
	if (*map == NULL)
		return (0);
	if (map[0][0] == '\0')
		return (char_count(map + 1, c));
	if (map[0][0] == c)
	{
		map[0]++;
		return (char_count(map, c) + 1);
	}
	map[0]++;
	return (char_count(map, c));
}

int	char_checker(t_game *game)
{
	char	**map2;

	map2 = malloc((ft_tablen(game->map) + 1) * sizeof(char *));
	map2 = ft_tabdup(game->map, map2);
	if (char_correct(map2))
		return (free (map2), 1);
	free (map2);
	map2 = malloc((ft_tablen(game->map) + 1) * sizeof(char *));
	map2 = ft_tabdup(game->map, map2);
	if (char_count(map2, 'E') != 1)
		return (free (map2), 11);
	free (map2);
	map2 = malloc((ft_tablen(game->map) + 1) * sizeof(char *));
	map2 = ft_tabdup(game->map, map2);
	if (char_count(map2, 'P') != 1)
		return (free (map2), 12);
	free (map2);
	map2 = malloc((ft_tablen(game->map) + 1) * sizeof(char *));
	map2 = ft_tabdup(game->map, map2);
	game->collec = char_count(map2, 'C');
	if (game->collec < 1)
		return (free (map2), 13);
	free (map2);
	return (0);
}

// int main()
// {
// 	char *tab[] = {"1111111111111", 
// 				   "100100000001", 
// 				   "1000011111001", 
// 				   "1P0011E000001", 
// 				   "1111111111111",
// 				   NULL
// 				   };
// 	printf("%d\n", char_checker(tab));
// 	// printf("%s\n", tab[0]);
// 	// printf("%s\n", tab[1]);
// 	// printf("%s\n", tab[2]);
// 	// printf("%s\n", tab[3]);
// 	// printf("%s\n", tab[4]);
// 	// printf("%s\n", tab[5]);
// 	return(1);
// }
