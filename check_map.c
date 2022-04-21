/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:24:47 by aait-mas          #+#    #+#             */
/*   Updated: 2022/04/20 00:54:36 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char **argv)
{
	char	*s;

	s = ft_strrchr(argv[1], '.');
	if (!s)
		return (1);
	if (ft_strncmp(".ber", s, 5))
		return (1);
	return (0);
}

int	map_height_width(char **argv, t_game *map)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	map->height = 0;
	str = get_next_line(fd);
	map->width = ft_strlen(str) - 1;
	while (str)
	{
		map->height += 1;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (0);
}

int	map_checker(char **argv, t_game *map)
{
	int		fd;
	char	*str;
	int		i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	if (map->height <= 1 || fd < 0)
		return (1);
	while (i <= map->height)
	{
		str = get_next_line(fd);
		if (i == map->height)
		{
			if (str[map->width - 1] != '1' || ft_strlen(str) != (map->width))
				return (1);
		}
		else
			if (ft_strlen(str) != (map->width + 1))
				return (1);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}

int	check_borders(char *str, t_game *map)
{
	if (str[0] != '1')
		return (1);
	if (str[map->width - 1] != '1')
		return (1);
	return (0);
}
