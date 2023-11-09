/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:13:13 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/08 17:01:28 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	tot;

	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	tot = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(tot, sizeof(char));
	if (!str)
		return (NULL);
	if (str)
	{
		ft_memcpy(str, s1, ft_strlen(s1));
		ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	}
	return (str);
}
