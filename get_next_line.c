/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:38:13 by aait-mas          #+#    #+#             */
/*   Updated: 2022/03/14 14:07:11 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*malgitch_n(char **s)
{
	char	*temp;

	if (*s != NULL && **s != '\0')
	{
		temp = *s;
		*s = NULL;
		return (temp);
	}
	else
	{
		free(*s);
		*s = NULL;
		return (NULL);
	}
}

char	*lgit_n(char **s)
{
	char	*line;
	int		i;
	char	*temp;

	i = ft_strchr(*s, '\n');
	line = ft_substr(*s, 0, i + 1);
	temp = *s;
	*s = ft_substr(*s, i + 1, (ft_strlen(*s) - i));
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	int			nbro;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str == NULL)
	{
		str = ft_strdup("");
		if (!str)
			return (NULL);
	}
	while (ft_strchr(str, '\n') == -1)
	{
		nbro = read(fd, buffer, BUFFER_SIZE);
		if (nbro == 0 || nbro == -1)
			break ;
		buffer[nbro] = '\0';
		str = ft_strjoin(str, buffer);
	}
	if (ft_strchr(str, '\n') == -1)
		return (malgitch_n(&str));
	return (lgit_n(&str));
}
