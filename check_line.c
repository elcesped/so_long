/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:07:11 by elcesped          #+#    #+#             */
/*   Updated: 2023/09/15 15:23:11 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//check si le format de la map est ok (trop petite/grande/rectangulaire)
int	ft_check_line(char *result, char *line, t_data *data)
{
	int	j;
	int	k;

	if (!result || !line || !data)
		return (-1);
	j = ft_strlen(result);
	k = ft_strlen(line);
	if (line[k - 1] != '\n')
		k = k + 1;
	data->col_x = k - 1;
	if (j < 3 || k < 3)
	{
		ft_putstr_fd("Error\nYou need too talk to us please, or your", 2);
		ft_putstr_fd(" map is too little or you add stuffs in some line\n", 2);
		return (-1);
	}
	if (j % k != 0)
	{
		ft_putstr_fd("Error\nNAN MAIS WTF C PAS UN KARE\n", 2);
		return (-1);
	}
	else
		return (1);
}

char	*ft_check_gnl(char *result, char *line, t_data *data, int fd)
{
	char	*temp;
	int		i;

	temp = NULL;
	while (1)
	{
		if (!result)
			result = get_next_line(fd);
		if (!line)
			line = get_next_line(fd);
		i = ft_check_line(result, line, data);
		if (line == NULL || result == NULL || i < 0)
		{
			if (result == NULL)
				ft_putstr_fd("Error\nEMPTYY Y A R\n", 2);
			else if (result && line && i < 0)
				result = ft_clean_gnl(line, result, fd);
			break ;
		}
		temp = result;
		result = ft_strjoin(result, line);
		(free(temp), free(line));
		line = NULL;
	}
	return (result);
}

//check le nbre de lignes + sort la map avec gnl
char	*ft_ber_on_line(int fd, t_data *data)
{
	char	*line;
	char	*result;

	result = NULL;
	line = NULL;
	result = ft_check_gnl(result, line, data, fd);
	if (result && result[strlen(result) - 1] == '\n')
	{
		free(result);
		result = NULL;
		ft_putstr_fd("Error\nTrop de lignes tue la ligne\n", 2);
	}
	return (result);
}

//check les elements a collecter la sortie et la position perso
int	ft_check_el_online(char *result, t_data *data)
{
	int	perso;
	int	exit;
	int	i;

	data->to_collect = 0;
	perso = 0;
	exit = 0;
	i = 0;
	while (result[i] != '\0')
	{
		if (result[i] == 'P')
			perso++;
		else if (result[i] == 'E')
			exit++;
		else if (result[i] == 'C')
			data->to_collect++;
		else if (result[i] != '1' && result[i] != '0'
			&& result[i] != '\n' && result[i] != 'Y')
			return (-1);
		i++;
	}
	if (perso == 1 && exit == 1 && data->to_collect >= 1)
		return (data->to_collect);
	return (-1);
}

int	ft_check_frontier(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j] != '\0')
		{
			if ((i == 0 && data->map[i][j] != '1')
				|| (j == 0 && data->map[i][j] != '1'))
				return (-1);
			j++;
		}
		if (data->map[i++][j - 1] != '1')
			return (-1);
		j = 0;
	}
	while (data->map[i - 1][j] != '\0')
	{
		if (data->map[i - 1][j++] != '1')
			return (-1);
	}
	data->lin_y = i;
	return (1);
}
