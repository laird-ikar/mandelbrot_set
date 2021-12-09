/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:21:52 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/09 13:21:48 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDEL_H
# define MANDEL_H

# include "libft.h"

/*
** Parameters
** RESOLUTION is the number of lines we output
** PRECISION is the number of iteration we do
** MIN_X, MAX_X, MIN_Y, MAX_Y are the borders in which we calculate
** RATIO is the ratio we use to print a set that looks orthonormal
*/
# define RESOLUTION 300.0
# define PRECISION 1000.0
# define MIN_X -2.0
# define MAX_X 2.0
# define MIN_Y -2.0
# define MAX_Y 2.0
# define RATIO 2.1

/*
** More parameter for calculating Julia Sets
** JULIA is a boolean
**	JULIA = 1 -> Julia Set
**	JULIA = 0 -> Mandelbrot Set
** C_X and C_Y are the Real and Imaginary part of c
*/
# define JULIA 1
# define C_X 0.3
# define C_Y 0.5

/*
** A structure to have complex numbers
*/
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

/*
** check_diver is the function in wich we calculte the sequence
**		z(0)		= z
**		z(n + 1)	= z(n)^2 + c
**	and then print the corresponding character
**		'#' if the serie is borned
**		' ' otherwise
** julia is the version where we fixes c and iterate for z
** mandel is the version where we fixes z and iterate for c
*/
void	check_diver(t_complex c, t_complex z);
void	julia(void);
void	mandel(void);

#endif
