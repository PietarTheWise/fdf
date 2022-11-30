/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiating_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:17:31 by pnoutere          #+#    #+#             */
/*   Updated: 2022/04/06 13:16:47 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_data *img)
{
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	init_grid(t_data *utils)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < utils->rows)
	{
		j = 0;
		while (j < utils->count)
		{
			utils->coords[i][j].x = (j * utils->scale);
			utils->coords[i][j].y = (i * utils->scale);
			j++;
		}
		i++;
	}
}

int	initiate_fdf(t_data *img)
{
	init(img);
	draw_grid(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_destroy_image(img->mlx, img->img);
	return (0);
}

void	swap_points(t_xyz *coords1, t_xyz *coords2)
{
	int	temp;

	temp = coords1->x;
	coords1->x = coords2->x;
	coords2->x = temp;
	temp = coords1->y;
	coords1->y = coords2->y;
	coords2->y = temp;
	temp = coords1->z;
	coords1->z = coords2->z;
	coords2->z = temp;
}

void	free_stuff(t_files *f)
{
	ft_free_array(f->char_array);
	free(f->line);
}
