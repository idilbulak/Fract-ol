/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 14:00:58 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/22 14:55:48 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_turnto_julia(t_fractol *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->img_ptr);
	ft_settings(ptr);
	ptr->name = 2;
	ptr->c_a = -0.687;
	ptr->c_b = 0.312;
}

void	ft_turnto_mandelbrot(t_fractol *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->img_ptr);
	ft_settings(ptr);
	ptr->name = 1;
}

void	ft_turnto_burningship(t_fractol *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->img_ptr);
	ft_settings(ptr);
	ptr->name = 3;
}

int	keyhook(int keycode, t_fractol *ptr)
{
	if (keycode == ESC)
		ft_destroy(ptr);
	if (keycode == KEY_C)
		ptr->color = ptr->color + 0xFFFFFF;
	if (keycode == KEY_1)
		ft_turnto_mandelbrot(ptr);
	if (keycode == KEY_2)
		ft_turnto_julia(ptr);
	if (keycode == KEY_3)
		ft_turnto_burningship(ptr);
	if (keycode == ARROW_UP)
		ptr->y_min = ptr->y_min - ptr->shift;
	if (keycode == ARROW_DOWN)
		ptr->y_min = ptr->y_min + ptr->shift;
	if (keycode == ARROW_LEFT)
		ptr->x_min = ptr->x_min - ptr->shift;
	if (keycode == ARROW_RIGHT)
		ptr->x_min = ptr->x_min + ptr->shift;
	if (keycode == KEY_PLUS)
		ptr->iteration = ptr->iteration + 50;
	if (keycode == KEY_MINUS)
		ptr->iteration = ptr->iteration - 50;
	ft_create_image(ptr);
	return (0);
}

int	mousehook(int button, int x, int y, t_fractol *ptr)
{
	double	dummy_x;
	double	dummy_y;

	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		dummy_x = x / ptr->zoom_x + (ptr->x_min);
		dummy_y = y / ptr->zoom_y + (ptr->y_min);
		if (button == ZOOM_IN)
		{
			ptr->zoom_x *= 0.5;
			ptr->zoom_y *= 0.5;
			ptr->shift /= 0.5;
		}
		if (button == ZOOM_OUT)
		{
			ptr->zoom_x /= 0.8;
			ptr->zoom_y /= 0.8;
			ptr->shift *= 0.8;
		}
		ptr->x_min = dummy_x - (x / ptr->zoom_x);
		ptr->y_min = dummy_y - (y / ptr->zoom_y);
	}
	ft_create_image(ptr);
	return (0);
}
