/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:53:33 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/27 10:41:13 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_flood(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

int	check_non(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1'
				&& game->map[y][x] != 'P' && game->map[y][x] != 'C'
				&& game->map[y][x] != 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (write(1, "\033[31m🚨error\033[0m\nmap is not .ber\n", 36), 0);
	len -= 4;
	if (str[len++] != '.' || str[len++] != 'b'
		|| str[len++] != 'e' || str[len++] != 'r')
		return (write(1, "\033[31m🚨error\033[0m\nmap is not .ber\n", 36), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2 || !check_ber(av[1]))
		return (1);
	game = malloc(sizeof(t_game));
	ft_memset(game, 0, sizeof(t_game));
	game->size = 64;
	read_map(game, av[1]);
	check_all(game);
	making_win(game);
	render_back(game);
	render_map(&game);
	mlx_hook(game->win_ptr, 17, 0, close_win, &game);
	mlx_key_hook(game->win_ptr, handling_input, &game);
	mlx_loop(game->mlx_ptr);
}
