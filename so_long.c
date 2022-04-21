/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:24:54 by aait-mas          #+#    #+#             */
/*   Updated: 2022/04/20 01:07:41 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tab2d_building(char **argv, t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	game->mat = (char **)malloc(sizeof(char *) * (game->height) + 1);
	while (i <= game->height)
	{
		game->mat[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2
		|| check_extension(argv) == 1
		|| map_height_width(argv, &game) == 1)
		return (ft_putstr("Error..  Invalid Arguments"));
	if (check_elements(argv, &game) == 1
		|| map_checker(argv, &game) == 1
		|| check_walls(argv, &game) == 1
		|| check_player(argv, &game) != 1
		|| check_collectible(argv, &game) < 1
		|| check_exit(argv, &game) < 1)
		return (ft_putstr("Error..  Invalid Map"));
	tab2d_building(argv, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 80,
			game.height * 80 + 30, "So_long");
	image_initialization(&game);
	draw_map(&game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
