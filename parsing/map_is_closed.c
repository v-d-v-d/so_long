/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 05:52:51 by vdunatte          #+#    #+#             */
/*   Updated: 2024/06/05 08:38:12 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	map_error(char *str)
{
	int	n;

	n = 0;
	n = ft_strlen(str);
	write(STDERR_FILENO, str, n);
	return (1);
}

int	lineslen_are_equals(char **tab)
{
	int		lentab;
	size_t	lenline;

	lentab = ft_tablen(tab) - 1;
	lenline = ft_strlen(tab[0]);
	if (lentab > 100 || lenline > 100)
		return (map_error("grrr pas content, map too big\n"));
	while (lentab > 0)
	{
		if (lenline != ft_strlen(tab[lentab]))
			return (map_error("grrr pas content, map not rectangle\n"));
		lentab--;
	}
	return (0);
}

int	first_last_line_is_1(char **tab)
{
	int	lentab;
	int	lenline;
	int	i;

	lentab = ft_tablen(tab) - 1;
	lenline = ft_strlen(tab[0]);
	i = 0;
	while (i < lenline - 1)
	{
		if (tab[0][i] != '1' || tab[lentab][i] != '1')
			return (map_error("grrr pas content, map is not closed\n"));
		i++;
	}
	return (0);
}

int	first_last_char_is_1(char **tab)
{
	int	lentab;
	int	lenline;

	lentab = ft_tablen(tab) - 1;
	lenline = ft_strlen(tab[0]) - 1;
	while (lentab >= 0)
	{
		if (tab[lentab][0] != '1' || tab[lentab][lenline - 1] != '1')
			return (map_error("grrr pas content, map is not closed\n"));
		lentab--;
	}
	return (0);
}

int	map_is_closed(char **tab)
{
	if (lineslen_are_equals(tab))
		return (5);
	if (first_last_line_is_1(tab))
		return (16);
	if (first_last_char_is_1(tab))
		return (17);
	return (0);
}

// int main()
// {
// 	char *tab[] = {"1111111111111", 
// 				   "10010000000C1", 
// 				   "1000011111001", 
// 				   "1P0011E000001", 
// 				   "1111111111111"
// 				   };
// 	printf("%d", map_is_closed(tab));
// 	return(1);
// }
