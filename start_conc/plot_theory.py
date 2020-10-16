import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

xdata = np.loadtxt("./data/1c_pix_l_1.txt",delimiter=";")
# cdata = np.loadtxt("./data/cfile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_10000.txt",delimiter=";")
# sigmadata = np.loadtxt("./data/sigmafile_a_0.100000_l_2.000000_dt_0.005000_tmax_50.000000_npart_10000.txt",delimiter=";")

N = 100000
l = 2
dt = 0.05
x = np.linspace(0,l,1000)
c = 1

blue_patch = mpatches.Patch(color='tab:blue', label=r'$\rho_{sim}$')
orange = mpatches.Patch(color='tab:orange', linestyle="-",label=r'$\rho_{exact}$')
def theory(t,x):
    return N/250*(1-np.cos(2*np.pi*x/l)*np.cos(2*np.pi/l*c*t))

for i in np.linspace(0,len(xdata[:,0]),301):
    t = int(i)*dt
    plt.hist(xdata[int(i),:],bins=250)
    plt.plot(x,theory(t,x))
    plt.ylim([0,1600])
    plt.xlim([0,2])
    plt.legend(handles=[blue_patch,orange],frameon=False)
    plt.savefig("./fig/frame"+str(int(i))+".png",dpi=190)
    plt.close()
