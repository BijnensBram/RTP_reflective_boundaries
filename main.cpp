#include <iostream>
#include <cmath>
#include <random>
#include "move.h"
#include "flip.h"

using namespace std;

int main(int argc, char *argv[]){
	/* defining parameters */
	int N;
	
	double a;
	double l;
	double nx;
	double dx;
	double tmax;
	double dt;
	double x[N];
	double sigma[N];
	double c[N];

	/* helper variables */
	double rand;

	/* defining RNG */
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<double> dist(0,1);
	std::uniform_int_distribution<int> distsigma(0,3);
	std::uniform_int_distribution<int> distx(1,nx);

	/* initialisation */
	a = stod(argv[2]);
	l = stod(argv[1]);
	nx = stod(argv[3]);
	dx = l/nx;
	dt = stod(argv[4]);
	tmax = stod(argv[5]);

	x = distx();
}
