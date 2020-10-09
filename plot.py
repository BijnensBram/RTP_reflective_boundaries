import numpy as np
import matplotlib.pyplot as plt

xdata = np.loadtxt("./data/xfile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_1000.txt",delimiter=";")
cdata = np.loadtxt("./data/cfile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_1000.txt",delimiter=";")
sigmadata = np.loadtxt("./data/sigmafile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_1000.txt",delimiter=";")


for i in range(0,len(xdata[:,0])):
    counts, bins, bars=plt.hist(xdata[i,:],bins=100)
    plt.show()
