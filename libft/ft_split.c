/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:10:18 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/08 17:01:25 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_check(char c, char set)
{
	if (c == set || c == '\0')
		return (1);
	return (0);
}

static int	ft_countword(char const *str, char set)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (ft_check(str[i], set) == 0 && ft_check(str[i + 1], set) == 1)
			k++;
		i++;
	}
	return (k);
}

static size_t	ft_countchar(char const *str, char set)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (ft_check(str[i], set) == 1 && str[i])
		i++;
	while (ft_check(str[i], set) == 0 && str[i])
	{
		i++;
		k++;
	}
	return (k);
}

static void	ft_clean(char **result, int nw)
{
	while (nw >= 0)
	{
		free(result[nw]);
		nw--;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		nw;
	char	**result;

	i = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	nw = 0;
	while (nw < ft_countword(s, c))
	{
		while (ft_check(s[i], c))
			i++;
		result[nw] = ft_substr(s, i, ft_countchar(s + i, c));
		if (!result[nw++])
		{
			ft_clean(result, nw);
			return (NULL);
		}
		i = i + ft_countchar(s + i, c);
	}
	result[nw] = NULL;
	return (result);
}

/*
int	main(void)
{
	char	**result;
	int		wd;
	char	*str;
	char	set;

	wd = 0;
	str = " lorem ipsum blq bla blabla bil";
	set = ' ';
//	printf("nombre de mots : %d\n", ft_countword(str, set));
	//	printf("ft_strncpy : %s\n", ft_strncpy(*result, str, 18));
	result = ft_split(str, set);
//	while (result[wd])
//	{
//		printf("%s\n", result[wd]);
////		free(result[wd]);
//		wd++;
//	}
//	free(result);
}*/
