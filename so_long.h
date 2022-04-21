/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:24:59 by aait-mas          #+#    #+#             */
/*   Updated: 2022/04/20 01:25:30 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10

# include "get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		move_count;
	void	*wall_img;
	void	*right_player_img;
	void	*left_player_img;
	void	*player_img;
	void	*collectible_img;
	void	*flag_down_img;
	void	*flag_up_img;
	void	*empty_img;
	int		w_xml;
	int		h_xml;
	char	**mat;
	int		x_map;
	int		y_map;
	int		x_empty;
	int		y_empty;
}				t_game;

int		map_height_width(char **argv, t_game *map);
int		map_checker(char **argv, t_game *map);
int		check_walls(char **argv, t_game *map);
int		check_borders(char *str, t_game *map);
int		check_player(char **argv, t_game *map);
int		check_collectible(char **argv, t_game *map);
int		check_exit(char **argv, t_game *map);
int		check_elements(char **argv, t_game *map);
void	draw_map(t_game *game);
void	draw_wall(t_game *game);
void	draw_collectible(t_game *game);
void	draw_exit(t_game *game);
void	draw_player(t_game *game);
void	empty_set(t_game *game);
void	image_initialization(t_game *game);
void	put_images(t_game *game);
void	map_set(t_game *game, int i, int j);
int		ft_putstr(char *s);
int		key_hook(int keycode, t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	swap_up_down(t_game *game, int i, int j, int s);
void	swap_left_right(t_game *game, int i, int j, int s);
int		count_collectible(t_game *game);
char	*ft_itoa(int n);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_exit(t_game *game);
int		check_extension(char **argv);

//int	animation(t_game *game);

#endif