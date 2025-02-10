/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:07:22 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/10 16:29:10 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_len(t_game *game)
{
	int	i;

	i = 0;
	while (1)
	{
		if (game->map[i + 2] == NULL)
		{
			if (ft_strlen(game->map[i]) - 1 != ft_strlen(game->map[i + 1]))
				return (1);
			break ;
		}
		else if (ft_strlen(game->map[i]) != ft_strlen(game->map[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	check_close(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != NULL)
	{
		if (game->map[i][0] != '1' || game->map[i][game->x - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (game->map[0][i] == '1')
		i++;
	while (game->map[game->y - 1][j] == '1')
		j++;
	if (game->map[0][i] != '\n' || game->map[game->y - 1][j] != '\0')
		return (1);
	return (0);
}

int	check_main(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				ft_printf("", game->c_start++, game->char_x = i,
					game->char_y = j);
			if (game->map[i][j] == 'C')
				game->c_colects++;
			if (game->map[i][j] == 'E')
				game->c_end++;
			j++;
		}
		i++;
	}
	if (game->c_start != 1 || game->c_colects == 0 || game->c_end != 1)
		return (1);
	return (0);
}

void	check_all(t_game *game)
{
	int		i;
	char	**map;

	i = 0;
	if (game->y >= game->x)
		ft_printf("\033[31merror\033[0m\nyour map is rectangular\n", i++);
	if (check_close(game))
		ft_printf("\033[31merror\033[0m\nyour map is not closed with walls\n", i++);
	if (check_len(game))
		ft_printf("\033[31merror\033[0m\nthe line of the map are not equal\n", i++);
	if (check_main(game))
	{
		ft_printf("\033[31merror\033[0m\n");
		ft_printf("1 player 1 door and at least 1 collectibles\n", i++);
	}
	map = copy_map(game->map);
	if (!flood_fill(map, (game->char_x / 64) + 1,
			(game->char_y / 64) + 1, game->c_colects))
		ft_printf("\033[31merror\033[0m\nno valid path\n", i++);
	free_flood(map);
	if (i)
	{
		print_shrek();
		free_map(game, 1);
	}
}
