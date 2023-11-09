/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:21:00 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/08 17:01:36 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!big && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (little[j] == '\0')
			return ((char *)(big + i));
		else if (little[j] == big[j + i] && i + j < len)
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	return (0);
}
