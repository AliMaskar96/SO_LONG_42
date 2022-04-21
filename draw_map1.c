/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:14 by aait-mas          #+#    #+#             */
/*   Updated: 2022/04/20 01:43:51 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game)
{
	char	*move;

	move = ft_itoa(game->move_count);
	empty_set(game);
	put_images(game);
	mlx_string_put(game->mlx, game->win, game->width * 40 + 300, 0,
		0xffffffff, "SCORE : ");
	mlx_string_put(game->mlx, game->win, game->width * 40 + 400, 0,
		0xffffffff, move);
	mlx_string_put(game->mlx, game->win, game->width * 40 -30, 0,
		0xffffffff, "LEVEL 1");
	mlx_string_put(game->mlx, game->win, game->width * 40 - 400, 0,
		0xffffffff, "SUPER MARIO");
	free(move);
}

void	empty_set(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			game->x_empty = j * 80;
			game->y_empty = i * 80;
			mlx_put_image_to_window(game->mlx, game->win,
				game->empty_img, game->x_empty, game->y_empty);
			j++;
		}
		i++;
	}
}

void	put_images(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			game->x_map = j * 80;
			game->y_map = i * 80;
			map_set(game, i, j);
			j++;
		}
		i++;
	}
}

void	map_set(t_game *game, int i, int j)
{
	if (game->mat[i][j] == '\n')
		i++;
	if (game->mat[i][j] == 'P')
		draw_player(game);
	if (game->mat[i][j] == '1')
		draw_wall(game);
	if (game->mat[i][j] == 'C')
		draw_collectible(game);
	if (game->mat[i][j] == 'E')
		draw_exit(game);
}
