#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include "write.h"
#include "move.h"
#include "flip.h"

using namespace std;

double initx_guitare(double t, double l, double pi){
	/* return 5*sin((pi/l)*t)*sin((pi/l)*t)+sin((0.313*pi/l)*t)*sin((0.313*pi/l)*t)+sin((2/l)*t)*sin((2/l)*t)+sin((3/l)*t)*sin((3/l)*t)+sin((5/l)*t)*sin((5/l)*t)+sin((1/l)*t)*sin((1/l)*t); */
	return sin((2*pi/l)*t)*sin((2*pi/l)*t);
}

/* printing metadata */ 
#define PRINTER(name) std::cout << "#" << #name << " = " << name << std::endl;

int main(int argc, char *argv[]){
	/* defining parameters */
	const double pi = 3.14159265359;
	int npart;
	double a;
	double l;
	double tmax;
	double dt;
	
	/* defining output files */
	ofstream File;
	string xFile;

	/* helper variables */
	double rand;
	double s;
	double t;
	int tt;

	/* initialisation */
	a = stod(argv[1]);
	l = stod(argv[2]);
	dt = stod(argv[3]);
	tmax = stod(argv[4]);
	npart = stoi(argv[5]);
	xFile = argv[6];
	
	double x[npart];
	double sigma[npart];
	double c[npart];
	double epsilon[npart];

	/* defining RNG */
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<double> dist(0,1);
	std::uniform_real_distribution<double> distx(0,l);

	/* print input parameters */
	PRINTER(a);
	PRINTER(l);
	PRINTER(tmax);
	PRINTER(dt);
	PRINTER(npart);
	
	for (int i=0; i<npart; i++){
		/* using hit and miss method to generate random numbers with distribution f(x)=sin^2(x) */
		t = distx(rng);
		s = dist(rng);
		while (initx_guitare(t,l,pi) < s){
			t = distx(rng);
			s = dist(rng);
		}
		x[i] = t;
		rand = dist(rng);
		c[i] = initc_2opt(rand);
		/* c[i] = 1; */
		rand = dist(rng);
		sigma[i] = initsigma(rand);
		/* sigma[i] = 1; */
		epsilon[i] = 1.01*c[i]*dt;
	}
	
	/* simulation */
	tt = 0;
	for (double t=0 ; t<=tmax ; t+=dt){
	
		/* simulation for all particles */
		for (int part=0; part < npart; part++){
			rand = dist(rng);
			sigma[part] = sigma[part]*fliptest(a,dt,rand);
			movefunc(x[part],c[part],sigma[part],l,dt,epsilon[part]);
		
		}
		/* writing out for every 100 steps */
		if (tt%10 == 0){
			/* writing the data out for first particle*/
			writefunc0(xFile,x[0]);
			/* writing the data out*/
			for (int part=1; part < npart-1; part++){
				writefunc(xFile,x[part]);
			}
			/* writing the data out for last particle*/
			writefunc_end(xFile,x[npart-1]);
		}
		tt++;
	}
	cout << "done" << endl;
	return 0;
}
