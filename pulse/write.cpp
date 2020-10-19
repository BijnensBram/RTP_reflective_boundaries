#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include "write.h"


using namespace std;

/* function to write data out */
/* void writefunc(std::string xfilename, double xdata, std::string cfilename, double cdata, std::string sigmafilename, double sigmadata){ */
void writefunc(std::string xfilename, double xdata){
	/* write x data */
	ofstream xFile;
	xFile.open(xfilename.c_str(),ios_base::app);
	xFile << ";" << xdata;
	xFile.close();
	
	/* /1* write c data *1/ */
	/* ofstream cFile; */
	/* cFile.open(cfilename.c_str(),ios_base::app); */
	/* cFile << ";" << cdata; */
	/* cFile.close(); */
	
	/* /1* write sigma data *1/ */
	/* ofstream sigmaFile; */
	/* sigmaFile.open(sigmafilename.c_str(),ios_base::app); */
	/* sigmaFile << ";" << sigmadata; */
	/* sigmaFile.close(); */
}

/* void writefunc0(std::string xfilename, double xdata, std::string cfilename, double cdata, std::string sigmafilename, double sigmadata){ */
void writefunc0(std::string xfilename, double xdata){
/* function to write out the first element */
	/* write x data */
	ofstream xFile;
	xFile.open(xfilename.c_str(),ios_base::app);
	xFile << xdata;
	xFile.close();
	
	/* /1* write c data *1/ */
	/* ofstream cFile; */
	/* cFile.open(cfilename.c_str(),ios_base::app); */
	/* cFile << cdata; */
	/* cFile.close(); */
	
	/* /1* write sigma data *1/ */
	/* ofstream sigmaFile; */
	/* sigmaFile.open(sigmafilename.c_str(),ios_base::app); */
	/* sigmaFile << sigmadata; */
	/* sigmaFile.close(); */
}

/* void writefunc_end(std::string xfilename, double xdata, std::string cfilename, double cdata, std::string sigmafilename, double sigmadata){ */
void writefunc_end(std::string xfilename, double xdata){
/* function to write out the first element */
	/* write x data */
	ofstream xFile;
	xFile.open(xfilename.c_str(),ios_base::app);
	xFile << ";" << xdata << endl;
	xFile.close();
	
	/* /1* write c data *1/ */
	/* ofstream cFile; */
	/* cFile.open(cfilename.c_str(),ios_base::app); */
	/* cFile << ";" << cdata << endl; */
	/* cFile.close(); */
	
	/* /1* write sigma data *1/ */
	/* ofstream sigmaFile; */
	/* sigmaFile.open(sigmafilename.c_str(),ios_base::app); */
	/* sigmaFile << ";" << sigmadata << endl; */
	/* sigmaFile.close(); */
}
