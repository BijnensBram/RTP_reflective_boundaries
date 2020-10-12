#ifndef FLIP_H
#define FLIP_H

/* function to initialise sigma */
double initsigma(double rand);

/* function to check of spin flips */
double fliptest(double a, double dt, double rand);

/* function to check of spin flips using a peaked a profile*/
double fliptest_a_peaks(double x, double a, double l, double dt, double rand);

/* function to create a profile */
double a_profile_peaks(double x, double a, double l);

#endif //FUNCTIONS
