#include "complex.h"

t_cmplx add_cmplx(t_cmplx nb_a, t_cmplx nb_b)
{
	t_cmplx	nb_out;

	nb_out.rl = nb_a.rl + nb_b.rl;
	nb_out.im = nb_a.im + nb_b.im;
	return(nb_out);
}

t_cmplx	substract_cmplx(t_cmplx nb_a, t_cmplx nb_b)
{
	t_cmplx nb_out;

	nb_out.rl = nb_a.rl - nb_b.rl;
	nb_out.im = nb_a.im - nb_b.im;
	return(nb_out);
}

t_cmplx multiply_cmplx(t_cmplx nb_a, t_cmplx nb_b)
{
	t_cmplx	nb_out;

	nb_out.rl = nb_a.rl * nb_b.rl - nb_a.im * nb_b.im;
	nb_out.im = nb_a.rl * nb_b.im + nb_a.im * nb_b.rl;
	return(nb_out);
}

t_cmplx div_cmplx(t_cmplx nb_a, t_cmplx nb_b)
{
	t_cmplx nb_out;

	nb_out.rl = nb_a.rl / nb_b.rl;
	nb_out.im = nb_a.im / nb_b.im;
	return(nb_out);
}

t_cmplx power_cmplx(t_cmplx nb, unsigned int power)
{
	unsigned int cntr;
	t_cmplx			tmp;
	t_cmplx			nb_out;

	cntr = 1;
	tmp.rl = nb.rl;
	tmp.im = nb.im;
	while (cntr < power)
	{
		nb_out.rl = nb.rl * tmp.rl - nb.im * tmp.im;
		nb_out.im = nb.rl * tmp.im + nb.im * tmp.rl;
		tmp.rl = nb_out.rl;
		tmp.im = nb_out.im;
		cntr++;
	}
	return(nb_out);
}