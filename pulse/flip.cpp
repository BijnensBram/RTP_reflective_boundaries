#include "flip.h"
#include <cmath>

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

double fliptest_a_peaks(double x, double a,double l, double dt, double rand){
	if (rand < a_profile_peaks(x,a,l)*dt){
		return -1;
	} else {
		return 1;
	}
}

double a_profile_peaks(double x,double a,double l){
	return a*(exp(-500*(x-l*0.5)*(x-l*0.25))+exp(-500*(x-l*0.75)*(x-l*0.75)));
}

