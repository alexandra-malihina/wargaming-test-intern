class arrayFIFO(object):
    def __init__(self, size): #Конструктор
        self.currentSize=0
        self.maxSize=size
        self.fifo=[]        
        pass
    
    def add(self,value): #метод длядобавления нового элемента
        if self.currentSize<self.maxSize:
            self.fifo.append(value)
            self.currentSize+=1
        else:
            print('FIFO is full')
            
    def remove(self): #метод удаления элемента
        if self.currentSize>0:
            self.fifo.pop(0)
            self.currentSize-=1
        else:
            print("FIFO is empty")
            
    def show(self):# метод вывода FIFO
        for i in range(self.currentSize):
            print (str(self.fifo[i]),end=' ')
        print()

fifo=arrayFIFO(10)
for i in range(15):
    fifo.add(i)
    fifo.show()
for i in range(15):
    fifo.remove()
    fifo.show() 
