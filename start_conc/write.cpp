#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include "write.h"


using namespace std;

/* function to write data out */
void writefunc(std::string xfilename, double xdata){
	/* write x data */
	ofstream xFile;
	xFile.open(xfilename.c_str(),ios_base::app);
	xFile << ";" << xdata;
	xFile.close();
}

void writefunc0(std::string xfilename, double xdata){
/* function to write out the first element */
	/* write x data */
	ofstream xFile;
	xFile.open(xfilename.c_str(),ios_base::app);
	xFile << xdata;
	xFile.close();
}

void writefunc_end(std::string xfilename, double xdata){
/* function to write out the first element */
	/* write x data */
	ofstream xFile;
	xFile.open(xfilename.c_str(),ios_base::app);
	xFile << ";" << xdata << endl;
	xFile.close();
}
