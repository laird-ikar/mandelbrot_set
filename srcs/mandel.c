/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:21:38 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/09 00:24:07 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandel.h"

int	main(void)
{
	t_complex	step;
	t_complex	c;
	int			i[2];

	step.x = (MAX_X - MIN_X) / RESOLUTION;
	step.y = (MAX_Y - MIN_Y) / RESOLUTION;
	i[0] = 0;
	c.y = step.y + MIN_Y;
	while (i[0]++ < RESOLUTION)
	{
		c.x = step.x + MIN_X;
		i[1] = 0;
		while (i[1]++ < RESOLUTION)
		{
			check_c(c);
			c.x += step.x;
		}
		ft_putchar('\n');
		c.y += step.y;
	}
}

void	check_c(t_complex c)
{
	t_complex	z;
	int			i;

	z.x = 0;
	z.y = 0;
	i = 0;
	while (i++ < PRECISION && z.x * z.x + z.y * z.y < 4)
	{
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
	}
	if (z.x * z.x + z.y * z.y >= 4)
		ft_putchar(' ');
	else
		ft_putchar('#');
}
