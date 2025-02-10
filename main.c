/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:53:33 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/10 16:47:58 by sael-kha         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_game));
	ft_memset(game, 0, sizeof(t_game));
	game->size = 64;
	read_map(game, av[1]);
	check_all(game);
	print_hitler();
	making_win(game);
	render_back(game);
	render_map(&game);
	mlx_key_hook(game->win_ptr, handling_input, &game);
	mlx_loop(game->mlx_ptr);
}
