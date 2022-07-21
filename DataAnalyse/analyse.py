import copy
import json
import time
import matplotlib.pyplot  as plt

temper = []
flow = []
press = []
humid = []
disp = []

while 1:
    with open('../DataGenerator/data.json', 'r') as f:
        data = json.load(f)
    time.sleep(1)
    temper.append(data['Temperature'])
    flow.append(data['FlowRate'])
    press.append(data['Pressure'])
    humid.append(data['Humidity'])
    disp.append(data['Displacement'])
    plt.clf()

