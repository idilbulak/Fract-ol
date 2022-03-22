/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 14:26:56 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/22 15:18:32 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx/mlx.h"
# define LEFT_CLICK 1
# define ZOOM_OUT 4
# define ZOOM_IN 5
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_UP 126
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_C 8
# define KEY_PLUS 24
# define KEY_MINUS 27

typedef struct s_img
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*img_data;
	void	*img_ptr;
}			t_img;

typedef struct s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	int			width_img;
	int			height_img;
	int			iteration;
	int			color;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		count;
	double		a;
	double		b;
	double		c_a;
	double		c_b;
	double		zoom_x;
	double		zoom_y;
	double		temp;
	int			img_x;
	int			img_y;
	float		shift;
	int			name;
	t_img		*img;
}				t_fractol;

int		keyhook(int keycode, t_fractol *ptr);
int		click_cross(int button, t_fractol *ptr);
int		mousehook(int button, int x, int y, t_fractol *ptr);
int		ft_color_pixels(t_fractol *ptr, int color);
void	ft_choose_fractol(t_fractol *ptr);
int		ft_create_image(t_fractol *ptr);
int		ft_init(t_fractol *ptr);
int		ft_isdigit(int c);
double	ft_atof(char *s, int sign);
void	ft_julia_parameters(int argc, char *argv[], t_fractol *ptr);
void	ft_julia(t_fractol *ptr);
void	ft_settings(t_fractol *ptr);
void	ft_mandelbrot(t_fractol *ptr);
void	ft_burningship(t_fractol *ptr);
void	ft_error(void);
void	ft_error_inputs(void);
void	ft_destroy(t_fractol *ptr);
void	ft_turnto_julia(t_fractol *ptr);
void	ft_turnto_mandelbrot(t_fractol *ptr);
void	ft_turnto_burningship(t_fractol *ptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_check_name(t_fractol *ptr, char **argv, int argc);

#	endif