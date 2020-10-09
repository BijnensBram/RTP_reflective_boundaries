#ifndef MOVE_H
#define MOVE_H

/* function to move the particles */
void movefunc(double &x,double c,double &sigma, double l, double dt, double epsilon);

/* function to initialise c out of two options */
double initc_2opt(double rand);

/* function to initialise c out of five options */
double initc_5opt(double rand);

#endif //FUNCTIONS
