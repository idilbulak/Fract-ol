/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 13:59:00 by ibulak        #+#    #+#                 */
/*   Updated: 2022/04/09 14:31:14 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_mandelbrot(t_fractol *ptr)
{
	ptr->x = 0;
	while (ptr->x < ptr->width_img)
	{
		ptr->y = 0;
		while (ptr->y < ptr->height_img)
		{
			ptr->count = 0;
			ptr->c_a = ptr->x / ptr->zoom_x + (ptr->x_min);
			ptr->c_b = ptr->y / ptr->zoom_y + (ptr->y_min);
			ptr->a = 0;
			ptr->b = 0;
			while (ptr->a * ptr->a + ptr->b * ptr->b < 4
				&& ptr->count < ptr->iteration)
			{
				ptr->temp = ptr->a;
				ptr->a = ptr->a * ptr->a - ptr->b * ptr->b + ptr->c_a;
				ptr->b = 2 * ptr->b * ptr->temp + ptr->c_b;
				ptr->count++;
			}
			ft_color_pixels(ptr, ptr->count * ptr->color / ptr->iteration);
			ptr->y++;
		}
		ptr->x++;
	}
}

void	ft_julia_parameters(int argc, char *argv[], t_fractol *ptr)
{
	if (argc == 4)
	{
		if (!ft_strncmp("0", argv[2], 2) && !ft_strncmp("0", argv[3], 2))
		{
			ptr->c_a = 0;
			ptr->c_b = 0;
		}
		else
		{
			ptr->c_a = ft_atof(argv[2], 1, 0.0, 1.0);
			ptr->c_b = ft_atof(argv[3], 1, 0.0, 1.0);
		}
	}
	else
		ft_error_inputs();
}

void	ft_julia(t_fractol *ptr)
{
	ptr->x = 0;
	while (ptr->x < ptr->width_img)
	{
		ptr->y = 0;
		while (ptr->y < ptr->height_img)
		{
			ptr->count = 0;
			ptr->a = ptr->x / ptr->zoom_x + ptr->x_min;
			ptr->b = ptr->y / ptr->zoom_y + ptr->y_min;
			while (ptr->a * ptr->a + ptr->b * ptr->b < 4
				&& ptr->count < ptr->iteration)
			{
				ptr->temp = ptr->a;
				ptr->a = ptr->a * ptr->a - ptr->b * ptr->b + ptr->c_a;
				ptr->b = 2 * ptr->b * ptr->temp + ptr->c_b;
				ptr->count++;
			}
			ft_color_pixels(ptr, ptr->count * ptr->color / ptr->iteration);
			ptr->y++;
		}
		ptr->x++;
	}
}

void	ft_burningship(t_fractol *ptr)
{
	ptr->x = 0;
	while (ptr->x < ptr->width_img)
	{
		ptr->y = 0;
		while (ptr->y < ptr->height_img)
		{
			ptr->count = 0;
			ptr->c_a = ptr->x / ptr->zoom_x + (ptr->x_min);
			ptr->c_b = ptr->y / ptr->zoom_y + (ptr->y_min);
			ptr->a = 0;
			ptr->b = 0;
			while (ptr->a * ptr->a + ptr->b * ptr->b < 4
				&& ptr->count < ptr->iteration)
			{
				ptr->temp = ptr->a * ptr->a - ptr->b * ptr->b + ptr->c_a;
				ptr->b = fabs(2 * ptr->b * ptr->a) + ptr->c_b;
				ptr->a = ptr->temp;
				ptr->count++;
			}
			ft_color_pixels(ptr, ptr->count * ptr->color / ptr->iteration);
			ptr->y++;
		}
		ptr->x++;
	}
}
