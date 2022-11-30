/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:42:44 by pnoutere          #+#    #+#             */
/*   Updated: 2022/04/06 13:16:35 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	elevation_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
	{
		ft_putendl("Error: Invalid map");
		exit (0);
	}
}

int	char_array_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		elevation_check(str[i]);
		i++;
	}
	return (i);
}

int	array_len_checker(t_files *f)
{
	if (f->count > 0)
	{
		f->len = char_array_len(f->char_array);
		if (f->len != f->count)
			return (0);
	}
	if (f->count == -1)
		char_array_len(f->char_array);
	return (1);
}

int	main_util(t_data *img, t_files *f)
{
	img_initiator(img, *f);
	initiate_fdf(img);
	ctrl_hooks(img);
	mlx_loop(img->mlx);
	return (1);
}

int	main_loop(t_files f)
{
	t_data	img;

	img.variance = 0;
	while (get_next_line(f.fd, &f.line))
	{
		f.char_array = ft_strsplit(f.line, ' ');
		if (!array_len_checker(&f))
			return (-1);
		while (f.char_array[f.j])
			f.j++;
		f.coords[f.i] = (t_xyz *)malloc(sizeof(t_xyz) * f.j);
		if (f.coords[f.i] == NULL)
			return (0);
		to_number(&f, &img);
		if (f.j > f.count)
		{
			f.count = f.j;
			f.j = 0;
		}
		if (f.count == 0)
			return (-1);
		free_stuff(&f);
		f.i++;
	}
	return (main_util(&img, &f));
}
