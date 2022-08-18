import json

import numpy as np
import time
import matplotlib.pyplot as plt
import imageio.v2 as imageio

temper = []
flow = []
press = []
humid = []
disp = []
setinterval = [22, 77]  ###################################
pic = []


def plott(temper, name, SetInterval=[29, 31]):  #################change
    plt.cla()
    plt.ylim(SetInterval[0] - 3, SetInterval[1] + 3)
    plt.ion()
    plt.plot(temper)
    plt.axhline(float(sum(temper) / len(temper)), label=f'mean: {round(sum(temper) / len(temper), 4)}', color='g')
    plt.axhline(SetInterval[0], linestyle='--', color='r', label='interval')
    plt.axhline(SetInterval[1], linestyle='--', color='r')
    minn = np.argmin(temper)
    plt.annotate('[' + str(minn) + ', ' + str(round(temper[minn], 4)) + ']', xy=(minn, temper[minn]),
                 xytext=(minn, temper[minn]))
    maxx = np.argmax(temper)
    plt.annotate('[' + str(maxx) + ', ' + str(round(temper[maxx], 4)) + ']', xy=(maxx, temper[maxx]),
                 xytext=(maxx, temper[maxx]))
    red = [(j, i) for j, i in enumerate(temper) if i < SetInterval[0] or i > SetInterval[1]]
    for i, j in red:
        plt.plot(i, j, color='r', marker='o')
        plt.annotate('[' + str(i) + ', ' + str(round(j, 4)) + ']', xy=(i, j), xytext=(i, j))
    plt.plot(minn, temper[minn], 'ko')
    plt.plot(maxx, temper[maxx], 'ko')
    plt.xlabel('Time')
    plt.ylabel(name)
    plt.legend()
    plt.pause(0.1)
    plt.show()
    plt.savefig(r'./{name:}.png'.format(name=name))
    ##########################################################################

    pic.append(imageio.imread(r'./{name:}.png'.format(name=name)))


count = 20
while count >= 1:
    count = count - 1
    with open(r"../DataGenerator/data.json", 'r') as f:
        data = json.load(f)
    time.sleep(1)
    try:
        temper.append(data['Temperature'])
        flow.append(data['FlowRate'])
        press.append(data['Pressure'])
        humid.append(data['Humidity'])
        disp.append(data['Displacement'])
    except:
        pass
    plott(temper, 'Temperature')

imageio.mimsave("p3.gif", pic, fps=5)
