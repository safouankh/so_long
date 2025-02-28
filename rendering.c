/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:18:25 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/27 10:33:23 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	making_win(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		free_map(game, 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->size * game->x, game->size * game->y, "so_long");
	if (game->win_ptr == NULL)
		free_map(game, 1);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/wall.xpm", &game->char_x, &game->char_y);
	game->character = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/char.xpm", &game->char_x, &game->char_y);
	game->colects = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/coin.xpm", &game->char_x, &game->char_y);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/floor.xpm", &game->char_x, &game->char_y);
	game->end = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/door.xpm", &game->char_x, &game->char_y);
	game->opend_end = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/door_mftoh.xpm", &game->char_x, &game->char_y);
	if (!game->wall || !game->character || !game->colects
		|| !game->floor || !game->end || !game->opend_end)
		return (write(1, "\033[31m🚨error\033[0m\nin xpm\n", 29),
			free_map(game, 0), exit(1));
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
	ft_printf("moves -> %d\n", (*game)->moves++);
}

void	read_map(t_game *game, char *s)
{
	int	i;
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (ft_printf("\033[31m🚨error\033[0m\nthe map is not available.\n"),
			free(game), exit(1));
	game->map = malloc(255);
	i = 0;
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL || i > 22 || ft_strlen(game->map[i]) > 40)
		{
			game->map[i + 1] = NULL;
			break ;
		}
		i++;
	}
	if (i > 22 || ft_strlen(game->map[i - 1]) > 40)
		return (ft_printf("\033[31m🚨error\033[0m\nmap too BIG\n"), free_all(game));
	if (i <= 1)
		return (ft_printf("\033[31m🚨error\033[0m\nmap man3raf\n"), free_all(game));
	game->x = ft_strlen(game->map[i - 1]);
	game->y = i;
}
