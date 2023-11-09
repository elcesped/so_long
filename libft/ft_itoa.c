/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:48:44 by elcesped          #+#    #+#             */
/*   Updated: 2023/05/16 13:32:09 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(long n)
{
	int	m;

	m = 1;
	if (n < 0)
		m = -m;
	return (m);
}

static int	ft_ccount(long n)
{
	size_t	i;

	i = 0;
	n = ft_sign(n) * n;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	j;

	j = n;
	i = ft_ccount(j);
	if (ft_sign(j) == -1)
		i++;
	j = j * ft_sign(j);
	s = NULL;
		s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	s[i + 1] = '\0';
	if (j >= 0 && j <= 9)
		s[i] = j + 48;
	while (i >= 0)
	{
		s[i] = (j % 10) + 48;
		j = j / 10;
		if (ft_sign(n) == -1 && i == 0)
			s[i] = '-';
		i--;
	}
	return (s);
}
/*
int	main(void)
{
	int	n;

	n = -2147483648;
	printf("itoa : %s", ft_itoa(n));
	return (0);
}
*/