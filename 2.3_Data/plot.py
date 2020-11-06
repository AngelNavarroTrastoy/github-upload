import pandas as pd
data = pd.read_csv('LINADV_data_320.txt', sep='\s+', header = None)
data = pd.DataFrame(data)

import matplotlib.pyplot as plt
x = data[0]
y = data[1]
z = data[2]
w = data[3]

data1 = pd.read_csv('LINADV_data_640.txt', sep='\s+', header = None)
data1 = pd.DataFrame(data1)

x1 = data1[0]
y1 = data1[1]
z1 = data1[2]

data2 = pd.read_csv('LINADV_data_960.txt', sep='\s+', header = None)
data2 = pd.DataFrame(data2)

x2 = data2[0]
y2 = data2[1]
z2 = data2[2]

data3 = pd.read_csv('LINADV_data_1280.txt', sep='\s+', header = None)
data3 = pd.DataFrame(data3)

x3 = data3[0]
y3 = data3[1]
z3 = data3[2]

data4 = pd.read_csv('LINADV_data_1600.txt', sep='\s+', header = None)
data4 = pd.DataFrame(data4)

x4 = data4[0]
y4 = data4[1]
z4 = data4[2]

data5 = pd.read_csv('LINADV_data_1920.txt', sep='\s+', header = None)
data5 = pd.DataFrame(data5)

x5 = data5[0]
y5 = data5[1]
z5 = data5[2]

data6 = pd.read_csv('LINADV_data_2240.txt', sep='\s+', header = None)
data6 = pd.DataFrame(data6)

x6 = data6[0]
y6 = data6[1]
z6 = data6[2]

data7 = pd.read_csv('LINADV_data_2560.txt', sep='\s+', header = None)
data7 = pd.DataFrame(data7)

x7 = data7[0]
y7 = data7[1]
z7 = data7[2]

data8 = pd.read_csv('LINADV_data_2880.txt', sep='\s+', header = None)
data8 = pd.DataFrame(data8)

x8 = data8[0]
y8 = data8[1]
z8 = data8[2]


plt.plot(x,y,'k',label="Initial State")
plt.plot(x,z,'r',label="TS = 320")
#plt.plot(x1,z1,'g',label="TS = 640")
#plt.plot(x2,z2,'c',label="TS = 960")
#plt.plot(x3,z3,'m',label="TS = 1280")
#plt.plot(x4,z4,'y',label="TS = 1600")
#plt.plot(x5,z5,'b',label="TS = 1920")
#plt.plot(x6,z6,'tab:orange',label="TS = 2240")
#plt.plot(x7,z7,'tab:grey',label="TS = 2560")
#plt.plot(x8,z8,'tab:brown',label="TS = 2880")
#plt.plot(x,w, 'g', label = "Initial Height Tendency")
plt.xlabel('1/1000 (m)')
plt.ylabel('Heigth')
plt.legend()
plt.show()


