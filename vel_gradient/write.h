#ifndef WRITE_H
#define WRITE_H

#include <iostream>

/* writting metadata */
void metadatawrite(std::string xfilename, double data);

/* function to write data out */
void writefunc(std::string xfilename, double xdata);

/* function to write out the first element */
void writefunc0(std::string xfilename, double xdata);

/* function to write out the last element */
void writefunc_end(std::string xfilename, double xdata);
#endif //FUNCTIONS
