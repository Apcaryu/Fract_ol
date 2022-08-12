/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:39:27 by apellegr          #+#    #+#             */
/*   Updated: 2022/08/12 12:29:57 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_cmplx
{
	double	rl;
	double	im;
}	t_cmplx;


t_cmplx add_cmplx(t_cmplx nb_a, t_cmplx nb_b);
t_cmplx	substract_cmplx(t_cmplx nb_a, t_cmplx nb_b);
t_cmplx multiply_cmplx(t_cmplx nb_a, t_cmplx nb_b);
t_cmplx power_cmplx(t_cmplx nb, unsigned int power);
#endif