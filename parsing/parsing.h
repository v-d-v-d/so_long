/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 06:33:35 by vdunatte          #+#    #+#             */
/*   Updated: 2024/06/03 06:09:59 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "get_next_line.h"

# include "../so_long.h"

int		parsing(char *file_map, t_game *game);
char	**get_map(int fd);
int		map_is_closed(char **tab);
int		char_checker(t_game *game);
int		take_all_c(t_game *game);

void	free_tab(char **tab);

#endif
