#include "../inc/fractol.h"

void	ft_error(void)
{
	write(1, "ERROR!", 6);
	exit(0);
}

void	ft_settings(t_fractol *ptr)
{
	ptr->x_min = -2.0;
	ptr->x_max = 2.0;
	ptr->y_min = -2.0;
	ptr->y_max = 2.0;
	ptr->zoom_x = 250;
	ptr->zoom_y = 250;
	ptr->iteration = 300;
	ptr->color = 0xFFFFFF / 20;
	ptr->shift = 0.1;
}

int	ft_check_name(t_fractol *ptr, char **argv, int argc)
{
	if (!ft_strncmp("Mandelbrot", argv[1], 10))
		ptr->name = 1;
	else if (!ft_strncmp("Julia", argv[1], 5))
	{
		ptr->name = 2;
		ft_julia_parameters(argc, argv, ptr);
	}
	else if (!ft_strncmp("Burningship", argv[1], 11))
		ptr->name = 3;
	else
		ft_error();
	ft_settings(ptr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractol	*ptr;

	ptr = (t_fractol *)malloc(sizeof(t_fractol));
	if (!ptr)
		ft_error();
	ptr->width_img = 1000;
	ptr->height_img = 1000;
	ptr->img = (t_img *)malloc(sizeof(t_img));
	if (!ptr->img)
		ft_error();
	if ( argc > 4 || argc < 2 || ft_check_name(ptr, argv, argc) != 1)
		ft_error();
	else
		ft_init(ptr);
	// system("leaks fractol");
	return (0);
}
