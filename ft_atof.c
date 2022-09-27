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

double	ft_atof(char *str)
{
	unsigned int	idx;
	double			nb_out;

	idx = 0;
	while((str[idx] < '0' || '9' < str[idx]) || str[idx] != '-' || str[idx] != '.')
		idx++;
}
