/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-06 13:52:11 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-06 13:52:11 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

static int	fill_var(char **element, t_game *game)
{
	if (ft_strcmp(element[0], "R") == 0)
	{
		if (fill_resolution(element, game) == -1)
			return (-1);
	}
	else if (ft_strcmp(element[0], "NO") == 0)
	{
		if (fill_north(element, game) == -1)
			return (-1);
	}
	else if (ft_strcmp(element[0], "SO") == 0)
	{
		if (fill_south(element, game) == -1)
			return (-1);
	}
	else if (ft_strcmp(element[0], "WE") == 0)
	{
		if (fill_west(element, game) == -1)
			return (-1);
	}
	else if (ft_strcmp(element[0], "EA") == 0)
	{
		if (fill_east(element, game) == -1)
			return (-1);
	}
	else if (ft_strcmp(element[0], "S") == 0)
	{
		if (fill_sprite(element, game) == -1)
			return (-1);
	}
		else if (ft_strcmp(element[0], "F") == 0)
	{
		if (fill_floor(element, game) == -1)
			return (-1);
	}
		else if (ft_strcmp(element[0], "C") == 0)
	{
		if (fill_ceilling(element, game) == -1)
			return (-1);
	}
	return (0);
}

static int	is_filled(t_game *game)
{
	if ((game->R_x == -1) || (game->R_y == -1)
		|| (game->NO == 0) || (game->SO == 0)
		|| (game->WE == 0) || (game->EA == 0)
		|| (game->S == 0) || (game->F_R == -1)
		|| (game->F_G == -1) || (game->F_B == -1)
		|| (game->C_R == -1) || (game->C_G == -1)
		|| (game->C_B == -1))
		return (-1);
	return (0);
}

static int	check_and_fill_var(char *line, t_game *game)
{
	int	flag;
	char	**element;

	flag = is_filled(game);
	if (line[0] == '1' && flag == 0)
		return (1);
	element = ft_split(line, ' ');
	if (ft_strcmp(element[0], "R") == 0 || ft_strcmp(element[0], "NO") == 0
		|| ft_strcmp(element[0], "SO") == 0 || ft_strcmp(element[0], "WE") == 0
		|| ft_strcmp(element[0], "EA") == 0 || ft_strcmp(element[0], "S") == 0
		|| ft_strcmp(element[0], "F") == 0 || ft_strcmp(element[0], "C") == 0)
	{
		flag = fill_var(element, game);
		ft_freestrs(element);
	}
	else
	{
		ft_freestrs(element);
		return (-1);
	}
	return (flag);
}

static void	print_variables(t_game *game)
{
	printf("r_x:%d\nr_y:%d\nNO:%s\nSO:%s\nWE:%s\nEA:%s\nS:%s\nF_R:%d\nF_G:%d\nF_B:%d\nC_R:%d\nC_G:%d\nC_B:%d\nstart_x:%f\nstart_y:%f\nstart_orientation:%d\nn_items:%d\n", game->R_x, game->R_y, game->NO, game->SO, game->WE, game->EA, game->S, game->F_R, game->F_G, game->F_B, game->C_R, game->C_G, game->C_B, game->start_x, game->start_y, game->start_orientation, game->n_items);
}

static	void print_strs(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

void	validate_file(char *file, t_game *game)
{
	int		fd;
	int		is_filled;
	char	*line;

	is_filled = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file.\n");
		exit(3);
	}
	while (is_filled == 0)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		if (line[0] != '\n')
			is_filled = check_and_fill_var(line, game);
		if (is_filled != 1)
			free (line);
	}
	if (is_filled == 1)
	{
		//print_variables(game);
		is_filled = fill_map(line, fd, game);
		print_variables(game);
		printf("is_filled:%d\n", is_filled);
		//print_strs(game->map);
		(void)print_strs;
		//(void)print_variables;
	}
	else
		printf("error\n");
	printf("\n");
	close(fd);
}
