/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:37:31 by vdunatte          #+#    #+#             */
/*   Updated: 2024/06/01 07:40:02 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**tabdup(char **src_tab, char **des_tab)
{
	int		i;

	i = 0;
	while (src_tab != NULL && src_tab[i] != NULL)
	{
		des_tab[i] = src_tab[i];
		i++;
	}
	des_tab[i] = NULL;
	return (des_tab);
}

void	tab_add_line(char ***map, char *line)
{
	char	**map2;
	int		sizemap;

	if (*map == NULL)
		sizemap = 0;
	else
		sizemap = ft_tablen(*map);
	map2 = malloc((sizemap + 2) * sizeof(char *));
	if (map2 == NULL)
		return ;
	map2 = tabdup(*map, map2);
	map2[sizemap] = line;
	map2[sizemap + 1] = NULL;
	free(*map);
	*map = map2;
}

char	**get_map(int fd)
{
	char		*line;
	static char	**map = NULL;
	char		**maptemp;

	line = get_next_line(fd);
	if (line == NULL)
	{
		maptemp = map;
		map = NULL;
		return (maptemp);
	}
	tab_add_line(&map, line);
	return (get_map(fd));
}

// int	main(void)
// {
// 	int	fd;
// 	char **map;

// 	fd = open("parsing/map1", O_RDONLY);
// 	if(fd < 0)
// 		return(1);
// 	map = get_map(fd);
// 	printf("%s\n", map[0]);
// 	printf("%s\n", map[1]);
// 	printf("%s\n", map[2]);
// 	printf("%s\n", map[3]);
// 	printf("%s\n", map[4]);
// 	printf("%s\n", map[5]);
// 	return (0);
// }
