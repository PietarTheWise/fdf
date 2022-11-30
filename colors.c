/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:36:38 by pnoutere          #+#    #+#             */
/*   Updated: 2022/04/06 13:31:35 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_return(int color_step)
{
	unsigned int	max;
	unsigned int	temp;
	unsigned int	color;

	max = 255;
	temp = 0;
	max -= color_step;
	temp |= max << 16;
	temp |= 255;
	color = temp;
	return (color);
}

int	color_return_2(int color_step)
{
	unsigned int	min;
	unsigned int	temp;
	unsigned int	color;

	min = 0;
	temp = 0;
	min += color_step;
	temp |= min << 16;
	temp |= 255;
	color = temp;
	return (color);
}

int	color_return_3(int z_elevation)
{
	if (z_elevation > 0)
		return (0xFF00FF);
	else if (z_elevation < 0)
		return (0xFF00FF);
	else
		return (0x0000FF);
}

int	color_change(t_xyz coords1, t_xyz coords2, int color_step, t_data utils)
{
	if (utils.variance > 1 && (coords1.z * utils.z) > 0)
		return (color_return_3(coords1.z * utils.z));
	else if (utils.variance > 1)
		return (0x0000FF);
	if ((coords1.z * utils.z) > (coords2.z * utils.z))
	{
		if ((coords2.z * utils.z) < 0)
			return (color_return_2(color_step));
		else
			return (color_return(color_step));
	}
	else if ((coords1.z * utils.z) < (coords2.z * utils.z))
	{
		if ((coords2.z * utils.z) > 0)
			return (color_return_2(color_step));
		else
			return (color_return(color_step));
	}
	if ((coords1.z * utils.z) == (coords2.z * utils.z) && coords1.z > 0)
		return (0xFF00FF);
	else
		return (0x0000FF);
}
