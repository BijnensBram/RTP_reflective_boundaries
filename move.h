#ifndef MOVE_H
#define MOVE_H

/* function to move the particles */
void movefunc(double &x,double c,double &sigma, double l, double dt, double epsilon);

/* function to initialise c */
double initc(double rand);

#endif //FUNCTIONS
