/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:05:24 by pnoutere          #+#    #+#             */
/*   Updated: 2022/04/05 17:39:14 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawer_2_util(int *color_step, int *sign,
						t_xyz *coords1, t_xyz *coords2)
{
	*color_step = 1;
	if (coords2->y - coords1->y < 0)
		swap_points(coords1, coords2);
	if (coords2->x - coords1->x < 0)
		*sign = -1;
	if ((coords2->y - coords1->y) != 0)
		*color_step = 255 / (coords2->y - coords1->y);
}

void	drawer_1_util(int *color_step, int *sign,
						t_xyz *coords1, t_xyz *coords2)
{
	*color_step = 1;
	if (coords2->x - coords1->x < 0)
		swap_points(coords1, coords2);
	if (coords2->y - coords1->y < 0)
		*sign = -1;
	if ((coords2->x - coords1->x) != 0)
		*color_step = 255 / (coords2->x - coords1->x);
}

void	drawer_1(t_data *utils, t_xyz coords1, t_xyz coords2)
{
	int	sign;
	int	p;
	int	temp;
	int	color_step;

	sign = 1;
	p = 0;
	drawer_1_util(&color_step, &sign, &coords1, &coords2);
	p = (2 * ((coords2.y - coords1.y) * sign)) - (coords2.x - coords1.x);
	temp = 0;
	while (coords1.x <= coords2.x)
	{
		my_mlx_pixel_put(utils, coords1.x, coords1.y,
			color_change(coords1, coords2, temp, *utils));
		temp += color_step;
		if (p >= 0)
		{
			coords1.y += sign;
			p += (2 * (((coords2.y - coords1.y) * sign)
						- (coords2.x - coords1.x)));
		}
		else
			p += (2 * ((coords2.y - coords1.y) * sign));
		coords1.x++;
	}
}

void	drawer_2(t_data *utils, t_xyz coords1, t_xyz coords2)
{
	int	sign;
	int	p;
	int	color_step;
	int	temp;

	p = 0;
	sign = 1;
	drawer_2_util(&color_step, &sign, &coords1, &coords2);
	p = (2 * ((coords2.x - coords1.x) * sign)) - (coords2.y - coords1.y);
	temp = 0;
	while (coords1.y <= coords2.y)
	{
		my_mlx_pixel_put(utils, coords1.x, coords1.y,
			color_change(coords1, coords2, temp, *utils));
		temp += color_step;
		if (p >= 0)
		{
			coords1.x += sign;
			p += (2 * (((coords2.x - coords1.x) * sign)
						- (coords2.y - coords1.y)));
		}
		else
			p += (2 * ((coords2.x - coords1.x) * sign));
		coords1.y++;
	}
}

int	draw_grid(t_data *utils)
{
	int	i;
	int	j;

	init_grid(utils);
	calculate_center(utils, &utils->start_x, &utils->start_y);
	i = 0;
	while (i < utils->rows)
	{
		j = 0;
		while (j < utils->count)
		{
			if (j < utils->count - 1)
				draw(utils, utils->coords[i][j], utils->coords[i][j + 1]);
			if (i < utils->rows - 1)
				draw(utils, utils->coords[i][j], utils->coords[i + 1][j]);
			j++;
		}
		i++;
	}
	return (0);
}
