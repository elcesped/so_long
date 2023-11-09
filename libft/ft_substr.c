/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:23:17 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/08 17:01:40 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	diff;
	size_t	tot;
	char	*str;

	str = NULL;
	tot = 0;
	if (!s)
		return (NULL);
	diff = ft_strlen(s) - start;
	if (len == 0 || start > ft_strlen(s))
		tot = 0;
	else if (diff < len)
		tot = diff;
	else if (diff >= len)
		tot = len;
	str = (char *)ft_calloc((tot + 1), sizeof(char));
	if (tot > 0 && str)
		ft_memcpy((void *)str, (const void *)(s + start), tot);
	return (str);
}
