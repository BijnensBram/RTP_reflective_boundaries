#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include "move.h"
#include "flip.h"

using namespace std;

/* printing metadata */ 
#define PRINTER(name) std::cout << "#" << #name << " = " << name << std::endl;

int main(int argc, char *argv[]){
	/* defining parameters */
	int npart;
	double a;
	double l;
	double tmax;
	double dt;
	
	/* defining output files */
	ofstream sigmaFile;
	ofstream xFile;
	ofstream cFile;

	/* helper variables */
	double rand;

	/* initialisation */
	a = stod(argv[1]);
	l = stod(argv[2]);
	dt = stod(argv[3]);
	tmax = stod(argv[4]);
	npart = stoi(argv[5]);
	
	double x[npart];
	double sigma[npart];
	double c[npart];

	/* defining RNG */
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<double> dist(0,1);
	std::uniform_real_distribution<double> distx(0,l);
	std::normal_distribution<double> distc(0,1);

	/* print input parameters */
	PRINTER(a);
	PRINTER(l);
	PRINTER(tmax);
	PRINTER(dt);
	PRINTER(npart);
	
	for (int i=0; i<npart; i++){
		x[i] = distx(rng);
		c[i] = distc(rng);
		rand = dist(rng);
		sigma[i] = initsigma(rand);
	}
	
	/* simulation */
	for (double t=0 ; t<=tmax ; t+=dt){
		rand = dist(rng);
		sigma[0] = sigma*fliptest(a,dt,rand);
		movefunc(x[0],c[0],sigma[0],dt);
		for (int part=1; part < npart; part++){
			rand = dist(rng);
			sigma = sigma*fliptest(a,dt,rand);
			movefunc(x[part],c[part],sigma[part],dt);
		}
	}

}
