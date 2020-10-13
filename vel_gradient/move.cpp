#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include "move.h"

using namespace std;

void movefunc(double &x,double &sigma, double l, double dt, double epsilon){
	if (x < epsilon) sigma = 1;
	else if (l-x < epsilon) sigma = -1;
	
	x += (sigma*c_lin(x)*dt);
}

/* function to initialise c out of five options */
double initc_5opt(double rand){
	if (rand < 0.2) return 0.5;
	else if (rand < 0.4) return 1;
	else if (rand < 0.6) return 1.5;
	else if (rand < 0.8) return 2;
	else return 2.5;
}

/* function to initialise c out of two options */
double initc_2opt(double rand){
	if (rand < 0.5) return 1;
	else return 2;
}

double c_lin(double x){
	return 1+x*0.5;
}
