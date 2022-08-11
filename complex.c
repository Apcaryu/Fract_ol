#include "complex.h"

t_cmplx add_cmplx(t_cmplx nb_a, t_cmplx nb_b)
{
	t_cmplx	nb_out;

	nb_out.rl = nb_a.rl + nb_b.rl;
	nb_out.im = nb_a.im + nb_b.im;
	return(nb_out);
}