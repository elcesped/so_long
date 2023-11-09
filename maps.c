/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:25:03 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/15 15:28:40 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_where_is_p(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i][j] != 'P')
	{
		j++;
		if (data->map[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	data->play_x = i;
	data->play_y = j;
}

void	*ft_check_map(t_data *data)
{
	int	i;

	i = ft_check_frontier(data);
	if (i < 0)
	{
		ft_putstr_fd("Error\nWE'RE FREE THE WALL HAS FALLEN\n", 2);
		ft_clean_sl(data->map);
		ft_clean_sl(data->check_map);
		return (NULL);
	}
	ft_ok_to_go_out(data);
	if (data->count_exit != 0 || data->check_collect != 0)
	{
		ft_putstr_fd("Error\nOH NAAAAN I CAN T PLAY WITH MY TEAM :(\n", 2);
		ft_clean_sl(data->map);
		ft_clean_sl(data->check_map);
		return (NULL);
	}
	ft_clean_sl(data->check_map);
	return (data->map);
}

//check les frontieres / mur + element + cree la map.
char	**ft_map_on_tab(int fd, t_data *data)
{
	char	*result;

	result = ft_ber_on_line(fd, data);
	if (!result)
		return (NULL);
	if (ft_check_el_online(result, data) <= 0)
	{
		ft_putstr_fd("Error\nWTF WE NEED MORE/LESS STUFFS ON THIS CARD\n", 2);
		return (free(result), NULL);
	}
	data->map = ft_split(result, '\n');
	data->check_map = ft_split(result, '\n');
	if (!data->map || !data->check_map)
	{
		if (data->map)
			ft_clean_sl(data->map);
		if (data->check_map)
			ft_clean_sl(data->check_map);
		return (NULL);
	}
	free (result);
	data->map = ft_check_map(data);
	if (data->map == NULL)
		return (NULL);
	return (data->map);
}

void	ft_ok_to_go_out(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	ft_check_where_is_p(data);
	x = data->play_x;
	y = data->play_y;
	data->check_collect = data->to_collect;
	data->count_exit = 1;
	map = data->map;
	ft_fill_map(data->check_map, data, x, y);
}

void	ft_fill_map(char **map, t_data *data, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'E'
		|| map[x][y] == 'F' || map[x][y] == 'Y')
	{
		if (map[x][y] == 'E')
			data->count_exit = 0;
		return ;
	}
	if (map[x][y] == 'C')
		data->check_collect--;
	map[x][y] = 'F';
	ft_fill_map(map, data, x - 1, y);
	ft_fill_map(map, data, x, y + 1);
	ft_fill_map(map, data, x + 1, y);
	ft_fill_map(map, data, x, y - 1);
}
