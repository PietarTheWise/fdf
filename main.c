/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:42:40 by pnoutere          #+#    #+#             */
/*   Updated: 2022/04/06 13:58:55 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_row_amount(char *file)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	ret = 1;
	i = 0;
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		perror("Error");
		return (-1);
	}
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == 0)
			return (i);
		free(line);
		i++;
	}
	return (0);
}

void	file_assigner(t_files *f, char *argv)
{
	f->fd = 0;
	f->i = 0;
	f->j = 0;
	f->k = 0;
	f->len = 0;
	f->count = -1;
	f->rows = get_row_amount(argv);
	f->coords = (t_xyz **)malloc(sizeof(t_xyz *) * f->rows);
	f->fd = open(argv, O_RDONLY);
}

void	img_initiator(t_data *img, t_files f)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 1920, 1080, "FDF");
	img->count = f.count;
	img->rows = f.rows;
	img->coords = f.coords;
	img->color = 0x0000FF;
	img->start_x = 300;
	img->start_y = 0;
	img->scale = 20;
	img->rotation = 0.3;
	img->rotation_x = 0;
	img->rotation_y = 0;
	img->state = -1;
	img->z = 1;
	img->status = 0;
	img->parallel = 0;
}

void	to_number(t_files *f, t_data *img)
{
	f->k = 0;
	while (f->k < f->j)
	{
		f->coords[f->i][f->k].z = ft_atoi(f->char_array[f->k]);
		if (f->coords[f->i][f->k].z < -1000000
			|| f->coords[f->i][f->k].z > 1000000)
		{
			ft_putendl("Error: Elevation too high");
			exit (0);
		}
		check_variance(f->coords[f->i][f->k].z, &img->variance);
		f->k++;
	}
}

int	main(int argc, char **argv)
{
	t_files	f;

	file_assigner(&f, argv[1]);
	if (f.rows < 0)
		return (0);
	if (argc > 2)
	{
		ft_putendl("Error: Too many arguments");
		return (0);
	}
	else if (argc < 2)
	{
		ft_putendl("Error: Too few arguments");
		return (0);
	}
	if (!main_loop(f))
		ft_putendl("Error: Malloc failed");
	else
		ft_putendl("Error: Invalid file");
	return (1);
}
