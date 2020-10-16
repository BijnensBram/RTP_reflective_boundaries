import numpy as np
import matplotlib.pyplot as plt

xdata = np.loadtxt("./data/2c_1_2_no_match_5.txt",delimiter=";")
xdata2 = np.loadtxt("./data/2c_1_2_match_2.txt",delimiter=";")
# cdata = np.loadtxt("./data/cfile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_10000.txt",delimiter=";")
# sigmadata = np.loadtxt("./data/sigmafile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_10000.txt",delimiter=";")


for i in np.linspace(0,len(xdata[:,0]),301):
    plt.hist(xdata[int(i),:],bins=200,alpha=0.5,label=r"$c_1 = 1,\, c_2 = \pi$")
    plt.hist(xdata2[int(i),:],bins=200,alpha=0.5,label=r"$c_1 = 1,\, c_2 = 2$")
    plt.ylim([0,1600])
    plt.xlim([0,2])
    plt.legend(frameon=False)
    plt.savefig("./fig/frame"+str(int(i))+".png",dpi=190)
    plt.close()
