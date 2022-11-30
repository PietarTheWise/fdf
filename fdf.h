/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fdf.h											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pnoutere <pnoutere@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/15 16:57:34 by pnoutere		  #+#	#+#			 */
/*   Updated: 2022/03/21 13:52:38 by pnoutere		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define KEY_MACOS_H

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	2
# define MOUSE_THIRD_BUTTON	3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_LEFT	6
# define MOUSE_SCROLL_RIGHT	7

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define NUM_PAD_0			82
# define NUM_PAD_1			83
# define NUM_PAD_2			84
# define NUM_PAD_3			85
# define NUM_PAD_4			86
# define NUM_PAD_5			87
# define NUM_PAD_6			88
# define NUM_PAD_7			89
# define NUM_PAD_8			91
# define NUM_PAD_9			92
# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78

# define MAIN_PAD_ESC		53
# define MAIN_PAD_I			34
# define MAIN_PAD_P			35
# define MAIN_PAD_0			29
# define MAIN_PAD_1			18
# define MAIN_PAD_2			19
# define MAIN_PAD_3			20
# define MAIN_PAD_4			21
# define MAIN_PAD_5			23
# define MAIN_PAD_6			22
# define MAIN_PAD_7			26
# define MAIN_PAD_8			28
# define MAIN_PAD_9			25
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27
# define MAIN_PAD_LESS		43
# define MAIN_PAD_MORE		47

typedef struct s_xyz
{
	int	x;
	int	y;
	int	z;
}				t_xyz;

typedef struct s_files
{
	int		fd;
	char	*line;
	char	**char_array;
	int		rows;
	int		i;
	int		j;
	int		k;
	int		len;
	int		count;
	t_xyz	**coords;
}				t_files;

typedef struct s_data
{
	t_xyz	**coords;
	char	*addr;
	void	*img;
	void	*mlx;
	void	*win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		start_x;
	int		start_y;
	int		scale;
	int		rows;
	int		count;
	int		state;
	float	rotation;
	int		rotation_x;
	int		rotation_y;
	int		z;
	int		variance;
	int		status;
	int		parallel;
}				t_data;

int		array_len_checker(t_files *f);
void	calculate_center(t_data *utils, int *start_x, int *start_y);
int		deal_key(int key, void *param);
int		deal_mouse(int key, int x, int y, void *param);
int		deal_mouse_movement(int x, int y, void *param);
int		char_array_len(char **str);
void	check_variance(int number, int *variant);
void	ctrl_hooks(t_data *img);
int		color_return_3(int z_elevation);
int		color_return_2(int color_step);
int		color_return(int color_step);
int		color_change(t_xyz coords1, t_xyz coords2,
			int color_step, t_data utils);
void	draw(t_data *utils, t_xyz coord1, t_xyz coord2);
void	drawer_1(t_data *utils, t_xyz coords1, t_xyz coords2);
void	drawer_2(t_data *utils, t_xyz coords1, t_xyz coords2);
int		draw_grid(t_data *utils);
void	drawer_2_util(int *color_step, int *sign,
			t_xyz *coords1, t_xyz *coords2);
void	drawer_1_util(int *color_step, int *sign,
			t_xyz *coords1, t_xyz *coords2);
void	elevation_check(char *str);
void	free_stuff(t_files *f);
void	file_assigner(t_files *f, char *argv);
int		get_row_amount(char *file);
void	img_initiator(t_data *img, t_files f);
void	init(t_data *img);
void	init_grid(t_data *utils);
int		initiate_fdf(t_data *img);
void	isometric(int *x, int *y, int z, t_data *utils);
int		main_util(t_data *img, t_files *f);
int		main_loop(t_files f);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	pre_initiate(t_files *f);
int		render_next_frame(void *structure);
void	rotate_key(t_data *coords);
void	swap_points(t_xyz *coords1, t_xyz *coords2);
void	to_number(t_files *f, t_data *img);

#endif