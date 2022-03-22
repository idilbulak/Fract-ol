/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 14:10:17 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/22 14:57:15 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0' && x < n - 1)
	{
		if (s1[x] != s2[x])
			break ;
		x++;
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	else
		return (1);
}

double	ft_atof(char *s, int sign)
{
	double	nbr;
	double	div;

	nbr = 0.0;
	div = 1.0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		nbr = nbr * 10.0 + (*s - '0');
		s++;
	}
	if (*s == '.')
		s++;
	while (ft_isdigit(*s))
	{
		nbr = nbr * 10.0 + (*s - '0');
		div *= 10.0;
		s++;
	}
	return (nbr * sign / div);
}

void	ft_destroy(t_fractol *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->img_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	free(ptr->img);
	free(ptr->mlx_ptr);
	free(ptr);
	exit(0);
}

int	click_cross(int button, t_fractol *ptr)
{
	(void)ptr;
	exit(0);
}
