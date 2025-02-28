/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:51:05 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/26 17:45:10 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game, int ok)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	if (ok)
	{
		free(game);
		exit(0);
	}
}

void	free_all(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->character)
		mlx_destroy_image(game->mlx_ptr, game->character);
	if (game->end)
		mlx_destroy_image(game->mlx_ptr, game->end);
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->colects)
		mlx_destroy_image(game->mlx_ptr, game->colects);
	if (game->opend_end)
		mlx_destroy_image(game->mlx_ptr, game->opend_end);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_map(game, 1);
}

int	close_win(t_game **game)
{
	free_all(*game);
	return (0);
}
