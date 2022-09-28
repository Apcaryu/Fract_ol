/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:17:51 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/27 15:19:42 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atof.h"

double	the_while(const char *str, double *nb_out, unsigned int *idx, int mod)
{
	unsigned int	nb_after_point;

	nb_after_point = 0;
	while ('0' <= str[*idx] && str[*idx] <= '9')
	{
		*nb_out = (*nb_out * 10) + (str[*idx] - '0');
		*idx += 1;
		if (mod == 1)
			nb_after_point++;
	}
	return (nb_after_point);
}

double	ft_atof(const char *str)
{
	unsigned int	idx;
	char			pos;
	double			nb_out;

	idx = 0;
	pos = 1;
	nb_out = 0;
	while ((str[idx] < '0' || '9' < str[idx]) && \
	str[idx] != '-' && str[idx] != '.')
		idx++;
	if (str[idx] == '-')
		pos = -1;
	the_while(str, &nb_out, &idx, 0);
	if (str[idx] == '.')
	{
		idx++;
		nb_out *= pow(0.1, the_while(str, &nb_out, &idx, 1));
	}
	return (nb_out * pos);
}
