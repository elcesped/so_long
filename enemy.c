/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:09:43 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/14 19:14:55 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_enemy_0(t_data *data, int x, int y)
{
	int	i;
	int	j;

	if (data->o == 0)
		i = 1;
	else
		i = -1;
	if (i == 1)
		j = -1;
	else
		j = 1;
	if (data->map[y][x] == 'Y' && (data->map[y][x + i] == '0'
		|| data->map[y + j][x] == '0'))
	{
		data->map[y][x] = '0';
		if (data->map[y][x + i] == '0')
			data->map[y][x++ + i] = 'Y';
		else if (data->map[y + j][x] == '0')
		{
			data->map[y + j][x] = 'Y';
			if (j == 1)
				data->map[y + j][x] = 'S';
		}
	}
	return (x);
}

void	ft_move_enemy(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!data->map)
		return ;
	while (y < data->lin_y && x < data->col_x && data->count_foot % 5 == 0)
	{
		if (data->map[y][x] == 'S')
		{	
			data->map[y][x] = 'Y';
			x++;
		}
		x = ft_move_enemy_0(data, x, y) + 1;
		if (x == data->col_x)
		{
			x = 0;
			y++;
		}
	}
	if (data->o == 0)
		data->o = 1;
	else
		data->o = 0;
}
