/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:22:20 by aait-mas          #+#    #+#             */
/*   Updated: 2022/04/20 01:51:50 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_initialization(t_game *game)
{
	game->move_count = 0;
	game->empty_img = mlx_xpm_file_to_image(game->mlx,
			"./pictures/empty.xpm", &game->w_xml, &game->h_xml);
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"./pictures/bricks.xpm", &game->w_xml, &game->h_xml);
	game->right_player_img = mlx_xpm_file_to_image(game->mlx,
			"./pictures/right_player.xpm", &game->w_xml, &game->h_xml);
	game->left_player_img = mlx_xpm_file_to_image(game->mlx,
			"./pictures/left_player.xpm", &game->w_xml, &game->h_xml);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"./pictures/collectible.xpm", &game->w_xml, &game->h_xml);
	game->flag_down_img = mlx_xpm_file_to_image(game->mlx,
			"./pictures/flag_down.xpm", &game->w_xml, &game->h_xml);
	game->flag_up_img = mlx_xpm_file_to_image(game->mlx,
			"./pictures/flag_up.xpm", &game->w_xml, &game->h_xml);
	game->player_img = game->right_player_img;
}
