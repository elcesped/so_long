/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:35:47 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/15 14:08:01 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sprite_perso(t_data *data, int lon, int lar)
{
	int	i;

	i = 1;
	if (data->lin_y * data->col_x < 150)
		i = 2;
	if (data->lin_y * data->col_x < 100)
		i = 4;
	if (data->sprite_perso < 50 * i)
		mlx_put_image_to_window(data->mlx, data->win, data->img_p, lon, lar);
	else if (data->sprite_perso < 100 * i && data->sprite_perso >= 50 * i
		&& data->music >= 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img_p1, lon, lar);
	else if (data->sprite_perso < 150 * i && data->sprite_perso >= 100 * i
		&& data->music >= 2)
		mlx_put_image_to_window(data->mlx, data->win, data->img_p2, lon, lar);
	else if (data->sprite_perso < 200 * i && data->sprite_perso >= 150 * i
		&& data->music >= 3)
		mlx_put_image_to_window(data->mlx, data->win, data->img_p3, lon, lar);
	else if (data->sprite_perso < 250 * i && data->sprite_perso >= 200 * i
		&& data->music >= 4)
		mlx_put_image_to_window(data->mlx, data->win, data->img_p4, lon, lar);
	else
		data->sprite_perso = 0;
}

void	ft_sprite_ennemy(t_data	*data, int lon, int lar)
{
	int	i;

	i = 1;
	if (data->lin_y * data->col_x < 150)
		i = 2;
	if (data->lin_y * data->col_x < 100)
		i = 4;
	if (data->sprite_perso < 100 * i)
		mlx_put_image_to_window(data->mlx, data->win, data->img_grr2, lon, lar);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img_grr, lon, lar);
}

void	ft_sprite_wall(t_data *data, int lon, int lar)
{
	int	i;

	i = 1;
	if (data->lin_y * data->col_x < 150)
		i = 2;
	if (data->lin_y * data->col_x < 100)
		i = 4;
	if (data->sprite_wall < 200 * i)
		mlx_put_image_to_window(data->mlx, data->win, data->img_pub, lon, lar);
	else if (data->sprite_wall < 250 * i && data->sprite_wall >= 200 * i
		&& data->music >= 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img_pub1, lon, lar);
	else if (data->sprite_wall < 300 * i && data->sprite_wall >= 250 * i
		&& data->music >= 2)
		mlx_put_image_to_window(data->mlx, data->win, data->img_pub2, lon, lar);
	else
		data->sprite_wall = 0;
}

void	ft_sprite_exit(t_data *data, int lon, int lar)
{
	int	i;

	i = 1;
	if (data->lin_y * data->col_x < 150)
		i = 2;
	if (data->lin_y * data->col_x < 100)
		i = 4;
	if (data->to_collect != 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img_exit, lon, lar);
	else if (data->to_collect == 0 && data->sprite_exit < 75 * i)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img_exit1, lon, lar);
	else if (data->to_collect == 0 && data->sprite_exit < 150 * i
		&& data->sprite_exit >= 75 * i)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img_exit2, lon, lar);
	else
		data->sprite_exit = 0;
}
