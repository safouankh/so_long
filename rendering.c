/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:18:25 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/10 15:03:00 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	making_win(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		free_map(game, 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->size * game->x, game->size * game->y, "khaliha 3la lah");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		free_map(game, 1);
	}
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/nazi_wall.xpm", &game->char_x, &game->char_y);
	game->character = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/char.xpm", &game->char_x, &game->char_y);
	game->colects = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/coin.xpm", &game->char_x, &game->char_y);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/grr.xpm", &game->char_x, &game->char_y);
	game->end = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/faran.xpm", &game->char_x, &game->char_y);
	game->opend_end = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/faran_mftoh.xpm", &game->char_x, &game->char_y);
}

void	render_back(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	x = 0;
	y = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, game->floor, x, y);
			x += game->size;
			if (game->map[i][j] == '\n')
			{
				y += game->size;
				x = 0;
			}
			j++;
		}
		i++;
	}
}

void	render_tile(t_game **game, char tile, int x, int y)
{
	if (tile == 'P')
	{
		(*game)->char_x = x;
		(*game)->char_y = y;
		mlx_put_image_to_window((*game)->mlx_ptr,
			(*game)->win_ptr, (*game)->character, x, y);
	}
	if (tile == '1')
		mlx_put_image_to_window((*game)->mlx_ptr,
			(*game)->win_ptr, (*game)->wall, x, y);
	if (tile == '0')
		mlx_put_image_to_window((*game)->mlx_ptr,
			(*game)->win_ptr, (*game)->floor, x, y);
	if (tile == 'C')
		mlx_put_image_to_window((*game)->mlx_ptr,
			(*game)->win_ptr, (*game)->colects, x, y);
	if (tile == 'E')
	{
		mlx_put_image_to_window((*game)->mlx_ptr,
			(*game)->win_ptr, (*game)->end, x, y);
		(*game)->x_end = x;
		(*game)->y_end = y;
	}
}

void	render_map(t_game **game)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	x = (*game)->size;
	while ((*game)->map[++y])
	{
		i = -1;
		while ((*game)->map[y][++i])
			render_tile(game, (*game)->map[y][i], i * x, y * x);
	}
}

void	read_map(t_game *game, char *s)
{
	int	i;
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\033[31merror\033[0m\nthe map is not available.");
		free(game);
		exit(1);
	}
	game->map = malloc(255);
	i = 0;
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			break ;
		i++;
	}
	game->x = ft_strlen(game->map[i - 1]);
	game->y = i;
}
