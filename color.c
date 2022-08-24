#include "color.h"

t_color_set	set_init(int mod)
{
	t_color_set color_set_out;

	if(mod == 1)
	{
		color_set_out.a = 0xB33E97;
		color_set_out.b = 0xFFE97D;
		color_set_out.c = 0xFF73DE;
		color_set_out.d = 0x59FFFC;
		color_set_out.e = 0x47B3B1;
	}
	return(color_set_out);
}