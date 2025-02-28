/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:37:21 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/25 19:39:20 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game **game)
{
	if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == '1')
		return ;
	if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == 'E'
		&& (*game)->c_colects != 0)
		return ;
	if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == 'C')
	{
		(*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] = '0';
		(*game)->c_colects--;
		mlx_put_image_to_window((*game)->mlx_ptr,
			(*game)->win_ptr, (*game)->floor,
			(*game)->char_x, (*game)->char_y - 64);
	}
	if ((*game)->map[((*game)->char_y / 64) - 1][((*game)->char_x / 64)] == 'E'
		&& (*game)->c_colects == 0)
		free_all(*game);
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->floor, (*game)->char_x, (*game)->char_y);
	(*game)->char_y -= 64;
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->character, (*game)->char_x, (*game)->char_y);
	ft_printf("moves -> %d\n", (*game)->moves++);
}

void	move_down(t_game **game)
{
	if ((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] == '1')
		return ;
	if ((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] == 'E'
		&& (*game)->c_colects != 0)
		return ;
	if ((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] == 'C')
	{
		(*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] = '0';
		(*game)->c_colects--;
		mlx_put_image_to_window((*game)->mlx_ptr,
			(*game)->win_ptr, (*game)->floor,
			(*game)->char_x, (*game)->char_y + 64);
	}
	if ((*game)->map[((*game)->char_y / 64) + 1][((*game)->char_x / 64)] == 'E'
			&& (*game)->c_colects == 0)
		free_all(*game);
	mlx_put_image_to_window((*game)->mlx_ptr,
		(*game)->win_ptr, (*game)->floor, (*game)->char_x, (*game)->char_y);
	(*game)->char_y += 64;
	mlx_put_image_to_window((*game)->mlx_ptr,
		(*game)->win_ptr, (*game)->character, (*game)->char_x, (*game)->char_y);
	ft_printf("moves -> %d\n", (*game)->moves++);
}

void	move_left(t_game **game)
{
	if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == '1')
		return ;
	if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == 'E'
		&& (*game)->c_colects != 0)
		return ;
	if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == 'C')
	{
		(*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] = '0';
		(*game)->c_colects--;
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->floor, (*game)->char_x - 64, (*game)->char_y);
	}
	if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) - 1] == 'E'
		&& (*game)->c_colects == 0)
		free_all(*game);
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->floor, (*game)->char_x, (*game)->char_y);
	(*game)->char_x -= 64;
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->character, (*game)->char_x, (*game)->char_y);
	ft_printf("moves -> %d\n", (*game)->moves++);
}

void	move_right(t_game **game)
{
	if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == '1')
		return ;
	if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == 'E'
		&& (*game)->c_colects != 0)
		return ;
	if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == 'C')
	{
		(*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] = '0';
		(*game)->c_colects--;
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->floor, (*game)->char_x + 64, (*game)->char_y);
	}
	if ((*game)->map[((*game)->char_y / 64)][((*game)->char_x / 64) + 1] == 'E'
		&& (*game)->c_colects == 0)
		free_all(*game);
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->floor, (*game)->char_x, (*game)->char_y);
	(*game)->char_x += 64;
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->character, (*game)->char_x, (*game)->char_y);
	ft_printf("moves -> %d\n", (*game)->moves++);
}

int	handling_input(int keycode, t_game **game)
{
	static int	key;

	if (keycode == 0)
		move_left(game);
	else if (keycode == 13)
		move_up(game);
	else if (keycode == 1)
		move_down(game);
	else if (keycode == 2)
		move_right(game);
	else if (keycode == 53)
		free_all(*game);
	if (!(*game)->c_colects && key == 0)
	{
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->floor, (*game)->x_end, (*game)->y_end);
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->opend_end, (*game)->x_end, (*game)->y_end);
		key = 1;
	}
	return (0);
}
