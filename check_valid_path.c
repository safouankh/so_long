/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:45:00 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/26 18:22:07 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	i = ft_strlen(s);
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**copy_map(char **map)
{
	int		rows;
	char	**new_map;
	int		i;

	rows = 0;
	i = 0;
	if (!map)
		return (NULL);
	while (map[rows] != NULL)
		rows++;
	new_map = malloc((rows + 1) * sizeof(char *));
	while (i < rows)
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[rows] = NULL;
	return (new_map);
}

int	flood_fill(char **map, int x, int y, int all)
{
	int static	door;
	int static	colected;
	int			toul;

	toul = 0;
	while (map[toul])
		toul++;
	if (y < toul && x < ft_strlen(map[y]) - 1 && map[y][x] == 'E' && !door)
		ft_printf("", map[y][x] = '1', door = 1);
	if (colected == all && door)
		return (1);
	if (x <= 0 || y <= 0 || y >= toul || x >= ft_strlen(map[y]) - 1
		|| map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C')
		colected++;
	map[y][x] = '1';
	return (flood_fill(map, x + 1, y, all)
		|| flood_fill(map, x - 1, y, all)
		|| flood_fill(map, x, y + 1, all)
		|| flood_fill(map, x, y - 1, all));
}
