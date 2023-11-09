/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:55:14 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/15 15:00:42 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <mlx_int.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_data
{
	void	*img_init;
	void	*mlx;
	void	*win;
	char	*addr;
	int		pixel_bits;
	int		line_length;
	int		endian;
	char	**map;
	char	**check_map;
	void	*img_wh;
	void	*img_pub;
	void	*img_pub1;
	void	*img_pub2;
	void	*img_p;
	void	*img_coll;
	void	*img_exit;
	void	*img_exit1;
	void	*img_exit2;
	void	*img_grr;
	void	*img_grr2;
	int		img_width;
	int		img_length;
	void	*img_p1;
	void	*img_p2;
	void	*img_p3;
	void	*img_p4;

	char	*relative_path_pub;
	char	*relative_path_wh;

	int		play_x;
	int		play_y;

	int		col_x;
	int		lin_y;

	int		to_collect;
	int		music;

	int		count_exit;
	int		check_collect;

	int		count_foot;

	int		sprite_perso;
	int		sprite_wall;
	int		sprite_exit;

	int		o;
}				t_data;

//so_long.c
int		ft_mlx_skills(t_data data);
void	ft_mlx_skills2(t_data data);
int		ft_check_arg(char *argv, int fd);
int		handle_map(t_data *data);

//maps.c
void	ft_check_where_is_p(t_data *data);
void	*ft_check_map(t_data *data);
char	**ft_map_on_tab(int fd, t_data *data);
void	ft_ok_to_go_out(t_data *data);
void	ft_fill_map(char **map, t_data *data, int x, int y);

//check_line.c
int		ft_check_line(char *result, char *line, t_data *data);
char	*ft_check_gnl(char *result, char *line, t_data *data, int fd);
char	*ft_ber_on_line(int fd, t_data *data);
int		ft_check_el_online(char *result, t_data *data);
int		ft_check_frontier(t_data *data);

//move.c
int		ft_touch(int keycode, t_data *data);
void	ft_move_up(t_data *data, int x, int y);
void	ft_move_down(t_data *data, int x, int y);
void	ft_move_left(t_data *data, int x, int y);
void	ft_move_right(t_data *data, int x, int y);

//clean.c
void	ft_close_img(t_data *data);
void	ft_close_img2(t_data *data);
int		ft_close(t_data *data);
void	ft_clean_sl(char **result);
char	*ft_clean_gnl(char *line, char *result, int fd);

//load_img.c
void	*ft_load_img_perso(t_data	*data);
void	*ft_load_img_wall_grr(t_data *data);
void	*ft_load_img(t_data *data);
void	ft_parsing_img(t_data *data, char datac, size_t lon, size_t lar);
void	ft_img_on_tab(t_data *data);

//sprite.c
void	ft_sprite_perso(t_data *data, int lon, int lar);
void	ft_sprite_ennemy(t_data	*data, int lon, int lar);
void	ft_sprite_wall(t_data *data, int lon, int lar);
void	ft_sprite_exit(t_data *data, int lon, int lar);

//enemy.c
void	ft_move_enemy(t_data *data);
int		ft_move_enemy_0(t_data *data, int x, int y);

//utils.c
void	ft_init_img_null(t_data *data);
void	ft_mess_sh(t_data *data);
void	ft_mess(t_data *data);

#endif
