/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:27:36 by pnoutere          #+#    #+#             */
/*   Updated: 2022/04/06 13:32:10 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_data *utils, t_xyz coord1, t_xyz coord2)
{
	if (!utils->parallel)
	{
		isometric(&coord1.x, &coord1.y, coord1.z, utils);
		isometric(&coord2.x, &coord2.y, coord2.z, utils);
	}
	else
	{
		coord1.x = coord1.x + utils->start_x;
		coord1.y = coord1.y + utils->start_y;
		coord2.x = coord2.x + utils->start_x;
		coord2.y = coord2.y + utils->start_y;
	}
	if ((ft_abs(coord2.y - coord1.y)) < (ft_abs(coord2.x - coord1.x)))
		drawer_1(utils, coord1, coord2);
	else
		drawer_2(utils, coord1, coord2);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	isometric(int *x, int *y, int z, t_data *utils)
{
	float	x_1;
	float	y_1;

	x_1 = (*x - *y) * cos(0.8);
	y_1 = (*x + *y) * sin(utils->rotation) - (z * utils->z);
	*x = (int)x_1 + utils->start_x;
	*y = (int)y_1 + utils->start_y;
}

void	calculate_center(t_data *utils, int *start_x, int *start_y)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = utils->coords[0][0].x;
	x2 = utils->coords[utils->rows - 1][utils->count -1].x;
	y1 = utils->coords[0][0].y;
	y2 = utils->coords[utils->rows - 1][utils->count -1].y;
	if (!utils->parallel)
	{
		isometric(&x1, &y1, utils->coords[0][0].z, utils);
		isometric(&x2, &y2,
			utils->coords[utils->rows - 1][utils->count -1].z, utils);
	}
	*start_x = (x1 + x2) / 2;
	*start_y = (y1 + y2) / 2;
	*start_x = 960 - (*start_x - x1);
	*start_y = 540 - (*start_y - y1);
}

void	check_variance(int number, int *variant)
{
	static int	init;
	static int	init_2;
	static int	temp;
	static int	differ;

	number = ft_abs(number);
	if (!init)
	{
		temp = number;
		init = 1;
		return ;
	}
	if (number != temp)
	{
		if (!init_2)
		{
			differ = number;
			*variant += 1;
			init_2 = 1;
			return ;
		}
		if (number != differ)
			*variant += 1;
	}
}
