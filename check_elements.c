/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:21:48 by aait-mas          #+#    #+#             */
/*   Updated: 2022/04/12 01:07:51 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_elements(char **argv, t_game *map)
{
	char	*str;
	int		fd;
	int		i;
	int		j;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while (i < map->height)
	{
		str = get_next_line(fd);
		j = 0;
		while (str[j])
		{
			if (str[j] != '0' && str[j] != '1' && str[j] != 'C'
				&& str[j] != 'E' && str[j] != 'P' && str[j] != '\n')
				return (1);
			j++;
		}
		free(str);
		i++;
	}
	close(fd);
	return (0);
}

int	check_walls(char **argv, t_game *map)
{
	int		fd;
	char	*str;
	int		i;
	int		j;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i < map->height)
	{
		str = get_next_line(fd);
		j = 0;
		if (i == 0 || i == map->height - 1)
		{
			while (str[j] && str[j] != '\n')
				if (str[j++] != '1')
					return (1);
		}
		else
			if (check_borders(str, map) == 1)
				return (1);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}

int	check_player(char **argv, t_game *map)
{
	char	*str;
	int		fd;
	int		i;
	int		j;
	int		count;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	count = 0;
	while (i < map->height)
	{
		str = get_next_line(fd);
		j = 0;
		while (str[j])
		{
			if (str[j] == 'P')
				count++;
			j++;
		}
		free(str);
		i++;
	}
	close(fd);
	return (count);
}

int	check_collectible(char **argv, t_game *map)
{
	char	*str;
	int		fd;
	int		i;
	int		j;
	int		count;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	count = 0;
	while (i < map->height)
	{
		str = get_next_line(fd);
		j = 0;
		while (str[j])
		{
			if (str[j] == 'C')
				count++;
			j++;
		}
		free(str);
		i++;
	}
	close(fd);
	return (count);
}

int	check_exit(char **argv, t_game *map)
{
	char	*str;
	int		fd;
	int		i;
	int		j;
	int		count;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	count = 0;
	while (i < map->height)
	{
		str = get_next_line(fd);
		j = 0;
		while (str[j])
		{
			if (str[j] == 'E')
				count++;
			j++;
		}
		free(str);
		i++;
	}
	close(fd);
	return (count);
}
