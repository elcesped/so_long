/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:02:47 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/14 16:36:22 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_load_img_wall_grr(t_data	*data)
{
	data->img_pub = mlx_xpm_file_to_image(data->mlx, "./Banque_img/public.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_pub)
		return (NULL);
	data->img_pub1 = mlx_xpm_file_to_image(data->mlx, "./Banque_img/pub_2n.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_pub1)
		return (NULL);
	data->img_pub2 = mlx_xpm_file_to_image(data->mlx, "./Banque_img/pub_1.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_pub2)
		return (NULL);
	data->img_grr = mlx_xpm_file_to_image(data->mlx, "./Banque_img/grr.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_grr)
		return (NULL);
	data->img_grr2 = mlx_xpm_file_to_image(data->mlx, "./Banque_img/grr2.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_grr2)
		return (NULL);
	return (data->img_pub);
}

void	*ft_load_img_perso(t_data *data)
{
	data->img_p = mlx_xpm_file_to_image(data->mlx, "./Banque_img/p.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_p)
		return (NULL);
	data->img_p1 = mlx_xpm_file_to_image(data->mlx, "./Banque_img/p1.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_p1)
		return (NULL);
	data->img_p3 = mlx_xpm_file_to_image(data->mlx, "./Banque_img/p2.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_p3)
		return (NULL);
	data->img_p4 = mlx_xpm_file_to_image(data->mlx, "./Banque_img/p3.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_p4)
		return (NULL);
	data->img_p2 = mlx_xpm_file_to_image(data->mlx, "./Banque_img/chanter.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_p2)
		return (NULL);
	return (data->img_p);
}

void	*ft_load_img(t_data *data)
{
	data->img_wh = mlx_xpm_file_to_image(data->mlx, "./Banque_img/sol.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_wh)
		return (NULL);
	data->img_coll = mlx_xpm_file_to_image(data->mlx, "./Banque_img/note.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_coll)
		return (NULL);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "./Banque_img/crew0.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_exit)
		return (NULL);
	data->img_exit2 = mlx_xpm_file_to_image(data->mlx, "./Banque_img/crew2.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_exit2)
		return (NULL);
	data->img_exit1 = mlx_xpm_file_to_image(data->mlx, "./Banque_img/crew1.xpm",
			&data->img_width, &data->img_length);
	if (!data->img_exit1)
		return (NULL);
	if (ft_load_img_wall_grr(data) == NULL || ft_load_img_perso(data) == NULL)
		return (NULL);
	return (data->img_grr);
}

void	ft_parsing_img(t_data *data, char datac, size_t lon, size_t lar)
{
	if (datac == '1')
		ft_sprite_wall(data, lon, lar);
	else if (datac == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_wh, lon, lar);
	else if (datac == 'P')
		ft_sprite_perso(data, lon, lar);
	else if (datac == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img_coll, lon, lar);
	else if (datac == 'E')
		ft_sprite_exit(data, lon, lar);
	else if (datac == 'Y')
		ft_sprite_ennemy(data, lon, lar);
	ft_mess(data);
}

void	ft_img_on_tab(t_data *data)
{
	int		i;
	int		j;
	size_t	lon;
	size_t	lar;

	lon = 0;
	lar = 0;
	i = 0;
	j = 0;
	while (i < data->lin_y && j < data->col_x)
	{
		ft_parsing_img(data, data->map[i][j], lon, lar);
		lon = lon + 120;
		j++;
		if (data->map[i][j] == '\0')
		{
			i++;
			j = 0;
			lar = lar + 100;
			lon = 0;
		}
	}
}

//verifier si les longueurs sont les memes ?
//multiplier par l indice pour trouver ou placer l image