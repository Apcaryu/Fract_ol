#include "fractol.h"

void	is_in_fractal(t_data m_data, char *pos)
{
	*(unsigned int *)pos = 0xFFFFFF / ((m_data.zc.z.rl * 10000) / (m_data.zc.z.im * 10000));
}

void	is_out_fractal(t_data m_data, char *pos, unsigned int i)
{
	*(unsigned int *)pos = 0x00000000 + i  * 0x010101;
}