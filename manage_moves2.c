/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_moves2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:24:38 by aait-mas          #+#    #+#             */
/*   Updated: 2022/04/20 06:11:29 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectible(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			if (game->mat[i][j + 1] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	swap_up_down(t_game *game, int i, int j, int s)
{
	game->mat[i][j] = '0';
	game->mat[s][j] = 'P';
	game->move_count++;
}

void	swap_left_right(t_game *game, int i, int j, int s)
{
	game->mat[i][j] = '0';
	game->mat[i][s] = 'P';
	game->move_count++;
}

void	ft_exit(t_game *game)
{
	game->move_count++;
	ft_putstr(" *** CONGRATULATIONS ... YOU WIN ! *** \n");
	exit(0);
}
