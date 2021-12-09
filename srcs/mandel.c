/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:21:38 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/09 13:26:47 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandel.h"

int	main(void)
{
	if (JULIA)
	{
		julia();
	}
	else
	{
		mandel();
	}
}

/*
** mandel is the version where we fixes z and iterate for c
*/
void	mandel(void)
{
	t_complex	step;
	t_complex	c;
	t_complex	z;
	int			i[2];

	step.x = (MAX_X - MIN_X) / RESOLUTION / RATIO;
	step.y = (MAX_Y - MIN_Y) / RESOLUTION;
	i[0] = 0;
	c.y = step.y + MIN_Y;
	while (i[0]++ <= RESOLUTION)
	{
		c.x = step.x + MIN_X;
		i[1] = 0;
		while (i[1]++ <= RESOLUTION * RATIO)
		{
			z.x = 0;
			z.y = 0;
			check_diver(c, z);
			c.x += step.x;
		}
		ft_putchar('\n');
		c.y += step.y;
	}
}

/*
** julia is the version where we fixes c and iterate for z
*/
void	julia(void)
{
	t_complex	step;
	t_complex	c;
	t_complex	z;
	int			i[2];

	step.x = (MAX_X - MIN_X) / RESOLUTION / RATIO;
	step.y = (MAX_Y - MIN_Y) / RESOLUTION;
	c.x = C_X;
	c.y = C_Y;
	i[0] = 0;
	z.y = step.y + MIN_Y;
	while (i[0]++ <= RESOLUTION)
	{
		z.x = step.x + MIN_X;
		i[1] = 0;
		while (i[1]++ <= RESOLUTION * RATIO)
		{
			check_diver(c, z);
			z.x += step.x;
		}
		ft_putchar('\n');
		z.y += step.y;
	}
}

/*
** check_diver is the function in wich we calculte the sequence
**		z(0)		= z
**		z(n + 1)	= z(n)^2 + c
**	and then print the corresponding character
**		'#' if the serie is borned
**		' ' otherwise
**	we check if the modulus of z is >= 2
**		(aka z_x^2 + z_y^2 >= 4, to spare a sqrt)
**	because we know for a fact that any number of modulus >= 2 diverges for that
**	function
*/
void	check_diver(t_complex c, t_complex z)
{
	int			i;
	double		temp_x;

	i = 0;
	while (i++ < PRECISION && z.x * z.x + z.y * z.y < 4)
	{
		temp_x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_x;
	}
	if (z.x * z.x + z.y * z.y >= 4)
		ft_putchar(' ');
	else
		ft_putchar('#');
}
