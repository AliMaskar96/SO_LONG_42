/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:14 by aait-mas          #+#    #+#             */
/*   Updated: 2022/04/20 01:44:39 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->wall_img, game->x_map, game->y_map + 30);
}

void	draw_collectible(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->collectible_img, game->x_map, game->y_map + 30);
}

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_img, game->x_map, game->y_map + 30);
}

void	draw_exit(t_game *game)
{
	if (count_collectible(game) == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->flag_up_img, game->x_map, game->y_map + 30);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->flag_down_img, game->x_map, game->y_map + 30);
}
