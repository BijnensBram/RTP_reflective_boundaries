#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include "write.h"
#include "move.h"
#include "flip.h"
/* #include "pulse.h" */

using namespace std;

/* printing metadata */ 
#define PRINTER(name) std::cout << "#" << #name << " = " << name << std::endl;

int main(int argc, char *argv[]){
	/* defining parameters */
	const double pi = 3.14159265359;
	int npart;
	int npulse;
	double a;
	double l;
	double tmax;
	double dt;
	
	/* defining output files */
	ofstream File;
	string xFile;

	/* helper variables */
	double rand;
	int index;
	int tt;

	/* initialisation */
	a = stod(argv[1]);
	l = stod(argv[2]);
	dt = stod(argv[3]);
	tmax = stod(argv[4]);
	npart = stoi(argv[5]);
	xFile = argv[6];
	
	npulse = int(npart/5);
	double x[npart];
	double sigma[npart];
	double c[npart];
	double epsilon[npart];

	/* defining RNG */
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<double> dist(0,1);
	std::uniform_real_distribution<double> distx(0,l);
	std::uniform_int_distribution<int> distindex(0,npart-1);
	std::normal_distribution<double> distpulse(l/2,l/12);
	/* print input parameters */
	PRINTER(a);
	PRINTER(l);
	PRINTER(tmax);
	PRINTER(dt);
	PRINTER(npart);
	
	for (int i=0; i<npart; i++){
		x[i] = distx(rng);
		rand = dist(rng);
		c[i] = 1;
		rand = dist(rng);
		sigma[i] = initsigma(rand);
		epsilon[i] = 1.01*c[i]*dt;
	}
	
	/* simulation */
	tt = 0;
	for (double t=0 ; t<=tmax ; t+=dt){
	
		/* simulation for all particles */
		for (int part=0; part < npart; part++){
			rand = dist(rng);
			sigma[part] = sigma[part]*fliptest_a_peaks(x[part],a,l,dt,rand);
			movefunc(x[part],c[part],sigma[part],l,dt,epsilon[part]);
		
		}

		/* pulsing with 2frec1 */
		if (tt%int(l/(4*dt)) == 0){
			for (int i = 0 ; i < npulse; i++){
				index = distindex(rng);
				x[index] = distpulse(rng);
				c[index] = 1;
			}
		}
		
		/* writing out for every 100 steps */
		if (tt%10 == 0){
			/* writing the data out for first particle*/
			/* writefunc0(xFile,x[0],cFile,c[0],sigmaFile,sigma[0]); */
			writefunc0(xFile,x[0]);
			/* writing the data out*/
			for (int part=1; part < npart-1; part++){
				/* writefunc(xFile,x[part],cFile,c[part],sigmaFile,sigma[part]); */
				writefunc(xFile,x[part]);
			}
			/* writing the data out for last particle*/
			/* writefunc_end(xFile,x[npart-1],cFile,c[npart-1],sigmaFile,sigma[npart-1]); */
			writefunc_end(xFile,x[npart-1]);
		}
		tt++;
	}
	cout << "done" << endl;
	return 0;
}
