/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:03:22 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/30 13:03:24 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_program(t_data *m_data)
{
	if (m_data->mlx && m_data->img.mlx_img)
		mlx_destroy_image(m_data->mlx, m_data->img.mlx_img);
	if (m_data->mlx && m_data->mlx_window)
		mlx_destroy_window(m_data->mlx, m_data->mlx_window);
	if (m_data->mlx)
	{
		mlx_destroy_display(m_data->mlx);
		mlx_loop_end(m_data->mlx);
		free(m_data->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	check_mlx(t_data *m_data)
{
	if(!m_data->img.addr)
		if (!m_data->img.mlx_img)
			if (!m_data->mlx_window)
				if (!m_data->mlx)
					exit_program(m_data);
}
