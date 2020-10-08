#include <iostream>
#include <cmath>
#include <random>
/* #include "move.h" */
#include "flip.h"

/* function to initialise sigma */
/* in 1d only two directions are possible for movement left or rigth => c = +/- 1 */
double initsigma(double rand){
	if (rand > 0.5){
		return +1;
	} else {
		return -1;
	}
}

double fliptest(double a, double dt, double rand){
	if (rand < a*dt){
		return -1;
	} else {
		return 1;
	}
}
