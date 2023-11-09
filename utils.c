/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:51:19 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/15 14:53:06 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_img_null(t_data *data)
{
	data->img_init = NULL;
	data->img_p = NULL;
	data->img_p1 = NULL;
	data->img_pub = NULL;
	data->img_wh = NULL;
	data->img_coll = NULL;
	data->img_exit = NULL;
	data->img_grr = NULL;
	data->img_grr2 = NULL;
	data->img_p2 = NULL;
	data->img_p3 = NULL;
	data->img_p4 = NULL;
	data->img_pub1 = NULL;
	data->img_pub2 = NULL;
	data->music = 0;
	data->img_width = 120;
	data->img_length = 100;
	data->sprite_perso = 0;
	data->sprite_wall = 0;
	data->img_pub1 = NULL;
	data->img_pub2 = NULL;
	data->sprite_exit = 0;
	data->o = 0;
	data->count_foot = 0;
}

void	ft_mess_sh(t_data *data)
{
	ft_putstr_fd("nombre de pas : ", 1);
	ft_putnbr_fd(data->count_foot, 1);
	write(1, "\n", 1);
}

void	ft_mess(t_data *data)
{
	char	*s;
	char	*result;

	s = ft_itoa(data->count_foot);
	if (!s)
		return ;
	result = ft_strjoin("nombre de pas :", s);
	free (s);
	if (!result)
		return ;
	mlx_string_put(data->mlx, data->win, 10, 10, 0x6f1f70, result);
	free (result);
	result = NULL;
}
