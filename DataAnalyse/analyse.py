import json

import numpy as np
import time
import matplotlib.pyplot as plt

temper = []
flow = []
press = []
humid = []
disp = []
setinterval = [22, 77]  ###################################


def plott(temper, name):
    plt.cla()
    plt.ion()
    plt.plot(temper)
    plt.axhline(float(sum(temper) / len(temper)), label='mean', color='g')
    minn = np.argmin(temper)
    plt.annotate('[' + str(minn) + ', ' + str(temper[minn]) + ']', xy=(minn, temper[minn]), xytext=(minn, temper[minn]))
    maxx = np.argmax(temper)
    plt.annotate('[' + str(maxx) + ', ' + str(temper[maxx]) + ']', xy=(maxx, temper[maxx]), xytext=(maxx, temper[maxx]))
    plt.text(0, float(sum(temper) / len(temper)), f'{round(sum(temper) / len(temper), 4)}(mean)')
    red = [(j, i) for j, i in enumerate(temper) if i < setinterval[0] or i > setinterval[1]]
    for i, j in red:
        plt.plot(i, j, color='r', marker='o')
    plt.plot(minn, temper[minn], 'ko')
    plt.plot(maxx, temper[maxx], 'ko')
    plt.xlabel('Time')
    plt.ylabel(name)
    plt.pause(0.1)
    plt.show()
    plt.savefig(r'./{name:}.png'.format(name=name))


while 1:
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
