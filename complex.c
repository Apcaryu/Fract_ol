#include "complex.h"

t_cmplx add_cmplx(t_cmplx nb_a, t_cmplx nb_b)
{
	t_cmplx	nb_out;

	nb_out.rl = nb_a.rl + nb_b.rl;
	nb_out.im = nb_a.im + nb_b.im;
	return(nb_out);
}

t_cmplx multiply_cmplx(t_cmplx nb_a, t_cmplx nb_b)
{
	t_cmplx	nb_out;

	nb_out.rl = nb_a.rl * nb_b.rl - nb_a.im * nb_b.im;
	nb_out.im = nb_a.rl * nb_b.im + nb_a.im * nb_b.rl;
	return(nb_out);
}