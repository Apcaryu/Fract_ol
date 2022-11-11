if [ $# == 1 ]
then
	make re && make clean
	if [ $1 == 0 ]
	then
		valgrind ./fractol julia
	elif [ $1 == 1 ]
	then
		./fractol mandelbrot &
		./fractol julia &
		./fractol julia 0.3 &
		./fractol julia 0.3 0.58 &
		./fractol burningship &
	else
		echo 'Wrong args'
	fi
else
	echo 'Missing or to many args'
fi