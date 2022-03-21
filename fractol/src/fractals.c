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
		ptr->c_a = ft_atof(argv[2]);
		ptr->c_b = ft_atof(argv[3]);
	}
	else
		ft_error();
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

