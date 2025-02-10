/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:51:05 by sael-kha          #+#    #+#             */
/*   Updated: 2025/01/31 11:53:00 by sael-kha         ###   ########.fr       */
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

void	free_all(t_game **game)
{
	free_map(*game, 0);
	mlx_clear_window((*game)->mlx_ptr, (*game)->win_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->wall);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->character);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->end);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->floor);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->colects);
	mlx_destroy_window((*game)->mlx_ptr, (*game)->win_ptr);
	free(*game);
	exit(0);
}
