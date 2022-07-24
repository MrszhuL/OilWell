import json
import random
import time

class Gene:
    def __init__(self):
        self.data = dict()
        self.data['Temperature'] = 30 #####realTemperature
        self.data['Displacement'] = 44##############fake below
        self.data['Humidity'] = 33
        self.data['Pressure'] = 66
        self.data['FlowRate'] = 55
        
    def TempException(self,excep=False):
        if excep==False:
            return
        self.data['Temperature']=self.data['Temperature']+random.normalvariate(0,0.6)
    
    def DisException(self,excep=False):
        if excep==False:
            return
        self.data['Displacement']=self.data['Displacement']+random.normalvariate(0,0.6)

    def HumException(self,excep=False):
        if excep==False:
            return
        self.data['Humidity']=self.data['Humidity']+random.normalvariate(0,0.6)
    
    def PressException(self,excep=False):
        if excep==False:
            return
        self.data['Pressure']=self.data['Pressure']+random.normalvariate(0,0.6)
    
    def FlowException(self,excep=False):
        if excep==False:
            return
        self.data['FlowRate']=self.data['FlowRate']+random.normalvariate(0,0.6)
    

    def __del__(self):
        with open(r"./DataGenerator/data.json", 'w') as f:
            json.dump(self.data, f)



while 1:
    ok=Gene()
    ok.TempException(random.randint(1,14)%3==1)
    ok.DisException(random.randint(1,14)%3==1)
    ok.FlowException(random.randint(1,14)%3==1)
    ok.HumException(random.randint(1,14)%3==1)
    ok.PressException(random.randint(1,14)%3==1)
    time.sleep(1)
