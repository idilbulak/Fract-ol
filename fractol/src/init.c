#include "../inc/fractol.h"

int	ft_color_pixels(t_fractol *ptr, int color)
{
	int		i;
	int		*new_ptr;

	if (ptr->x >= 0 && ptr->x < ptr->width_img
		&& ptr->y >= 0 && ptr->y < ptr->height_img)
	{
		i = ptr->y * ptr->img->size_line + ptr->x
			* ptr->img->bits_per_pixel / 8;
		new_ptr = (int *)&ptr->img->img_data[i];
		*new_ptr = color;
	}
	return (1);
}

void	ft_choose_fractol(t_fractol *ptr)
{
	if (ptr->name == 1)
		ft_mandelbrot(ptr);
	else if (ptr->name == 2)
		ft_julia(ptr);
	else if (ptr->name == 3)
		ft_burningship(ptr);
}

int	ft_create_image(t_fractol *ptr)
{
	if (ptr->img->img_ptr)
		mlx_destroy_image(ptr->mlx_ptr, ptr->img->img_ptr);
	ptr->img->img_ptr = mlx_new_image(ptr->mlx_ptr,
			ptr->width_img, ptr->height_img);
	if (!ptr->img->img_ptr)
		ft_error();
	ptr->img->img_data = mlx_get_data_addr(ptr->img->img_ptr,
			&ptr->img->bits_per_pixel, &ptr->img->size_line, &ptr->img->endian);
	if (!ptr->img->img_data)
		ft_error();
	ft_choose_fractol(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
		ptr->img->img_ptr, 0, 0);
	return (1);
}

int	ft_init(t_fractol *ptr)
{
	ptr->mlx_ptr = mlx_init();
	if (!ptr->mlx_ptr)
		ft_error();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr,
			ptr->width_img, ptr->height_img, "Fract-ol" );
	if (!ptr->win_ptr)
		ft_error();
	ft_create_image(ptr);
	mlx_hook(ptr->win_ptr, 2, 0, keyhook, ptr);
	// mlx_hook(ptr->win_ptr, 5, 0, click_cross, ptr);
	mlx_hook(ptr->win_ptr, 4, 0, mousehook, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (1);
}
