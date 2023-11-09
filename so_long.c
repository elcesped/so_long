/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:54:42 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/15 15:21:16 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//actualise la map + les compteurs si usleep interdit, sinon, usleep
int	handle_map(t_data *data)
{
	ft_img_on_tab(data);
	data->sprite_perso++;
	data->sprite_wall++;
	data->sprite_exit++;
	return (0);
}

int	ft_check_arg(char *argv, int fd)
{
	char	*i;

	if (fd == -1)
	{
		ft_putstr_fd("Error\nWHERE IS THE MAP ?? THIS IS NOT MY MAAAAP : ", 2);
		perror("");
		return (-1);
	}
	i = NULL;
	i = ft_strnstr(argv, ".ber", ft_strlen(argv));
	if (i == 0)
	{
		ft_putstr_fd("Error\nWTFork, Wrong extension snirf snirf\n", 2);
		return (-1);
	}
	return (0);
}

void	ft_mlx_skills2(t_data data)
{
	data.addr = mlx_get_data_addr(data.img_init, &data.pixel_bits,
			&data.line_length, &data.endian);
	if (ft_load_img(&data) == NULL)
	{
		ft_putstr_fd("Error\nI'm BLIND!!, I CANT SEE THE IMAGES\n", 2);
		ft_close(&data);
		return ;
	}
	(ft_img_on_tab(&data), ft_putstr_fd("nombre de pas : ", 1));
	(ft_putnbr_fd(data.count_foot, 1), write(1, "\n", 1));
	mlx_loop_hook(data.mlx, &handle_map, &data);
	mlx_hook(data.win, ClientMessage, NoEventMask, &ft_close, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &ft_touch, &data);
	mlx_loop(data.mlx);
}

int	ft_mlx_skills(t_data data)
{
	int	long_win;
	int	larg_win;
	int	screen_w;
	int	screen_h;

	long_win = data.img_width * data.col_x;
	larg_win = data.img_length * data.lin_y;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (-1);
	mlx_get_screen_size(data.mlx, &screen_w, &screen_h);
	if (long_win > screen_w || larg_win > screen_h)
	{
		free (data.mlx);
		ft_putstr_fd("Error\nYour map is bigger than my screen\n", 2);
		return (-1);
	}
	data.win = mlx_new_window(data.mlx, long_win, larg_win, "LALILA LALALA");
	if (!data.win)
		return (-1);
	data.img_init = mlx_new_image(data.mlx, long_win, larg_win);
	ft_mlx_skills2(data);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_data	data;

	if (argc == 2)
	{
		fd = 0;
		fd = open(argv[1], fd);
		if (ft_check_arg(argv[1], fd) == -1)
			return (0);
	}
	else
	{
		ft_putstr_fd("Error\nNo Card Or Too Much Card\n", 2);
		return (0);
	}
	i = 0;
	ft_init_img_null(&data);
	data.map = ft_map_on_tab(fd, &data);
	if (data.map == NULL)
		return (0);
	ft_mlx_skills(data);
	return (0);
}
