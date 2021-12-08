/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:21:52 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/09 00:24:50 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDEL_H
# define MANDEL_H

# include "libft.h"

# define RESOLUTION 60.0
# define PRECISION 25.0
# define MIN_X -2
# define MAX_X 1.4
# define MIN_Y -1.2
# define MAX_Y 1.2

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void	check_c(t_complex c);

#endif
