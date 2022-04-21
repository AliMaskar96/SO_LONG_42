/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:38:05 by aait-mas          #+#    #+#             */
/*   Updated: 2022/03/14 14:07:30 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*pt;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	pt = (char *)malloc(sizeof(char) * i + 1);
	if (pt == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		pt[i] = s1[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*pt;

	i = 0;
	j = (size_t)start;
	if (!s)
		return (NULL);
	while (s[j] != '\0')
		j++;
	if ((int )start > ft_strlen(s))
		pt = malloc(sizeof(char));
	else if (j < len)
		pt = malloc(sizeof(char) * j + 1);
	else
		pt = malloc(sizeof(char) * len + 1);
	if (!pt)
		return (NULL);
	while (s[start] != '\0' && i < len && start < j)
		pt[i++] = s[start++];
	pt[i] = '\0';
	return (pt);
}

int	ft_strchr( char *s, int c)
{
	int		j;
	char	cs;

	j = 0;
	cs = (char )c;
	if (cs == '\0')
	{
		while (s[j])
			j++;
		return (j);
	}
	while (s[j])
	{
		if (s[j] == cs)
			return (j);
		j++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*pt;
	char	*str1;
	char	*str2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str1 = s1;
	str2 = s2;
	if (!str1 && str2)
		return (ft_strdup(str2));
	pt = malloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (pt == NULL)
		return (NULL);
	while (str1[i])
	{
		pt[i] = str1[i];
		i++;
	}
	while (str2[j])
		pt[i++] = str2[j++];
	pt[i] = '\0';
	free(s1);
	return (pt);
}
