/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:21:18 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/08 17:01:09 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;
	size_t	t;

	if (size != 0 && nmemb > sizeof(char) * 2147483424 / size)
		return (NULL);
	t = nmemb * size;
	r = (void *)malloc(sizeof(char) * t);
	if (!r)
		return (NULL);
	ft_bzero(r, t);
	return (r);
}

//	if (nmemb == 0 || size == 0)
//	return (0);
// --> pas necessaire : car on mallocra 0 dans ce cas.