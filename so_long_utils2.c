/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:23:01 by aait-mas          #+#    #+#             */
/*   Updated: 2022/04/04 17:20:13 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static long long	ft_abs(int n)
{
	long long	nbr;

	nbr = (long long)n;
	if (nbr < 0)
		return (nbr * (-1));
	return (nbr);
}

static long long	countnumber(int n)
{
	int			i;
	long long	nbr;

	nbr = (long long)n;
	i = 0;
	if (n < 0)
		i++;
	nbr = ft_abs(nbr);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	len;
	long long	i;
	long long	nbr;
	char		*new;

	i = 0;
	len = countnumber(n);
	nbr = (long long)n;
	if (nbr == 0)
		return (ft_strdup("0"));
	new = (char *)malloc(sizeof(char) * (len) + 1);
	if (!new)
		return (NULL);
	if (nbr < 0)
		new[0] = '-';
	nbr = ft_abs(nbr);
	while (++i <= len)
	{
		if (new[len - i] != '-')
			new[len - i] = (nbr % 10) + '0';
			nbr /= 10;
	}
	new[len] = '\0';
	return (new);
}
