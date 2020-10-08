#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include "write.h"
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
	ofstream File;
	string xFile;
	string cFile;
	string sigmaFile;
	string datafolder;

	/* helper variables */

	double rand;

	/* initialisation */
	a = stod(argv[1]);
	l = stod(argv[2]);
	dt = stod(argv[3]);
	tmax = stod(argv[4]);
	npart = stoi(argv[5]);
	datafolder = argv[6];
	xFile = datafolder+"xfile_a_"+to_string(a)+"_l_"+to_string(l)+"_dt_"+to_string(dt)+"_tmax_"+to_string(tmax)+"_npart_"+to_string(npart)+".txt";
	cFile = datafolder+"cfile_a_"+to_string(a)+"_l_"+to_string(l)+"_dt_"+to_string(dt)+"_tmax_"+to_string(tmax)+"_npart_"+to_string(npart)+".txt";
	sigmaFile = datafolder+"sigmafile_a_"+to_string(a)+"_l_"+to_string(l)+"_dt_"+to_string(dt)+"_tmax_"+to_string(tmax)+"_npart_"+to_string(npart)+".txt";
	
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
		x[i] = distx(rng);
		rand = dist(rng);
		c[i] = initc(rand);
		rand = dist(rng);
		sigma[i] = initsigma(rand);
		epsilon[i] = 1.01*c[i]*dt;
	}
	
	/* simulation */
	for (double t=0 ; t<=tmax ; t+=dt){
		/* simulation for first particle */
		rand = dist(rng);
		sigma[0] = sigma[0]*fliptest(a,dt,rand);
		movefunc(x[0],c[0],sigma[0],l,dt,epsilon[0]);

		/* writing the data out for first particle*/
		writefunc0(xFile,x[0],cFile,c[0],sigmaFile,sigma[0]);
		
		/* simulation for all particles */
		for (int part=1; part < npart-1; part++){
			rand = dist(rng);
			sigma[part] = sigma[part]*fliptest(a,dt,rand);
			movefunc(x[part],c[part],sigma[part],l,dt,epsilon[part]);
		
			/* writing the data out*/
			writefunc(xFile,x[part],cFile,c[part],sigmaFile,sigma[part]);
		}
		/* simulation for last particle */
		rand = dist(rng);
		sigma[npart-1] = sigma[npart-1]*fliptest(a,dt,rand);
		movefunc(x[npart-1],c[npart-1],sigma[npart-1],l,dt,epsilon[npart-1]);

		/* writing the data out for last particle*/
		writefunc_end(xFile,x[npart-1],cFile,c[npart-1],sigmaFile,sigma[npart-1]);
	}

}
