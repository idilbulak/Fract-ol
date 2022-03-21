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

double	ft_atof(char *s)
{
	double	nbr;
	int		sign;
	double	div;

	sign = 1;
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
