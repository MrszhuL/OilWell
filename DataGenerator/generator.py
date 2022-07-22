import json
import random
import time


class Gene:
    def __init__(self):
        data = dict()
        data['Temperature'] = random.randint(1, 100)
        data['Displacement'] = random.randint(1, 100)
        data['Humidity'] = random.randint(1, 100)
        data['Pressure'] = random.randint(1, 100)
        data['FlowRate'] = random.randint(1, 100)
        with open(r"./DataGenerator/data.json", 'w') as f:
            json.dump(data, f)


while 1:
    Gene()
    time.sleep(1)
