/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:23:50 by pnoutere          #+#    #+#             */
/*   Updated: 2022/04/06 13:21:25 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_key(t_data *coords)
{
	if (coords->status == 0)
	{
		coords->parallel = 0;
		coords->status = 1;
		coords->rotation = 0.8;
	}
	else if (coords->status == 1)
	{
		coords->status = 2;
		coords->rotation = 0.01;
	}
	else if (coords->status == 2)
	{
		coords->status = 3;
		coords->rotation = 0.4;
	}
	else if (coords->status == 3)
	{
		coords->status = 0;
		coords->parallel = 1;
	}
}

int	deal_key(int key, void *param)
{
	t_data	*coords;

	coords = param;
	if (key == ARROW_UP)
	{
		coords->z++;
		initiate_fdf(coords);
	}
	if (key == ARROW_DOWN)
	{
		coords->z--;
		initiate_fdf(coords);
	}
	if (key == MAIN_PAD_ESC)
	{
		mlx_destroy_window(coords->mlx, coords->win);
		exit (0);
	}
	if (key == MAIN_PAD_P)
	{
		rotate_key(coords);
		initiate_fdf(coords);
	}
	return (0);
}

int	deal_mouse(int key, int x, int y, void *param)
{
	t_data	*coords;

	coords = param;
	(void)x;
	(void)y;
	if (key == MOUSE_LEFT_BUTTON)
		coords->state *= -1;
	if (key == MOUSE_SCROLL_UP)
	{
		coords->scale += 2;
		mlx_clear_window(coords->mlx, coords->win);
		initiate_fdf(coords);
	}
	if (key == MOUSE_SCROLL_DOWN)
	{
		coords->scale -= 2;
		initiate_fdf(coords);
	}
	return (0);
}

void	ctrl_hooks(t_data *img)
{
	mlx_hook(img->win, 2, 0, &deal_key, img);
	mlx_hook(img->win, 4, 0, &deal_mouse, img);
	mlx_hook(img->win, 5, 0, &deal_mouse, img);
	mlx_hook(img->win, 6, 0, &deal_mouse_movement, img);
}

int	deal_mouse_movement(int x, int y, void *param)
{
	t_data	*coords;

	coords = param;
	(void)x;
	if (coords->state == 1)
	{
		if (y > coords->rotation_y)
		{
			coords->rotation += 0.02;
			initiate_fdf(coords);
		}
		else
		{
			initiate_fdf(coords);
			coords->rotation -= 0.02;
		}
	}
	coords->rotation_x = x;
	coords->rotation_y = y;
	return (0);
}
