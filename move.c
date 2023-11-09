/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:47:49 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/14 19:10:09 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_touch(int keycode, t_data *data)
{
	int	x;
	int	y;

	ft_check_where_is_p(data);
	x = data->play_x;
	y = data->play_y;
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		ft_move_enemy(data);
	if (keycode == XK_Escape)
		ft_close(data);
	if (keycode == 119)
		ft_move_up(data, x, y);
	if (keycode == 115)
		ft_move_down(data, x, y);
	if (keycode == 97)
		ft_move_left(data, x, y);
	if (keycode == 100)
		ft_move_right(data, x, y);
	return (0);
}

void	ft_move_up(t_data *data, int x, int y)
{
	data->count_foot++;
	ft_mess_sh(data);
	if ((data->map[x - 1][y] == 'E' && data->to_collect == 0)
			|| data->map[x - 1][y] == 'Y')
	{
		if (data->map[x - 1][y] == 'E' && data->to_collect == 0)
			ft_putstr_fd("OLALALA LALALI LALALA ! You won !\n", 1);
		if (data->map[x - 1][y] == 'Y')
			ft_putstr_fd("OH NOOOO! THE OTHER SINGER ATE YOU :( LOOOOSER\n", 1);
		ft_close(data);
	}
	else if (data->map[x - 1][y] == '0' || data->map[x - 1][y] == 'C')
	{
		if (data->map[x - 1][y] == 'C')
		{
			ft_putstr_fd("Wow ! You are a good singer :)\n", 1);
			data->to_collect--;
			data->music++;
			if (data->to_collect == 0)
				ft_putstr_fd("YOU ARE READY TO PLAYY ON OUR GROUP YIHAAAA\n", 1);
		}
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'P';
	}
	ft_img_on_tab(data);
}

void	ft_move_down(t_data *data, int x, int y)
{
	data->count_foot++;
	ft_mess_sh(data);
	if ((data->map[x + 1][y] == 'E' && data->to_collect == 0)
			|| data->map[x + 1][y] == 'Y')
	{
		if (data->map[x + 1][y] == 'E' && data->to_collect == 0)
			ft_putstr_fd("OLALALA LALALI LALALA ! You won !\n", 1);
		if (data->map[x + 1][y] == 'Y')
			ft_putstr_fd("OH NOOOO! THE OTHER SINGER ATE YOU :( LOOOOSER\n", 1);
		ft_close(data);
	}
	else if (data->map[x + 1][y] == '0' || data->map[x + 1][y] == 'C')
	{
		if (data->map[x + 1][y] == 'C')
		{
			ft_putstr_fd("Wow ! You are a good singer :)\n", 1);
			data->to_collect--;
			data->music++;
			if (data->to_collect == 0)
				ft_putstr_fd("YOU ARE READY TO PLAYY ON OUR GROUP YIHAAAA\n", 1);
		}
	data->map[x][y] = '0';
	data->map[x + 1][y] = 'P';
	}
	ft_img_on_tab(data);
}

void	ft_move_left(t_data *data, int x, int y)
{
	data->count_foot++;
	ft_mess_sh(data);
	if ((data->map[x][y - 1] == 'E' && data->to_collect == 0)
			|| data->map[x][y - 1] == 'Y')
	{
		if (data->map[x][y - 1] == 'E' && data->to_collect == 0)
			ft_putstr_fd("OLALALA LALALI LALALA ! You won !\n", 1);
		if (data->map[x][y - 1] == 'Y')
			ft_putstr_fd("OH NOOOO! THE OTHER SINGER ATE YOU :( LOOOOSER\n", 1);
		ft_close(data);
	}
	else if (data->map[x][y - 1] == '0' || data->map[x][y - 1] == 'C')
	{
		if (data->map[x][y - 1] == 'C')
		{
			ft_putstr_fd("Wow ! You are a good singer :)\n", 1);
			data->to_collect--;
			data->music++;
			if (data->to_collect == 0)
				ft_putstr_fd("YOU ARE READY TO PLAYY ON OUR GROUP YIHAAAA\n", 1);
		}
	data->map[x][y] = '0';
	data->map[x][y - 1] = 'P';
	}
	ft_img_on_tab(data);
}

void	ft_move_right(t_data *data, int x, int y)
{
	data->count_foot++;
	ft_mess_sh(data);
	if ((data->map[x][y + 1] == 'E' && data->to_collect == 0)
			|| data->map[x][y + 1] == 'Y')
	{
		if (data->map[x][y + 1] == 'E' && data->to_collect == 0)
			ft_putstr_fd("OLALALA LALALI LALALA ! You won !\n", 1);
		if (data->map[x][y + 1] == 'Y')
			ft_putstr_fd("OH NOOOO! THE OTHER SINGER ATE YOU :( LOOOOSER\n", 1);
		ft_close(data);
	}
	else if (data->map[x][y + 1] == '0' || data->map[x][y + 1] == 'C')
	{
		if (data->map[x][y + 1] == 'C')
		{
			ft_putstr_fd("Wow ! You are a good singer :)\n", 1);
			data->to_collect--;
			data->music++;
			if (data->to_collect == 0)
				ft_putstr_fd("YOU ARE READY TO PLAYY ON OUR GROUP YIHAAAA\n", 1);
		}
	data->map[x][y] = '0';
	data->map[x][y + 1] = 'P';
	}
	ft_img_on_tab(data);
}
