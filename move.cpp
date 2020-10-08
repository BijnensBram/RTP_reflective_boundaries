#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include "move.h"

using namespace std;

void movefunc(double &x,double c,double &sigma, double l, double dt, double epsilon){
	if (x < epsilon) sigma = 1;
	else if (l-x < epsilon) sigma = -1;
	
	x += (sigma*c*dt);
}

double initc(double rand){
	if (rand < 0.2) return 0.5;
	else if (rand < 0.4) return 1;
	else if (rand < 0.6) return 1.5;
	else if (rand < 0.8) return 2;
	else return 2.5;
}
