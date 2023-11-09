/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:54:44 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/14 14:41:58 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_img2(t_data *data)
{
	if (data->img_p)
		mlx_destroy_image(data->mlx, data->img_p);
	if (data->img_p1)
		mlx_destroy_image(data->mlx, data->img_p1);
	if (data->img_p2)
		mlx_destroy_image(data->mlx, data->img_p2);
	if (data->img_p3)
		mlx_destroy_image(data->mlx, data->img_p3);
	if (data->img_p4)
		mlx_destroy_image(data->mlx, data->img_p4);
}

void	ft_close_img(t_data *data)
{
	if (data->img_init)
		mlx_destroy_image(data->mlx, data->img_init);
	if (data->img_pub)
		mlx_destroy_image(data->mlx, data->img_pub);
	if (data->img_wh)
		mlx_destroy_image(data->mlx, data->img_wh);
	if (data->img_coll)
		mlx_destroy_image(data->mlx, data->img_coll);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->img_grr)
		mlx_destroy_image(data->mlx, data->img_grr);
	if (data->img_grr2)
		mlx_destroy_image(data->mlx, data->img_grr2);
	if (data->img_pub1)
		mlx_destroy_image(data->mlx, data->img_pub1);
	if (data->img_pub2)
		mlx_destroy_image(data->mlx, data->img_pub2);
	if (data->img_exit1)
		mlx_destroy_image(data->mlx, data->img_exit1);
	if (data->img_exit2)
		mlx_destroy_image(data->mlx, data->img_exit2);
	ft_close_img2(data);
}

int	ft_close(t_data *data)
{
	ft_close_img(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_clean_sl(data->map);
	exit (0);
	return (0);
}

void	ft_clean_sl(char **result)
{
	int	nw;

	nw = 0;
	while (result[nw])
	{
		free(result[nw]);
		nw++;
	}
	free(result);
}

char	*ft_clean_gnl(char *line, char *result, int fd)
{
	while (line != NULL)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	free (result);
	result = NULL;
	return (result);
}
