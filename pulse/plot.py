#!/bin/python3.8
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

xdata = np.loadtxt("./data/pulse_match_f_9.txt",delimiter=";")
# cdata = np.loadtxt("./data/cfile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_10000.txt",delimiter=";")
# sigmadata = np.loadtxt("./data/sigmafile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_10000.txt",delimiter=";")

l = 2
a = 50

def flip(x):
    return a*(np.exp(-500*(x-l*0.25)*(x-l*0.25))+np.exp(-500*(x-l*0.75)*(x-l*0.75)))

x = np.linspace(0,l,1000)

blue_patch = mpatches.Patch(color='tab:blue', label=r'$\rho$')
black_patch = mpatches.Patch(color='black', linestyle="-",label=r'$a(x)$')

for i in np.linspace(0,int(len(xdata[:,0])),501):
    plt.hist(xdata[int(i),:],bins=200,label=r"$\rho$")
    plt.ylabel("Counts")
    plt.xlabel("Position")
    plt.ylim([0,1600])
    plt.xlim([0,2])
    plt.savefig("./fig2/frame"+str(int(i))+".png",dpi=96)
    # plt.show()
    plt.close()
