/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:50:26 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/10 16:29:31 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "GET_NEXT_LINE/get_next_line.h"
#include <fcntl.h>
#include "FT_PRINTF/ft_printf.h"

typedef struct t_game
{
	void	*wall;
	void	*character;
	void	*colects;
	void	*end;
	void	*opend_end;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor;
	char	**map;
	int		size;
	int		x;
	int		y;
	int		char_x;
	int		char_y;
	int		x_end;
	int		y_end;
	int		c_colects;
	int		c_start;
	int		c_end;
	int		moves;
	int		test;
}		t_game;

/* functions for checking map */
int		ft_strlen(char *str);
int		check_len(t_game *game);
int		check_close(t_game *game);
int		check_main(t_game *game);
void	check_all(t_game *game);
void	print_shrek(void);
void	print_hitler(void);
void	free_flood(char **str);
char	**copy_map(char **map);
int		flood_fill(char **map, int x, int y, int all);
int		can_collect_and_escape(t_game **game,
			int start_x, int start_y, int *collectibles);

/* rendering map */
void	making_win(t_game *game);
void	render_map(t_game **game);
void	read_map(t_game *game, char *s);
void	render_back(t_game *game);

/* moves */
int		handling_input(int keycode, t_game **game);
void	move_right(t_game **game);
void	move_left(t_game **game);
void	move_down(t_game **game);
void	move_up(t_game **game);

/* free error */
void	free_map(t_game *game, int ok);
void	free_all(t_game **game);
