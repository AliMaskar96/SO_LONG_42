/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_moves1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:24:30 by aait-mas          #+#    #+#             */
/*   Updated: 2022/04/20 01:49:58 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53 || keycode < 0)
		exit(0);
	mlx_clear_window(game->mlx, game->win);
	if (keycode == 2 || keycode == 124)
		move_right(game);
	if (keycode == 0 || keycode == 123)
		move_left(game);
	if (keycode == 13 || keycode == 126)
		move_up(game);
	if (keycode == 1 || keycode == 125)
		move_down(game);
	draw_map(game);
	return (0);
}

void	move_right(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player_img = game->right_player_img;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			if (game->mat[i][j] == 'P')
			{
				if (game->mat[i][j + 1] == '0')
					swap_left_right(game, i, j, j + 1);
				else if (game->mat[i][j + 1] == 'C')
					swap_left_right(game, i, j, j + 1);
				else if (game->mat[i][j + 1] == 'E')
					if (count_collectible(game) == 0)
						ft_exit(game);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	move_left(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player_img = game->left_player_img;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			if (game->mat[i][j] == 'P')
			{
				if (game->mat[i][j - 1] == '0')
					swap_left_right(game, i, j, j - 1);
				else if (game->mat[i][j - 1] == 'C')
					swap_left_right(game, i, j, j - 1);
				else if (game->mat[i][j - 1] == 'E')
					if (count_collectible(game) == 0)
						ft_exit(game);
			}
			j++;
		}
		i++;
	}
}

void	move_up(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			if (game->mat[i][j] == 'P')
			{
				if (game->mat[i - 1][j] == '0')
					swap_up_down(game, i, j, i - 1);
				else if (game->mat[i - 1][j] == 'C')
					swap_up_down(game, i, j, i - 1);
				else if (game->mat[i - 1][j] == 'E')
					if (count_collectible(game) == 0)
						ft_exit(game);
			}
			j++;
		}
		i++;
	}
}

void	move_down(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			if (game->mat[i][j] == 'P')
			{
				if (game->mat[i + 1][j] == '0')
					swap_up_down(game, i, j, i + 1);
				else if (game->mat[i + 1][j] == 'C')
					swap_up_down(game, i, j, i + 1);
				else if (game->mat[i + 1][j] == 'E')
					if (count_collectible(game) == 0)
						ft_exit(game);
				i++;
			}
			j++;
		}
		i++;
	}
}
