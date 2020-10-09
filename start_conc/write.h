#ifndef WRITE_H
#define WRITE_H

#include <iostream>

/* function to write data out */
void writefunc(std::string xfilename, double xdata, std::string cfilename, double cdata, std::string sigmafilename, double sigmadata);

/* function to write out the first element */
void writefunc0(std::string xfilename, double xdata, std::string cfilename, double cdata, std::string sigmafilename, double sigmadata);

/* function to write out the last element */
void writefunc_end(std::string xfilename, double xdata, std::string cfilename, double cdata, std::string sigmafilename, double sigmadata);
#endif //FUNCTIONS
