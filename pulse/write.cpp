#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include "write.h"


using namespace std;

/* function to write data out */
void writefunc(std::string xfilename, double xdata, std::string cfilename, double cdata, std::string sigmafilename, double sigmadata){
	/* write x data */
	ofstream xFile;
	xFile.open(xfilename.c_str(),ios_base::app);
	xFile << ";" << xdata;
	xFile.close();
	
	/* write c data */
	ofstream cFile;
	cFile.open(cfilename.c_str(),ios_base::app);
	cFile << ";" << cdata;
	cFile.close();
	
	/* write sigma data */
	ofstream sigmaFile;
	sigmaFile.open(sigmafilename.c_str(),ios_base::app);
	sigmaFile << ";" << sigmadata;
	sigmaFile.close();
}

void writefunc0(std::string xfilename, double xdata, std::string cfilename, double cdata, std::string sigmafilename, double sigmadata){
/* function to write out the first element */
	/* write x data */
	ofstream xFile;
	xFile.open(xfilename.c_str(),ios_base::app);
	xFile << xdata;
	xFile.close();
	
	/* write c data */
	ofstream cFile;
	cFile.open(cfilename.c_str(),ios_base::app);
	cFile << cdata;
	cFile.close();
	
	/* write sigma data */
	ofstream sigmaFile;
	sigmaFile.open(sigmafilename.c_str(),ios_base::app);
	sigmaFile << sigmadata;
	sigmaFile.close();
}

void writefunc_end(std::string xfilename, double xdata, std::string cfilename, double cdata, std::string sigmafilename, double sigmadata){
/* function to write out the first element */
	/* write x data */
	ofstream xFile;
	xFile.open(xfilename.c_str(),ios_base::app);
	xFile << ";" << xdata << endl;
	xFile.close();
	
	/* write c data */
	ofstream cFile;
	cFile.open(cfilename.c_str(),ios_base::app);
	cFile << ";" << cdata << endl;
	cFile.close();
	
	/* write sigma data */
	ofstream sigmaFile;
	sigmaFile.open(sigmafilename.c_str(),ios_base::app);
	sigmaFile << ";" << sigmadata << endl;
	sigmaFile.close();
}
