import numpy as np
import matplotlib.pyplot as plt

xdata = np.loadtxt("./data2/xfile_a_0.200000_l_2.000000_dt_0.010000_tmax_5.000000_npart_100000.txt",delimiter=";")
# cdata = np.loadtxt("./data/cfile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_10000.txt",delimiter=";")
# sigmadata = np.loadtxt("./data/sigmafile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_10000.txt",delimiter=";")


for i in range(0,int(len(xdata[:,0]))):
    plt.hist(xdata[i,:],bins=200)
    plt.ylim([0,1600])
    plt.xlim([0,2])
    plt.savefig("./fig/frame"+str(i)+".png",dpi=190)
    plt.close()
